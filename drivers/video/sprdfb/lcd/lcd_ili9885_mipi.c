/* drivers/video/sprdfb/lcd_nt35597_mipi.c
 *
 * Support for ili9885 mipi LCD device
 *
 * Copyright (C) 2015 Spreadtrum
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

#include "../sprdfb_chip_common.h"
#include "../sprdfb.h"
#include "../sprdfb_panel.h"

#define printk printf

#define  LCD_DEBUG
#ifdef LCD_DEBUG
#define LCD_PRINT printk
#else
#define LCD_PRINT(...)
#endif

#define MAX_DATA   130

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

#define LCM_TAG_SEND  (1<< 0)
#define LCM_TAG_SLEEP (1 << 1)

static LCM_Init_Code init_data[] = {
	{LCM_SEND(6),{4,0,0xB0,0x98,0x85,0x0A}},
	{LCM_SEND(6),{4,0,0xD1,0x09,0x09,0xC2}},
	{LCM_SEND(10),{8,0,0xC4,0x70,0x00,0x23,0x00,0x20,0x20,0x00 }},
	{LCM_SEND(9),{7,0,0xD0,0x33,0x05,0x34,0x76,0x5A,0x00}},
	{LCM_SEND(7),{5,0,0xD2,0x03,0x03,0x2A,0x22}},
	{LCM_SEND(12),{10,0,0xD3,0x33,0x33,0x05,0x03,0x59,0x59,0x77,0x2B,0x22}},
	{LCM_SEND(17),{15,0,0xD5,0x8B,0x00,0x00,0x00,0x01,0x75,0x01,0x75,0x01,0x75,0x00,0x00,0x00,0x00}},
	{LCM_SEND(10),{8,0,0xEC,0x76,0x1E,0x32,0x00,0x46,0x00,0x00}},
	{LCM_SEND(11),{9,0,0xEF,0x8F,0x05,0x52,0x13,0xE1,0x33,0x5b,0x09}},
	{LCM_SEND(15),{13,0,0xD6,0x80,0x00,0x08,0x17,0x23,0x65,0x77,0x44,0x87,0x00,0x00,0x09}},
	{LCM_SEND(76),{74,0,0xE5,0xF6,0xF6,0xF6,0xA8,0xF6,0x18,0x0A,0x5C,0x4E,0x38,0x2A,0xF6,0xF6,0x5B,0x64,0x8C,0x36,0x36,0x36,0xC8,0xF6,0xF6,0xF6,0xA1,0xF6,0x11,0x03,0x55,0x47,0x31,0x23,0xF6,0xF6,0x5B,0x64,0x85,0x36,0x36,0x36,0xC1,0x0e,0x40,0x70,0x00,0x00,0x00,0x40,0x04,0x00,0x01,0x01,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x13,0x13,0x13,0x13,0x13,0x00,0x07 }},
	{LCM_SEND(69),{67,0,0xEA,0x51,0x13,0x00,0x03,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x0d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x03,0x00,0x00,0x00,0x3c,0x70,0x01,0x21,0x00,0x40,0x80,0xc0,0x00,0x00,0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0x33,0x33,0x33,0x22,0x33,0x00,0x00,0x00,0x00,0x11,0x11,0x33,0x33,0xDD,0xDD,0x22,0xCC,0xCC,0xCC,0x33 }},
	{LCM_SEND(26),{24,0,0xED,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40}},
	{LCM_SEND(22),{20,0,0xEE,0x22,0x10,0x02,0x02,0x0F,0x40,0x00,0x07,0x00,0x04,0x00,0x00,0xC0,0xB9,0x77,0x00,0x55,0x05,0x1F }},
	{LCM_SEND(35),{33,0,0xEB,0xA3,0xCF,0x66,0x18,0x54,0x55,0x55,0x55,0x55,0x50,0xA9,0x6A,0x55,0xAA,0x56,0x25,0x0D,0x0F,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x32,0x3E,0x55,0x43,0x55}},
	{LCM_SEND(125),{123,0,0xC7,0x00,0x00,0x00,0x10,0x00,0x30,0x00,0x4D,0x00,0x64,0x00,0x78,0x00,0x8A,0x00,0x9A,0x00,0xA9,0x00,0xDD,0x01,0x07,0x01,0x4A,0x01,0x7F,0x01,0xD2,0x02,0x15,0x02,0x17,0x02,0x53,0x02,0x93,0x02,0xBC,0x02,0xF0,0x03,0x14,0x03,0x41,0x03,0x4F,0x03,0x5E,0x03,0x6F,0x03,0x84,0x03,0x9A,0x03,0xB7,0x03,0xD6,0x03,0xE6,0x00,0x00,0x00,0x10,0x00,0x30,0x00,0x4D,0x00,0x64,0x00,0x78,0x00,0x8A,0x00,0x9A,0x00,0xA9,0x00,0xDD,0x01,0x07,0x01,0x4A,0x01,0x7F,0x01,0xD2,0x02,0x15,0x02,0x17,0x02,0x53,0x02,0xa8,0x02,0xd2,0x03,0x0f,0x03,0x38,0x03,0x5a,0x03,0x5F,0x03,0x5E,0x03,0x6F,0x03,0x84,0x03,0x9A,0x03,0xB7,0x03,0xD6,0x03,0xE6,0x01,0x01}},
	{LCM_SEND(6),{4,0,0xC1,0x04,0x00,0x01}},
	{LCM_SEND(2),{0x35,0x00}},
	{LCM_SEND(2),{0x36,0x00}},
	{LCM_SEND(1),{0x11}},
	{LCM_SLEEP(120)},
	{LCM_SEND(8),{6,0,0xD7,0x00,0x00,0x00,0x81,0x07}},
	{LCM_SEND(1),{0x29}},
	{LCM_SLEEP(10)},
};


static LCM_Force_Cmd_Code rd_prep_code[]={
	{0x37, {LCM_SEND(2), {0x3, 0}}},
};

static int32_t ili9885_mipi_init(struct panel_spec *self)
{
	int32_t i = 0;
	LCM_Init_Code *init = init_data;
	unsigned int tag;

	mipi_set_cmd_mode_t mipi_set_cmd_mode = self->info.mipi->ops->mipi_set_cmd_mode;
	mipi_gen_write_t mipi_gen_write = self->info.mipi->ops->mipi_gen_write;

	LCD_PRINT("sprdfb:ili9885_mipi_init\n");

	mipi_set_cmd_mode();

	for(i = 0; i < ARRAY_SIZE(init_data); i++){
		tag = (init->tag >>24);
		if(tag & LCM_TAG_SEND){
			mipi_gen_write(init->data, (init->tag & LCM_TAG_MASK));
			udelay(20);
		}else if(tag & LCM_TAG_SLEEP){
			mdelay((init->tag & LCM_TAG_MASK));
		}
		init++;
	}
	return 0;
}

static uint32_t ili9885_readid(struct panel_spec *self)
{
	int32_t i = 0;
	uint32_t j =0;
	LCM_Force_Cmd_Code * rd_prepare = rd_prep_code;
	uint8_t read_data[3] = {0};
	int32_t read_rtn = 0;
	unsigned int tag = 0;
	mipi_set_cmd_mode_t mipi_set_cmd_mode = self->info.mipi->ops->mipi_set_cmd_mode;
	mipi_force_write_t mipi_force_write = self->info.mipi->ops->mipi_force_write;
	mipi_force_read_t mipi_force_read = self->info.mipi->ops->mipi_force_read;
	mipi_eotp_set_t mipi_eotp_set = self->info.mipi->ops->mipi_eotp_set;

	LCD_PRINT("sprdfb:lcd_ili9885_mipi read id!\n");
	mipi_set_cmd_mode();
	mipi_eotp_set(0,1);

	for(j = 0; j < 4; j++){
		rd_prepare = rd_prep_code;
		for(i = 0; i < ARRAY_SIZE(rd_prep_code); i++){
			tag = (rd_prepare->real_cmd_code.tag >> 24);
			if(tag & LCM_TAG_SEND){
				mipi_force_write(rd_prepare->datatype, rd_prepare->real_cmd_code.data, (rd_prepare->real_cmd_code.tag & LCM_TAG_MASK));
			}else if(tag & LCM_TAG_SLEEP){
				mdelay((rd_prepare->real_cmd_code.tag & LCM_TAG_MASK));
			}
			rd_prepare++;
		}
		read_rtn = mipi_force_read(0xbf, 2,(uint8_t *)read_data);
		printk("lcd_ili9885_mipi read id 0xbf value is 0x%x, 0x%x, 0x%x!\n", read_data[0], read_data[1], read_data[2]);

		if(0x98 == read_data[0]){
			printk("lcd_ili9885_mipi read id success!\n");
			mipi_eotp_set(1,1);
			i2c_set_bus_num(4);
			i2c_init(100000, 0x3E);
			i2c_reg_write(0x3E, 0x00, 0x0E);
			mdelay(50);
			i2c_reg_write(0x3E, 0x01, 0x0E);
			mdelay(50);
			return 0x98;
		}
	}
	mipi_eotp_set(1,1);
	return 0x0;
}

int32_t ili9885_reset(struct panel_spec *self)
{
	sprd_gpio_request(NULL, LCM_GPIO_AVDDEN);
	sprd_gpio_direction_output(NULL, LCM_GPIO_AVDDEN, 1);
	mdelay(10);

	sprd_gpio_request(NULL, LCM_GPIO_AVEEEN);
	sprd_gpio_direction_output(NULL, LCM_GPIO_AVEEEN, 1);
	mdelay(20);

	sprd_gpio_request(NULL, LCM_GPIO_RSTN);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN, 1);
	mdelay(5);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN, 0);
	mdelay(5);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN, 1);
	mdelay(5);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN, 0);
	mdelay(5);
	sprd_gpio_direction_output(NULL, LCM_GPIO_RSTN, 1);
	mdelay(20);

	return 0;
}

static struct panel_operations lcd_ili9885_mipi_operations = {
	.panel_init = ili9885_mipi_init,
	.panel_readid = ili9885_readid,
	.panel_reset = ili9885_reset,
};

static struct timing_rgb lcd_ili9885_mipi_timing = {
	.hfp = 6,  /* unit: pixel */
	.hbp = 6,
	.hsync = 8,//4,
	.vfp = 16, /*unit: line*/
	.vbp = 8,
	.vsync = 8,
};

static struct info_mipi lcd_ili9885_mipi_info = {
	.work_mode  = SPRDFB_MIPI_MODE_VIDEO,
	.video_bus_width = 24, /*18,16*/
	.lan_number = 4,
	.phy_feq = 910*1000,
	.h_sync_pol = SPRDFB_POLARITY_POS,
	.v_sync_pol = SPRDFB_POLARITY_POS,
	.de_pol = SPRDFB_POLARITY_POS,
	.te_pol = SPRDFB_POLARITY_POS,
	.color_mode_pol = SPRDFB_POLARITY_NEG,
	.shut_down_pol = SPRDFB_POLARITY_NEG,
	.timing = &lcd_ili9885_mipi_timing,
	.ops = NULL,
};

struct panel_spec lcd_ili9885_mipi_spec = {
	.width = 1080,
	.height =1920,
	.fps = 60,
	.type = LCD_MODE_DSI,
	.direction = LCD_DIRECT_NORMAL,
	.is_need_reset = 1,
	//.is_need_dsc = 1,
	.info = {
		.mipi = &lcd_ili9885_mipi_info
	},
	.ops = &lcd_ili9885_mipi_operations,
};

