/* drivers/video/sprdfb/lcd_rm68180_mipi.c
 *
 * Support for rm68180 mipi LCD device
 *
 * Copyright (C) 2010 Spreadtrum
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/arch/sprd_lcd.h>
#include "../sprdfb.h"

#define printk printf

//#define  LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printk
#else
#define LCD_PRINT(...)
#endif

#define MAX_DATA   58

typedef struct LCM_Init_Code_tag {
	unsigned int tag;
	unsigned char data[MAX_DATA];
}LCM_Init_Code;

typedef struct LCM_force_cmd_code_tag{
	unsigned int datatype;
	LCM_Init_Code real_cmd_code;
}LCM_Force_Cmd_Code;
#define LCM_TAG_SHIFT 24
#define LCM_TAG_MASK  ((1 << 24) -1)
#define LCM_SEND(len) ((1 << LCM_TAG_SHIFT)| len)
#define LCM_SLEEP(ms) ((2 << LCM_TAG_SHIFT)| ms)
//#define ARRAY_SIZE(array) ( sizeof(array) / sizeof(array[0]))

#define LCM_TAG_SEND  (1<< 0)
#define LCM_TAG_SLEEP (1 << 1)

static LCM_Init_Code init_data[] = {
#if 1  //l901 shengjing  rm68180
     {LCM_SEND(8),{6,0,0xF0,0x55,0xAA,0x52,0x08,0x01}},
     {LCM_SEND(6),{4,0,0xB0,0x0D,0x0D,0x0D}},
     {LCM_SEND(6),{4,0,0xB1,0x05,0x05,0x05}},
     {LCM_SEND(6),{4,0,0xB6,0x34,0x34,0x34}},
     {LCM_SEND(6),{4,0,0xB7,0x34,0x34,0x34}},
     {LCM_SEND(6),{4,0,0xB8,0x24,0x24,0x24}},
     {LCM_SEND(6),{4,0,0xB9,0x34,0x34,0x34}},
     {LCM_SEND(6),{4,0,0xBA,0x04,0x04,0x04}},
     {LCM_SEND(6),{4,0,0xBC,0x00,0x90,0x00}},
     {LCM_SEND(6),{4,0,0xBD,0x00,0x90,0x00}},
     {LCM_SEND(5),{3,0,0xBE,0x00,0x75}},
     {LCM_SEND(2),{0xCC,0x05}},
     {LCM_SEND(55),{53,0,0xD1,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x3B,0x00,0x60,0x00,0x9E,0x00,0xCF,0x01,0x17,0x01,0x4B,0x01,0x93,0x01,0xC6,0x02,0x10,0x02,0x48,0x02,0x49,0x02,0x79,0x02,0xAA,0x02,0xC4,0x02,0xE4,0x02,0xF8,0x03,0x10,0x03,0x20,0x03,0x36,0x03,0x46,0x03,0x5C,0x03,0x8B,0x03,0xFF}},
     {LCM_SEND(55),{53,0,0xD2,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x3B,0x00,0x60,0x00,0x9E,0x00,0xCF,0x01,0x17,0x01,0x4B,0x01,0x93,0x01,0xC6,0x02,0x10,0x02,0x48,0x02,0x49,0x02,0x79,0x02,0xAA,0x02,0xC4,0x02,0xE4,0x02,0xF8,0x03,0x10,0x03,0x20,0x03,0x36,0x03,0x46,0x03,0x5C,0x03,0x8B,0x03,0xFF}},
     {LCM_SEND(55),{53,0,0xD3,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x3B,0x00,0x60,0x00,0x9E,0x00,0xCF,0x01,0x17,0x01,0x4B,0x01,0x93,0x01,0xC6,0x02,0x10,0x02,0x48,0x02,0x49,0x02,0x79,0x02,0xAA,0x02,0xC4,0x02,0xE4,0x02,0xF8,0x03,0x10,0x03,0x20,0x03,0x36,0x03,0x46,0x03,0x5C,0x03,0x8B,0x03,0xFF}},
     {LCM_SEND(55),{53,0,0xD4,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x3B,0x00,0x60,0x00,0x9E,0x00,0xCF,0x01,0x17,0x01,0x4B,0x01,0x93,0x01,0xC6,0x02,0x10,0x02,0x48,0x02,0x49,0x02,0x79,0x02,0xAA,0x02,0xC4,0x02,0xE4,0x02,0xF8,0x03,0x10,0x03,0x20,0x03,0x36,0x03,0x46,0x03,0x5C,0x03,0x8B,0x03,0xFF}},
     {LCM_SEND(55),{53,0,0xD5,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x3B,0x00,0x60,0x00,0x9E,0x00,0xCF,0x01,0x17,0x01,0x4B,0x01,0x93,0x01,0xC6,0x02,0x10,0x02,0x48,0x02,0x49,0x02,0x79,0x02,0xAA,0x02,0xC4,0x02,0xE4,0x02,0xF8,0x03,0x10,0x03,0x20,0x03,0x36,0x03,0x46,0x03,0x5C,0x03,0x8B,0x03,0xFF}},
     {LCM_SEND(55),{53,0,0xD6,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x3B,0x00,0x60,0x00,0x9E,0x00,0xCF,0x01,0x17,0x01,0x4B,0x01,0x93,0x01,0xC6,0x02,0x10,0x02,0x48,0x02,0x49,0x02,0x79,0x02,0xAA,0x02,0xC4,0x02,0xE4,0x02,0xF8,0x03,0x10,0x03,0x20,0x03,0x36,0x03,0x46,0x03,0x5C,0x03,0x8B,0x03,0xFF}},
     {LCM_SEND(8),{6,0,0xF0,0x55,0xAA,0x52,0x08,0x00}},
     {LCM_SEND(2),{0xB1,0xFC}},
     {LCM_SEND(2),{0xB4,0x10}},
     {LCM_SEND(2),{0xB6,0x01}},
     {LCM_SEND(7),{5,0,0xB8,0x01,0x04,0x04,0x04}},
     {LCM_SEND(2),{0xBA,0x01}},
     {LCM_SEND(6),{4,0,0xBC,0x02,0x02,0x02}},
     {LCM_SEND(2),{0x3A,0x77}}, //0x55
     {LCM_SEND(5),{3,0,0xC9,0xC0,0x01}},
     {LCM_SEND(8),{6,0,0xF0,0x55,0xAA,0x52,0x08,0x02}},
     {LCM_SEND(2),{0xF6,0x60}},
     {LCM_SEND(2),{0x35,0x00}},
     {LCM_SEND(2),{0x36,0x00}},
     {LCM_SEND(5),{3,0,0x44,0x00,0x50}},
     {LCM_SEND(8),{6,0,0xF0,0x55,0xAA,0x52,0x08,0x01}},
     {LCM_SEND(7),{5,0,0x2A,0x00,0x00,0x01,0xDF}},
     {LCM_SEND(7),{5,0,0x2B,0x00,0x00,0x03,0x1F}}, //0x355
     {LCM_SEND(1),{0x11}},
     {LCM_SLEEP(120)},
     {LCM_SEND(1),{0x29}},
     {LCM_SLEEP(100)},
#endif
};

static LCM_Force_Cmd_Code rd_prep_code[]={
	{0x39, {LCM_SEND(8), {0x6, 0, 0xF0, 0x55, 0xAA, 0x52, 0x08, 0x01}}},
	{0x37, {LCM_SEND(2), {0x3, 0}}},
};

static LCM_Init_Code disp_on =  {LCM_SEND(1), {0x29}};

static LCM_Init_Code sleep_in =  {LCM_SEND(1), {0x10}};

static LCM_Init_Code sleep_out =  {LCM_SEND(1), {0x11}};

static int32_t rm68180_mipi_init(struct panel_spec *self)
{
	int32_t i;
	LCM_Init_Code *init = init_data;
	unsigned int tag;

	mipi_set_cmd_mode_t mipi_set_cmd_mode = self->info.mipi->ops->mipi_set_cmd_mode;
	mipi_gen_write_t mipi_gen_write = self->info.mipi->ops->mipi_gen_write;
	mipi_dcs_write_t mipi_dcs_write = self->info.mipi->ops->mipi_dcs_write;

	LCD_PRINT("rm68180_init\n");
	mipi_eotp_set_t mipi_eotp_set = self->info.mipi->ops->mipi_eotp_set;
	mipi_set_cmd_mode();
	mipi_eotp_set(1,0);

	for(i = 0; i < ARRAY_SIZE(init_data); i++){
		tag = (init->tag >>24);
		if(tag & LCM_TAG_SEND){
			mipi_gen_write(init->data, (init->tag & LCM_TAG_MASK));
			udelay(20);
		}else if(tag & LCM_TAG_SLEEP){
			udelay((init->tag & LCM_TAG_MASK) * 1000);
		}
		init++;
	}
	mipi_eotp_set(1,1);

	return 0;
}

static uint32_t rm68180_readid(struct panel_spec *self)
{

//{LCM_SEND(8), {6,0,0xF0,0x55,0xAA,0x52,0x08,0x01}},   
	/*Jessica TODO: need read id*/
	int32_t i = 0;
	uint32_t j =0;
	LCM_Force_Cmd_Code * rd_prepare = rd_prep_code;
	
	uint8_t read_data[3] = {0};
	uint8_t read_c5[3] = {0};
	int32_t read_rtn = 0;
	unsigned int tag = 0;
