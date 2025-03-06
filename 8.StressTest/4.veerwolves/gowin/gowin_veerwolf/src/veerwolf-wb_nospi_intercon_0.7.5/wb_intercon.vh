wire [31:0] wb_io_adr;
wire [31:0] wb_io_dat;
wire  [3:0] wb_io_sel;
wire        wb_io_we;
wire        wb_io_cyc;
wire        wb_io_stb;
wire  [2:0] wb_io_cti;
wire  [1:0] wb_io_bte;
wire [31:0] wb_io_rdt;
wire        wb_io_ack;
wire        wb_io_err;
wire        wb_io_rty;
wire [31:0] wb_rom_adr;
wire [31:0] wb_rom_dat;
wire  [3:0] wb_rom_sel;
wire        wb_rom_we;
wire        wb_rom_cyc;
wire        wb_rom_stb;
wire  [2:0] wb_rom_cti;
wire  [1:0] wb_rom_bte;
wire [31:0] wb_rom_rdt;
wire        wb_rom_ack;
wire        wb_rom_err;
wire        wb_rom_rty;
wire [31:0] wb_sys_adr;
wire [31:0] wb_sys_dat;
wire  [3:0] wb_sys_sel;
wire        wb_sys_we;
wire        wb_sys_cyc;
wire        wb_sys_stb;
wire  [2:0] wb_sys_cti;
wire  [1:0] wb_sys_bte;
wire [31:0] wb_sys_rdt;
wire        wb_sys_ack;
wire        wb_sys_err;
wire        wb_sys_rty;
wire [31:0] wb_uart_adr;
wire [31:0] wb_uart_dat;
wire  [3:0] wb_uart_sel;
wire        wb_uart_we;
wire        wb_uart_cyc;
wire        wb_uart_stb;
wire  [2:0] wb_uart_cti;
wire  [1:0] wb_uart_bte;
wire [31:0] wb_uart_rdt;
wire        wb_uart_ack;
wire        wb_uart_err;
wire        wb_uart_rty;

wb_intercon wb_intercon0
   (.wb_clk_i      (wb_clk),
    .wb_rst_i      (wb_rst),
    .wb_io_adr_i   (wb_io_adr),
    .wb_io_dat_i   (wb_io_dat),
    .wb_io_sel_i   (wb_io_sel),
    .wb_io_we_i    (wb_io_we),
    .wb_io_cyc_i   (wb_io_cyc),
    .wb_io_stb_i   (wb_io_stb),
    .wb_io_cti_i   (wb_io_cti),
    .wb_io_bte_i   (wb_io_bte),
    .wb_io_rdt_o   (wb_io_rdt),
    .wb_io_ack_o   (wb_io_ack),
    .wb_io_err_o   (wb_io_err),
    .wb_io_rty_o   (wb_io_rty),
    .wb_rom_adr_o  (wb_rom_adr),
    .wb_rom_dat_o  (wb_rom_dat),
    .wb_rom_sel_o  (wb_rom_sel),
    .wb_rom_we_o   (wb_rom_we),
    .wb_rom_cyc_o  (wb_rom_cyc),
    .wb_rom_stb_o  (wb_rom_stb),
    .wb_rom_cti_o  (wb_rom_cti),
    .wb_rom_bte_o  (wb_rom_bte),
    .wb_rom_rdt_i  (wb_rom_rdt),
    .wb_rom_ack_i  (wb_rom_ack),
    .wb_rom_err_i  (wb_rom_err),
    .wb_rom_rty_i  (wb_rom_rty),
    .wb_sys_adr_o  (wb_sys_adr),
    .wb_sys_dat_o  (wb_sys_dat),
    .wb_sys_sel_o  (wb_sys_sel),
    .wb_sys_we_o   (wb_sys_we),
    .wb_sys_cyc_o  (wb_sys_cyc),
    .wb_sys_stb_o  (wb_sys_stb),
    .wb_sys_cti_o  (wb_sys_cti),
    .wb_sys_bte_o  (wb_sys_bte),
    .wb_sys_rdt_i  (wb_sys_rdt),
    .wb_sys_ack_i  (wb_sys_ack),
    .wb_sys_err_i  (wb_sys_err),
    .wb_sys_rty_i  (wb_sys_rty),
    .wb_uart_adr_o (wb_uart_adr),
    .wb_uart_dat_o (wb_uart_dat),
    .wb_uart_sel_o (wb_uart_sel),
    .wb_uart_we_o  (wb_uart_we),
    .wb_uart_cyc_o (wb_uart_cyc),
    .wb_uart_stb_o (wb_uart_stb),
    .wb_uart_cti_o (wb_uart_cti),
    .wb_uart_bte_o (wb_uart_bte),
    .wb_uart_rdt_i (wb_uart_rdt),
    .wb_uart_ack_i (wb_uart_ack),
    .wb_uart_err_i (wb_uart_err),
    .wb_uart_rty_i (wb_uart_rty));

