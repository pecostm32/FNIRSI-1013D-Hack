//----------------------------------------------------------------------------------------------------------------------------------

#ifndef F1C100S_STRUCTS_H
#define F1C100S_STRUCTS_H

//----------------------------------------------------------------------------------------------------------------------------------

typedef struct tagF1C100S_PERIPH_STATUS    F1C100S_PERIPH_STATUS;

typedef struct tagF1C100S_CCU              F1C100S_CCU;
typedef struct tagF1C100S_DRAMC            F1C100S_DRAMC;
typedef struct tagF1C100S_SPI              F1C100S_SPI;
typedef struct tagF1C100S_PIO_PORT         F1C100S_PIO_PORT;
typedef struct tagF1C100S_PIO_INT          F1C100S_PIO_INT;
typedef struct tagF1C100S_PIO_DDR          F1C100S_PIO_DDR;
typedef struct tagF1C100S_TCON             F1C100S_TCON;
typedef struct tagF1C100S_DEBE             F1C100S_DEBE;

//----------------------------------------------------------------------------------------------------------------------------------
// Not a F1C100s peripheral but for simplicity implemented here for now
typedef struct tagFLASH_MEMORY             FLASH_MEMORY;

//----------------------------------------------------------------------------------------------------------------------------------

typedef union tagF1C100S_MEMORY      F1C100S_MEMORY;

//----------------------------------------------------------------------------------------------------------------------------------

union tagF1C100S_MEMORY
{
  u_int32_t m_32bit;
  u_int16_t m_16bit[2];
  u_int8_t  m_8bit[4];
};

//----------------------------------------------------------------------------------------------------------------------------------
//Data for flash memory handling
struct tagFLASH_MEMORY
{
  u_int32_t commandstate;
  u_int32_t mode;
  u_int32_t readaddress;
};

//----------------------------------------------------------------------------------------------------------------------------------
//Peripheral reset status info
struct tagF1C100S_PERIPH_STATUS
{
  u_int32_t spi0_reset;
  u_int32_t spi1_reset;
};

//----------------------------------------------------------------------------------------------------------------------------------
//The clock control register set
struct tagF1C100S_CCU
{
  F1C100S_MEMORY pll_cpu_ctrl;
  F1C100S_MEMORY pll_audio_ctrl;
  F1C100S_MEMORY pll_video_ctrl;
  F1C100S_MEMORY pll_ve_ctrl;
  F1C100S_MEMORY pll_ddr_ctrl;
  F1C100S_MEMORY pll_periph_ctrl;
  F1C100S_MEMORY cpu_clk_src;
  F1C100S_MEMORY ahb_apb_cfg;
  F1C100S_MEMORY bus_clk_gate0;
  F1C100S_MEMORY bus_clk_gate1;
  F1C100S_MEMORY bus_clk_gate2;
  F1C100S_MEMORY sdmmc0_clk;
  F1C100S_MEMORY sdmmc1_clk;
  F1C100S_MEMORY daudio_clk;
  F1C100S_MEMORY spdif_clk;
  F1C100S_MEMORY i2s_clk;
  F1C100S_MEMORY usbphy_cfg;
  F1C100S_MEMORY dram_clk_gate;
  F1C100S_MEMORY debe_clk;
  F1C100S_MEMORY defe_clk;
  F1C100S_MEMORY lcd_clk;
  F1C100S_MEMORY deinterlace_clk;
  F1C100S_MEMORY tve_clk;
  F1C100S_MEMORY tvd_clk;
  F1C100S_MEMORY csi_clk;
  F1C100S_MEMORY ve_clk;
  F1C100S_MEMORY adda_clk;
  F1C100S_MEMORY avs_clk;
  F1C100S_MEMORY pll_stable_time0;
  F1C100S_MEMORY pll_stable_time1;
  F1C100S_MEMORY pll_cpu_bias;
  F1C100S_MEMORY pll_audio_bias;
  F1C100S_MEMORY pll_video_bias;
  F1C100S_MEMORY pll_ve_bias;
  F1C100S_MEMORY pll_ddr0_bias;
  F1C100S_MEMORY pll_periph_bias;
  F1C100S_MEMORY pll_cpu_tun;
  F1C100S_MEMORY pll_ddr_tun;
  F1C100S_MEMORY pll_audio_pat;
  F1C100S_MEMORY pll_video_pat;
  F1C100S_MEMORY pll_ddr0_pat;
  F1C100S_MEMORY bus_soft_rst0;
  F1C100S_MEMORY bus_soft_rst1;
  F1C100S_MEMORY bus_soft_rst2;
};