#if 1
	mipi_set_cmd_mode_t mipi_set_cmd_mode = self->info.mipi->ops->mipi_set_cmd_mode;
	mipi_force_write_t mipi_force_write = self->info.mipi->ops->mipi_force_write;
	mipi_force_read_t mipi_force_read = self->info.mipi->ops->mipi_force_read;
	mipi_set_lp_mode_t mipi_set_lp_mode = self->info.mipi->ops->mipi_set_lp_mode;
	mipi_set_hs_mode_t mipi_set_hs_mode = self->info.mipi->ops->mipi_set_hs_mode;
	mipi_eotp_set_t mipi_eotp_set = self->info.mipi->ops->mipi_eotp_set;

	printk("lcd_rm68180_mipi read id!\n");
	mipi_set_cmd_mode();
	mipi_eotp_set(1,0);
	//mipi_force_read(0x0, 3,(uint8_t *)read_data);

	for(j = 0; j < 4; j++){
		for(i = 0; i < ARRAY_SIZE(rd_prep_code); i++){
			tag = (rd_prepare->real_cmd_code.tag >> 24);
			if(tag & LCM_TAG_SEND){
				mipi_force_write(rd_prepare->datatype, rd_prepare->real_cmd_code.data, (rd_prepare->real_cmd_code.tag & LCM_TAG_MASK));
			}else if(tag & LCM_TAG_SLEEP){
				udelay((rd_prepare->real_cmd_code.tag & LCM_TAG_MASK) * 1000);
			}
			rd_prepare++;	
		}
		read_rtn = mipi_force_read(0x04, 3,(uint8_t *)read_data);
		printk("lcd_rm68180_mipi read id value is 0x%x, 0x%x, 0x%x!\n", read_data[0], read_data[1], read_data[2]);	
		//0x00 0x80 0x00
		//return 0x80;
		if((0x80 == read_data[1])){
			self->info.mipi->ops->mipi_set_hs_mode();
			printk("lcd_rm68180_mipi read id success!\n");
			mipi_eotp_set(1,1);
			return 0x80;
		}
		else 
			printk("lcd_rm68180_mipi read id failed!\n");

	}
	mipi_eotp_set(1,1);
