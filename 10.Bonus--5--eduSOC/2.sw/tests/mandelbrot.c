#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "soc.h"
#include "memtest.h"
#include "uart.h"

const uint32_t mandel_shift = 10;
const uint32_t mandel_mul   = 1 << mandel_shift;
const int32_t xmin         = -2 * mandel_mul; 
const int32_t xmax         =  2 * mandel_mul; 
const int32_t ymin         = -2 * mandel_mul;
const int32_t ymax         =  2 * mandel_mul;
const int32_t dx           =  4 * mandel_mul/30;
const int32_t dy           =  4 * mandel_mul/30;

const int32_t norm_max         =  4 << mandel_shift;


typedef struct {
    int32_t x;
    int32_t y;
} complex_t;

complex_t c_add(complex_t z1, complex_t z2) {
    complex_t res;
    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;
    return res;
}

uint32_t c_norm (complex_t z) {
    return (z.x * z.x >> mandel_shift) + (z.y * z.y >> mandel_shift);
}

complex_t c_mult (complex_t z1, complex_t z2){
    complex_t res;
    res.x = (z1.x * z2.x >> mandel_shift) - (z1.y * z2.y >> mandel_shift);
    res.y = (z1.x * z2.y >> mandel_shift) + (z1.y * z2.x >> mandel_shift);
    return res;
}

void reverse(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Modified function to use an external buffer
void int32_to_string(char* buffer, int32_t value) {
    int i = 0;
    uint32_t abs_value;

    if (value < 0) {
        abs_value = -value;
        buffer[i++] = '-';
    } else {
        abs_value = value;
    }

    do {
        buffer[i++] = (abs_value % 10) + '0';
        abs_value /= 10;
    } while (abs_value != 0);

    buffer[i] = '\0';
    reverse(buffer, (value < 0 ? 1 : 0), i - 1);
}

void main () {
    uart_send ("Computing the mandelbrot set for you now!\n");
    
    int32_t curr_x = xmin;
    int32_t curr_y = ymax;

    
    //looping through screen positions
    while (curr_y > ymin){
        curr_x = xmin;
        while(curr_x < xmax){
            //check convergency

            complex_t curr_z = {0, 0};
            curr_z.x = 0;
            curr_z.y = 0;

            complex_t curr_c;
            curr_c.x = curr_x;
            curr_c.y = curr_y;

            uint32_t count = 0;



            for(; count < 30; count = count + 1){
                curr_z = c_add(c_mult(curr_z, curr_z), curr_c);
                if(c_norm(curr_z) > norm_max){
                    break;
                }
            }
            
            if(count == 30){
                char str_x[12];  // Buffer for curr_x
                char str_y[12];  // Buffer for curr_y
                int32_to_string(str_x, curr_x); //this line makes the bug not the sending
                int32_to_string(str_y, curr_y);
                uart_send (str_x);
                uart_send (str_y);
                uart_send ("\n\r"); 
            }
            

            curr_x = curr_x + dx;
        }
        curr_y = curr_y - dy;
    }    
    
}