//----------------------------------------------------------------------------------------------------------------------------------
//The dram controller register set
struct tagF1C100S_DRAMC
{
  F1C100S_MEMORY sconr;
  F1C100S_MEMORY stmg0r;
  F1C100S_MEMORY stmg1r;
  F1C100S_MEMORY sctlr;
  F1C100S_MEMORY srefr;
  F1C100S_MEMORY sextmr;
  F1C100S_MEMORY ddlyr;
  F1C100S_MEMORY dadrr;
  F1C100S_MEMORY dvalr;
  F1C100S_MEMORY drptr0;
  F1C100S_MEMORY drptr1;
  F1C100S_MEMORY drptr2;
  F1C100S_MEMORY drptr3;
  F1C100S_MEMORY sefr;
  F1C100S_MEMORY mae;
  F1C100S_MEMORY aspr;
  F1C100S_MEMORY sdly0;
  F1C100S_MEMORY sdly1;
  F1C100S_MEMORY sdly2;
  F1C100S_MEMORY mcr0;
  F1C100S_MEMORY mcr1;
  F1C100S_MEMORY mcr2;
  F1C100S_MEMORY mcr3;
  F1C100S_MEMORY mcr4;
  F1C100S_MEMORY mcr5;
  F1C100S_MEMORY mcr6;
  F1C100S_MEMORY mcr7;
  F1C100S_MEMORY mcr8;
  F1C100S_MEMORY mcr9;
  F1C100S_MEMORY mcr10;
  F1C100S_MEMORY mcr11;
  F1C100S_MEMORY bwcr;
};

//----------------------------------------------------------------------------------------------------------------------------------
//The SPI controller register set
struct tagF1C100S_SPI
{
  F1C100S_MEMORY gcr;
  F1C100S_MEMORY tcr;
  F1C100S_MEMORY ier;
  F1C100S_MEMORY isr;
  F1C100S_MEMORY fcr;
  F1C100S_MEMORY fsr;
  F1C100S_MEMORY wcr;
  F1C100S_MEMORY ccr;
  F1C100S_MEMORY mbc;
  F1C100S_MEMORY mtc;
  F1C100S_MEMORY bcc;
  F1C100S_MEMORY txd;
  F1C100S_MEMORY rxd;
  
  //Not directly addressable are the two fifo's each spi interface has
  u_int8_t txfifo[64];
  u_int8_t rxfifo[64];
};

//----------------------------------------------------------------------------------------------------------------------------------
//The PIO registers
struct tagF1C100S_PIO_PORT
{
  F1C100S_MEMORY cfg0;
  F1C100S_MEMORY cfg1;
  F1C100S_MEMORY cfg2;
  F1C100S_MEMORY cfg3;
  F1C100S_MEMORY data;
  F1C100S_MEMORY drv0;
  F1C100S_MEMORY drv1;
  F1C100S_MEMORY pul0;
  F1C100S_MEMORY pul1;
};

struct tagF1C100S_PIO_INT
{
  F1C100S_MEMORY cfg0;
  F1C100S_MEMORY cfg1;
  F1C100S_MEMORY cfg2;
  F1C100S_MEMORY cfg3;
  F1C100S_MEMORY ctrl;
  F1C100S_MEMORY sta;
  F1C100S_MEMORY deb;
};

struct tagF1C100S_PIO_DDR
{
  F1C100S_MEMORY paddrv;
  F1C100S_MEMORY padpul;
};