#endif
	return 0x00;
}

static struct panel_operations lcd_rm68180_mipi_operations = {
	.panel_init = rm68180_mipi_init,
	.panel_readid = rm68180_readid,
};

static struct timing_rgb lcd_rm68180_mipi_timing = {
#if  1
	.hfp = 60,  /* unit: pixel */
	.hbp = 20,
	.hsync = 10,//4,
	.vfp = 16, /*unit: line*/
	.vbp = 8,
	.vsync = 4,//6
#else
/*
	.hfp = 120,  
	.hbp = 120,
	.hsync = 60,
	.vfp = 6, 
	.vbp = 6,
	.vsync = 4,
*/
	.hfp =70,  /* unit: pixel */
	.hbp = 40,
	.hsync = 10,
	.vfp = 10, /*unit: line*/
	.vbp = 10,
	.vsync = 12,
#endif
};

static struct info_mipi lcd_rm68180_mipi_info = {
	.work_mode  = SPRDFB_MIPI_MODE_VIDEO,
	.video_bus_width = 24, /*18,16*/
	.lan_number = 2,
	.phy_feq = 360*1000,
	.h_sync_pol = SPRDFB_POLARITY_POS,
	.v_sync_pol = SPRDFB_POLARITY_POS,
	.de_pol = SPRDFB_POLARITY_POS,
	.te_pol = SPRDFB_POLARITY_POS,
	.color_mode_pol = SPRDFB_POLARITY_NEG,
	.shut_down_pol = SPRDFB_POLARITY_NEG,
	.timing = &lcd_rm68180_mipi_timing,
	.ops = NULL,
};

struct panel_spec lcd_rm68180_mipi_spec = {
	.width = 480,
	.height = 800, //854,
	.fps = 60,
	.type = LCD_MODE_DSI,
	.direction = LCD_DIRECT_NORMAL,
	.info = {
		.mipi = &lcd_rm68180_mipi_info
	},
	.ops = &lcd_rm68180_mipi_operations,
};
