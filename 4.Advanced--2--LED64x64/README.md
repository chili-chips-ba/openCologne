# LED64x64 Example

This example runs `24bpp` animated video on a 64x64 LED panel. 

With the whooping `11.8kHz refresh rate`, it's flicker-free. We also run the panel at the `minumum possible blanking time`, thus yielding the `max possible intensity`. This is 100% RTL design -- Microcontrollers and embedded approach would have hard time meeting these specs.

<p align="center" width="100%">
    <img width="80%" src="https://github.com/user-attachments/assets/b4e4109c-ecd3-4ddb-8a8c-a9a2bb70d6a9">
</p>

We recommend using [DUAL PMOD PANEL](https://hr.mouser.com/ProductDetail/1BitSquared/PMOD-DUAL-LED-PANEL-HUB75E?qs=By6Nw2ByBD17d8wmsR3qXQ%3D%3D) to interface with a HUB75E [RGB LED Matrix](https://www.aliexpress.com/item/1005001950053920.html?spm=a2g0o.productlist.main.1.7e9d2OiV2OiVg7&algo_pvid=7d92e052-fed2-436e-9b2f-a6a3415e5e29&algo_exp_id=7d92e052-fed2-436e-9b2f-a6a3415e5e29-0&pdp_npi=4%40dis!EUR!15.03!14.28!!!16.40!15.58!%402103890117248461873115836e076e!12000018198812421!sea!HR!104410995!ACX&curPageLogUid=PzMljgAhNWk5&utparam-url=scene%3Asearch%7Cquery_from%3A) on GateMate EVB. 

Think of this as a mere building block for making larger panels, such as these 😃 
> <img width="513" alt="Sarajevo-light-panels" src="https://github.com/user-attachments/assets/33bc7420-3fe7-450c-9960-e32ef68df5af">

Also posted on [LinkedIn](https://www.linkedin.com/posts/ahmed-imamovic_etfpga-fpga-rtl-activity-7242253055411331073-E36f?utm_source=share&utm_medium=member_desktop)...

#### End of Document