//----------------------------------------------------------------------------------------------------------------------------------
//LCD timing control registers
struct tagF1C100S_TCON
{
  F1C100S_MEMORY ctrl;
  F1C100S_MEMORY int0;
  F1C100S_MEMORY int1;
  F1C100S_MEMORY frm_ctrl;
  F1C100S_MEMORY frm_seed0_r;
  F1C100S_MEMORY frm_seed0_g;
  F1C100S_MEMORY frm_seed0_b;
  F1C100S_MEMORY frm_seed1_r;
  F1C100S_MEMORY frm_seed1_g;
  F1C100S_MEMORY frm_seed1_b;
  F1C100S_MEMORY frm_tbl0;
  F1C100S_MEMORY frm_tbl1;
  F1C100S_MEMORY frm_tbl2;
  F1C100S_MEMORY frm_tbl3;
  F1C100S_MEMORY clk_ctrl;
  F1C100S_MEMORY debug_info;
  F1C100S_MEMORY tcon0_ctrl;
  F1C100S_MEMORY tcon0_basic_timing0;
  F1C100S_MEMORY tcon0_basic_timing1;
  F1C100S_MEMORY tcon0_basic_timing2;
  F1C100S_MEMORY tcon0_basic_timing3;
  F1C100S_MEMORY tcon0_hv_timing;
  F1C100S_MEMORY tcon0_cpu_if;
  F1C100S_MEMORY tcon0_cpu_wr;
  F1C100S_MEMORY tcon0_cpu_rd;
  F1C100S_MEMORY tcon0_cpu_rd_nx;
  F1C100S_MEMORY tcon0_io_ctrl0;
  F1C100S_MEMORY tcon0_io_ctrl1;
  F1C100S_MEMORY tcon1_ctrl;
  F1C100S_MEMORY tcon1_basic_timing0;
  F1C100S_MEMORY tcon1_basic_timing1;
  F1C100S_MEMORY tcon1_basic_timing2;
  F1C100S_MEMORY tcon1_basic_timing3;
  F1C100S_MEMORY tcon1_basic_timing4;
  F1C100S_MEMORY tcon1_basic_timing5;
  F1C100S_MEMORY tcon1_io_ctrl0;
  F1C100S_MEMORY tcon1_io_ctrl1;
};

//----------------------------------------------------------------------------------------------------------------------------------
//Display engine back end registers
struct tagF1C100S_DEBE
{
  F1C100S_MEMORY mode_ctrl;
  F1C100S_MEMORY color_ctrl;
  F1C100S_MEMORY lay_size;
  F1C100S_MEMORY lay0_size;
  F1C100S_MEMORY lay1_size;
  F1C100S_MEMORY lay2_size;
  F1C100S_MEMORY lay3_size;
  F1C100S_MEMORY lay0_codnt;
  F1C100S_MEMORY lay1_codnt;
  F1C100S_MEMORY lay2_codnt;
  F1C100S_MEMORY lay3_codnt;
  F1C100S_MEMORY lay0_linewidth;
  F1C100S_MEMORY lay1_linewidth;
  F1C100S_MEMORY lay2_linewidth;
  F1C100S_MEMORY lay3_linewidth;
  F1C100S_MEMORY lay0_fb_addr1;
  F1C100S_MEMORY lay1_fb_addr1;
  F1C100S_MEMORY lay2_fb_addr1;
  F1C100S_MEMORY lay3_fb_addr1;
  F1C100S_MEMORY lay0_fb_addr2;
  F1C100S_MEMORY lay1_fb_addr2;
  F1C100S_MEMORY lay2_fb_addr2;
  F1C100S_MEMORY lay3_fb_addr2;
  F1C100S_MEMORY regbuff_ctrl;
  F1C100S_MEMORY ck_max;
  F1C100S_MEMORY ck_min;
  F1C100S_MEMORY ck_cfg;
  F1C100S_MEMORY lay0_att_ctrl0;
  F1C100S_MEMORY lay1_att_ctrl0;
  F1C100S_MEMORY lay2_att_ctrl0;
  F1C100S_MEMORY lay3_att_ctrl0;
  F1C100S_MEMORY lay0_att_ctrl1;
  F1C100S_MEMORY lay1_att_ctrl1;
  F1C100S_MEMORY lay2_att_ctrl1;
  F1C100S_MEMORY lay3_att_ctrl1;
  F1C100S_MEMORY hwc_ctrl;
  F1C100S_MEMORY hwcfb_ctrl;
  F1C100S_MEMORY wb_ctrl;
  F1C100S_MEMORY wb_addr;
  F1C100S_MEMORY wb_lw;
  F1C100S_MEMORY iyuv_ch_ctrl;
  F1C100S_MEMORY ch0_yuv_fb_addr;
  F1C100S_MEMORY ch1_yuv_fb_addr;
  F1C100S_MEMORY ch2_yuv_fb_addr;
  F1C100S_MEMORY ch0_yuv_blw;
  F1C100S_MEMORY ch1_yuv_blw;
  F1C100S_MEMORY ch2_yuv_blw;
  F1C100S_MEMORY coef00;
  F1C100S_MEMORY coef01;
  F1C100S_MEMORY coef02;
  F1C100S_MEMORY coef03;
  F1C100S_MEMORY coef10;
  F1C100S_MEMORY coef11;
  F1C100S_MEMORY coef12;
  F1C100S_MEMORY coef13;
  F1C100S_MEMORY coef20;
  F1C100S_MEMORY coef21;
  F1C100S_MEMORY coef22;
  F1C100S_MEMORY coef23;
};

//----------------------------------------------------------------------------------------------------------------------------------

#endif /* F1C100S_STRUCTS_H */

