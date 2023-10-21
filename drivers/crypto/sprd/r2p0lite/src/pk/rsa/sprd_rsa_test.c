/*
* Copyright (c) 2016, Spreadtrum Communications.
*
* The above copyright notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <sprd_crypto.h>
#include <sprd_rsa.h>

static struct {
	uint32_t data_len;
	uint8_t key_n[512];
	uint8_t key_e[4];
	uint8_t key_d[512];
	uint8_t din[512];
	uint8_t dout[512];
} tests[] =
{
	{
		32,
		//n
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x43, },
		//e
		{ 0x00, 0x00, 0x00, 0x05, },
		//d
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D, },
		//in
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7B, },
		//out
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE1, },
	},

	{ //1024
		128,
		//n
		{ 0x77, 0xA6, 0x64, 0x81, 0xC6, 0x66, 0x31, 0xE7, 0xFE, 0x2B, 0xF2, 0x82, 0xF6, 0xC3, 0x3C, 0x8E,
		  0x4E, 0x57, 0x7B, 0xF9, 0xE7, 0xCA, 0x96, 0x8C, 0xDD, 0xA1, 0x48, 0xE6, 0x23, 0x85, 0xC6, 0x17,
		  0x23, 0xE5, 0x61, 0x80, 0x4D, 0x7F, 0x28, 0x0B, 0xA0, 0xF8, 0xCE, 0x01, 0x5E, 0x82, 0x9D, 0x30,
		  0xF7, 0xA7, 0x7D, 0x0B, 0x05, 0x5A, 0xB5, 0x0A, 0x0D, 0xB3, 0xC7, 0xA2, 0x6D, 0x9C, 0xB5, 0xA6,
		  0x1B, 0xDB, 0xF6, 0x44, 0x6D, 0xBF, 0x52, 0xA4, 0xD9, 0x65, 0x7A, 0xED, 0xAB, 0x27, 0x96, 0xF3,
		  0x51, 0xA9, 0xFD, 0xD6, 0x62, 0xFB, 0x9B, 0x97, 0x7F, 0x46, 0x82, 0x9A, 0xDE, 0x78, 0xBC, 0x10,
		  0xA1, 0x46, 0x70, 0x61, 0x9E, 0x17, 0x3E, 0x0B, 0xFD, 0x84, 0x0A, 0x2B, 0x98, 0x1D, 0x01, 0x48,
		  0x4A, 0x6F, 0x3F, 0xA8, 0xE1, 0x0D, 0xBB, 0x66, 0x8F, 0x2C, 0xC0, 0x54, 0x65, 0x81, 0xC3, 0xA7, },
		//e
		{ 0x00, 0x01, 0x00, 0x01, },
		//d
		{ 0x30, 0xAC, 0x3B, 0x8E, 0x9F, 0x4A, 0xCB, 0x5A, 0x78, 0x87, 0x20, 0x2C, 0x2E, 0x7D, 0xD5, 0x90,
		  0x7E, 0x46, 0x10, 0x64, 0xE4, 0xEA, 0x00, 0xBC, 0x65, 0x1C, 0x4B, 0x2F, 0x73, 0x9B, 0xE3, 0xAD,
		  0x5E, 0x28, 0xDD, 0xB4, 0xF7, 0xD1, 0x96, 0x54, 0xC4, 0xB2, 0xF1, 0xFA, 0x94, 0x9B, 0xC5, 0x9E,
		  0x39, 0xE0, 0xA4, 0x79, 0x6B, 0x40, 0x2F, 0x0D, 0x5B, 0xED, 0x9A, 0x74, 0x74, 0xEA, 0x9E, 0xE9,
		  0xD7, 0xA1, 0x2C, 0x1E, 0x63, 0x5E, 0xDE, 0xD1, 0x8F, 0xB8, 0xAC, 0xC0, 0x0F, 0xC7, 0xD4, 0xC6,
		  0x28, 0xD5, 0x60, 0x58, 0x60, 0xBF, 0xC7, 0xB3, 0x41, 0x79, 0x6A, 0x57, 0x2D, 0x22, 0xD5, 0x29,
		  0xB5, 0xA1, 0x7F, 0x3D, 0x8B, 0xC2, 0xD4, 0x5B, 0x23, 0x06, 0xCE, 0xAA, 0xB4, 0x66, 0x43, 0xA5,
		  0x86, 0xA5, 0xD6, 0x61, 0x79, 0x34, 0x9E, 0xB8, 0x42, 0xD9, 0x08, 0x25, 0xD6, 0x91, 0x32, 0xC1, },
		//in
		{ 0x30, 0xAC, 0x3B, 0x8E, 0x9F, 0x4A, 0xCB, 0x5A, 0x78, 0x87, 0x20, 0x2C, 0x2E, 0x7D, 0xD5, 0x90,
		  0x7E, 0x46, 0x10, 0x64, 0xE4, 0xEA, 0x00, 0xBC, 0x65, 0x1C, 0x4B, 0x2F, 0x73, 0x9B, 0xE3, 0xAD,
		  0x5E, 0x28, 0xDD, 0xB4, 0xF7, 0xD1, 0x96, 0x54, 0xC4, 0xB2, 0xF1, 0xFA, 0x94, 0x9B, 0xC5, 0x9E,
		  0x39, 0xE0, 0xA4, 0x79, 0x6B, 0x40, 0x2F, 0x0D, 0x5B, 0xED, 0x9A, 0x74, 0x74, 0xEA, 0x9E, 0xE9,
		  0xD7, 0xA1, 0x2C, 0x1E, 0x63, 0x5E, 0xDE, 0xD1, 0x8F, 0xB8, 0xAC, 0xC0, 0x0F, 0xC7, 0xD4, 0xC6,
		  0x28, 0xD5, 0x60, 0x58, 0x60, 0xBF, 0xC7, 0xB3, 0x41, 0x79, 0x6A, 0x57, 0x2D, 0x22, 0xD5, 0x29,
		  0xB5, 0xA1, 0x7F, 0x3D, 0x8B, 0xC2, 0xD4, 0x5B, 0x23, 0x06, 0xCE, 0xAA, 0xB4, 0x66, 0x43, 0xA5,
		  0x86, 0xA5, 0xD6, 0x61, 0x79, 0x34, 0x9E, 0xB8, 0x42, 0xD9, 0x08, 0x25, 0xD6, 0x91, 0x32, 0xC1, },
		//out
		{ 0x58, 0xAA, 0xE3, 0x98, 0x0B, 0xEB, 0x82, 0x25, 0x0C, 0x45, 0x31, 0xF1, 0x8B, 0x71, 0xFD, 0xBE,
		  0xDE, 0x69, 0x6D, 0x93, 0x23, 0x8A, 0x94, 0x9C, 0x3E, 0x9B, 0x26, 0x2A, 0x85, 0xDF, 0x10, 0x63,
		  0x89, 0xA1, 0x76, 0x8D, 0xD6, 0x30, 0xEC, 0x6D, 0x58, 0x40, 0xB8, 0x1A, 0x96, 0xCA, 0xD1, 0xDB,
		  0xA3, 0x15, 0x5F, 0x8F, 0x64, 0xE7, 0xEA, 0x59, 0xA1, 0xA6, 0x8D, 0x02, 0x01, 0x81, 0x0B, 0xBC,
		  0x21, 0xE2, 0x48, 0xC6, 0x55, 0x26, 0x86, 0x94, 0xF3, 0xE7, 0x16, 0xD0, 0x19, 0xB0, 0x3E, 0xC7,
		  0xF8, 0x39, 0x1E, 0x46, 0xCA, 0x3E, 0xBA, 0x11, 0xD5, 0xF2, 0x9C, 0xFB, 0x96, 0x54, 0x3E, 0xD1,
		  0x4F, 0x45, 0xE3, 0x82, 0x22, 0x4B, 0x50, 0xDA, 0xE6, 0x27, 0x6A, 0x48, 0xD0, 0x0E, 0x47, 0x4C,
		  0x25, 0x76, 0x14, 0x7C, 0x3B, 0x50, 0xCA, 0xEF, 0x2E, 0x0B, 0x21, 0x82, 0xFE, 0xF7, 0xFE, 0xA0, },
	},

	{ //2048
		256,
		//n
		{ 0xBB, 0xE6, 0x11, 0x28, 0x13, 0x40, 0xD8, 0x6D, 0xE9, 0x54, 0x78, 0x82, 0x01, 0xA0, 0xDE, 0xCE,
		  0x2D, 0x57, 0x69, 0x8E, 0x8A, 0x93, 0x26, 0x4F, 0x72, 0x3F, 0xEB, 0xEF, 0xE1, 0xE9, 0xF9, 0x2E,
		  0x6F, 0x43, 0x47, 0x0A, 0x4B, 0xA0, 0x83, 0xFC, 0x8C, 0xC4, 0x93, 0xD9, 0xFC, 0x2E, 0xC4, 0xF9,
		  0x7E, 0x67, 0xDC, 0x7C, 0xC6, 0xE5, 0xAE, 0xB4, 0x1A, 0xB3, 0xDB, 0xD1, 0xE3, 0x9A, 0xB3, 0xB3,
		  0xF2, 0xCB, 0x94, 0xBA, 0xCC, 0x30, 0x73, 0x62, 0x46, 0x74, 0x44, 0xC1, 0x6B, 0x6B, 0x86, 0x11,
		  0xB7, 0xD1, 0x7F, 0xA0, 0xD3, 0x53, 0x99, 0x7C, 0x9A, 0x78, 0xA1, 0x04, 0x6C, 0x7D, 0x56, 0x09,
		  0x08, 0x7C, 0x14, 0x61, 0xDC, 0xE5, 0x89, 0xB3, 0x24, 0xB1, 0x73, 0x25, 0x7D, 0xE0, 0x5F, 0x43,
		  0x36, 0x1C, 0x12, 0xDD, 0xB5, 0xE3, 0x8C, 0x6F, 0x53, 0x4F, 0x94, 0xE1, 0xD3, 0xDC, 0x94, 0xBE,
		  0xD8, 0x5D, 0xDD, 0x4A, 0x47, 0x13, 0xF6, 0xEE, 0x5F, 0x7C, 0xA2, 0xE5, 0xBF, 0x92, 0xA6, 0xC9,
		  0x08, 0x11, 0x5A, 0xFD, 0x97, 0x68, 0x60, 0x0A, 0x72, 0xBA, 0xA0, 0x5E, 0x81, 0x27, 0xD5, 0x6C,
		  0x19, 0x5D, 0xBA, 0x0F, 0x04, 0x64, 0x2B, 0x79, 0x51, 0xA1, 0x36, 0x5F, 0x34, 0x43, 0xBF, 0xAB,
		  0x31, 0xDB, 0x57, 0xBB, 0xA6, 0x94, 0x9F, 0x3D, 0xBC, 0xE6, 0x69, 0xBD, 0xBC, 0x5D, 0xC4, 0xC0,
		  0x0D, 0x20, 0xC8, 0xF2, 0x85, 0x67, 0xCE, 0x4F, 0x68, 0xC7, 0x9D, 0x73, 0x95, 0x8B, 0x42, 0x2C,
		  0x0D, 0x12, 0x98, 0xAD, 0x53, 0x5F, 0x21, 0xCD, 0x9C, 0x01, 0x21, 0xDE, 0x7E, 0xB2, 0x32, 0xF1,
		  0xC4, 0x66, 0xF5, 0x3D, 0x53, 0x6C, 0x24, 0xA0, 0x86, 0x9B, 0xD4, 0x61, 0xB5, 0x63, 0xF6, 0x45,
		  0x4E, 0xD4, 0x26, 0x86, 0x0C, 0xC9, 0x43, 0x73, 0x9F, 0x18, 0xED, 0x20, 0xE8, 0xA3, 0xC0, 0xC9, },
		//e
		{ 0x00, 0x01, 0x00, 0x01, },
		//d
		{ 0xAE, 0x96, 0xFC, 0xB4, 0x0F, 0x07, 0xBE, 0xD2, 0x89, 0xEE, 0xEA, 0x36, 0x6A, 0x8A, 0xEE, 0xDC,
		  0x06, 0xB7, 0x65, 0x26, 0x84, 0x4E, 0x6C, 0x57, 0x7F, 0xA2, 0x33, 0x79, 0x66, 0xA1, 0xFF, 0xDE,
		  0x0C, 0x96, 0x27, 0xC9, 0x42, 0x32, 0x38, 0xD1, 0x8E, 0x7F, 0x0D, 0x9E, 0x8B, 0xBB, 0x6D, 0x5D,
		  0x21, 0xFE, 0x21, 0x9A, 0x73, 0x39, 0x71, 0x96, 0x7A, 0x05, 0x4B, 0x28, 0x80, 0x62, 0xFB, 0xBD,
		  0x25, 0xC9, 0xD2, 0x3D, 0xAB, 0x83, 0x0D, 0x83, 0x70, 0x51, 0x92, 0x9D, 0x62, 0x51, 0xBB, 0x76,
		  0x75, 0x25, 0x9D, 0x80, 0x73, 0x3C, 0x07, 0xAF, 0x06, 0xDD, 0x35, 0x48, 0x26, 0x02, 0x63, 0xD1,
		  0xEA, 0xE7, 0x58, 0x0D, 0x02, 0xB2, 0xE9, 0xBA, 0xE2, 0x4A, 0x5B, 0xE2, 0xA7, 0x4E, 0xB7, 0x55,
		  0x7D, 0x4E, 0xA2, 0x9D, 0x0D, 0xE8, 0x0C, 0x52, 0x58, 0xC7, 0xE6, 0x5F, 0xDB, 0x7A, 0xE7, 0x5D,
		  0xC1, 0x6D, 0x94, 0x2C, 0x4F, 0x03, 0x6D, 0x34, 0x17, 0x6C, 0xD1, 0xD9, 0x17, 0xF9, 0x06, 0x60,
		  0x20, 0xED, 0xF3, 0x1C, 0xD8, 0x5E, 0x01, 0xB8, 0xBA, 0x15, 0xBF, 0x4F, 0x5A, 0xE9, 0xF1, 0xE5,
		  0x4F, 0xD8, 0xE7, 0x51, 0x28, 0x9C, 0x9A, 0x82, 0x83, 0x74, 0xD0, 0x44, 0x52, 0x1B, 0xEB, 0x65,
		  0x05, 0x68, 0x02, 0x1B, 0x01, 0xD9, 0xC8, 0x16, 0x2B, 0x10, 0xEF, 0x5E, 0x01, 0xFE, 0xF5, 0x47,
		  0x5C, 0x8C, 0xC4, 0xCE, 0x43, 0x6A, 0x44, 0xA1, 0x42, 0x9E, 0x28, 0x8A, 0x56, 0x47, 0x20, 0x5C,
		  0x7F, 0x48, 0x7B, 0xB0, 0xC2, 0xF5, 0x48, 0xA4, 0xC9, 0xCB, 0x71, 0x5F, 0x60, 0x48, 0x22, 0xC6,
		  0x56, 0x55, 0xDA, 0x1E, 0x9F, 0x42, 0x11, 0x1A, 0xA1, 0x03, 0xEC, 0x62, 0x69, 0xFF, 0xDE, 0xBB,
		  0xC7, 0x04, 0xF4, 0xAC, 0xAE, 0x61, 0xE1, 0xB5, 0x71, 0x4C, 0x08, 0x72, 0x4C, 0xDA, 0x96, 0x01, },
		//in
		{ 0x44, 0x63, 0xD0, 0x5B, 0xA8, 0xE1, 0x68, 0x18, 0x24, 0x2E, 0x83, 0xBF, 0xAE, 0x99, 0xD7, 0x3F,
		  0x70, 0x03, 0x4F, 0x63, 0x10, 0x8A, 0x37, 0x88, 0x49, 0x4D, 0xF7, 0xDA, 0x08, 0x11, 0x5C, 0x0A,
		  0x14, 0x63, 0x67, 0x4B, 0x15, 0x69, 0x3B, 0x1D, 0x03, 0x9D, 0x9F, 0x49, 0x7C, 0x14, 0x09, 0xCD,
		  0x9E, 0x10, 0x4C, 0x80, 0xC0, 0x92, 0x43, 0x67, 0x4A, 0x61, 0xD2, 0x8F, 0xBE, 0xA2, 0xB4, 0xA9,
		  0x31, 0x2D, 0xE1, 0x3B, 0xA8, 0xA9, 0x5B, 0x6E, 0x40, 0xD8, 0x41, 0x94, 0xA3, 0x48, 0x03, 0x80,
		  0x1F, 0x69, 0x75, 0x10, 0xF3, 0x8D, 0x13, 0xC8, 0x75, 0x72, 0x7C, 0xEA, 0x32, 0xC2, 0x90, 0xEA,
		  0x87, 0x25, 0xC8, 0xF0, 0xE3, 0xF9, 0x32, 0x45, 0x28, 0x01, 0x3B, 0x97, 0x8F, 0xE9, 0x30, 0xDB,
		  0x89, 0x4B, 0x57, 0x3D, 0x00, 0x8D, 0x0A, 0xB6, 0x65, 0xD2, 0xF2, 0x30, 0x80, 0x12, 0x1E, 0xE5,
		  0xBA, 0xE7, 0x50, 0x63, 0xEA, 0xC3, 0xCF, 0x83, 0xA9, 0x39, 0xF4, 0x93, 0x14, 0x9C, 0xA0, 0xBD,
		  0x22, 0xC6, 0xBD, 0x22, 0x3D, 0xBA, 0xBC, 0xDF, 0x75, 0xA3, 0x63, 0x18, 0xDD, 0xFB, 0x56, 0x02,
		  0xCF, 0x2A, 0x5C, 0xE5, 0x35, 0x54, 0x4D, 0x34, 0x5E, 0xEC, 0x90, 0xAA, 0x88, 0x95, 0xD9, 0x8A,
		  0xA6, 0x91, 0x17, 0x33, 0xEB, 0xA4, 0xF1, 0xAB, 0xA9, 0x15, 0xC4, 0x36, 0x16, 0xBC, 0xBD, 0x5F,
		  0xE1, 0x54, 0xD8, 0x68, 0x83, 0xFE, 0x44, 0x19, 0x62, 0x29, 0xF4, 0x81, 0xA2, 0x04, 0xE0, 0xE5,
		  0x86, 0x4B, 0x78, 0x66, 0x91, 0x19, 0x65, 0xE7, 0x5B, 0x0F, 0xA5, 0x73, 0xB3, 0xFD, 0x76, 0x59,
		  0xEC, 0x62, 0x9C, 0xA2, 0xBC, 0xB6, 0x0D, 0x00, 0x24, 0xC0, 0xD8, 0x57, 0x91, 0x4E, 0x54, 0x8D,
		  0xAD, 0x22, 0x65, 0x30, 0xD3, 0x6D, 0xEF, 0x98, 0x77, 0x80, 0xDF, 0xBD, 0x6F, 0x09, 0x73, 0xAB, },
		//out
		{ 0xAE, 0x96, 0xFC, 0xB4, 0x0F, 0x07, 0xBE, 0xD2, 0x89, 0xEE, 0xEA, 0x36, 0x6A, 0x8A, 0xEE, 0xDC,
		  0x06, 0xB7, 0x65, 0x26, 0x84, 0x4E, 0x6C, 0x57, 0x7F, 0xA2, 0x33, 0x79, 0x66, 0xA1, 0xFF, 0xDE,
		  0x0C, 0x96, 0x27, 0xC9, 0x42, 0x32, 0x38, 0xD1, 0x8E, 0x7F, 0x0D, 0x9E, 0x8B, 0xBB, 0x6D, 0x5D,
		  0x21, 0xFE, 0x21, 0x9A, 0x73, 0x39, 0x71, 0x96, 0x7A, 0x05, 0x4B, 0x28, 0x80, 0x62, 0xFB, 0xBD,
		  0x25, 0xC9, 0xD2, 0x3D, 0xAB, 0x83, 0x0D, 0x83, 0x70, 0x51, 0x92, 0x9D, 0x62, 0x51, 0xBB, 0x76,
		  0x75, 0x25, 0x9D, 0x80, 0x73, 0x3C, 0x07, 0xAF, 0x06, 0xDD, 0x35, 0x48, 0x26, 0x02, 0x63, 0xD1,
		  0xEA, 0xE7, 0x58, 0x0D, 0x02, 0xB2, 0xE9, 0xBA, 0xE2, 0x4A, 0x5B, 0xE2, 0xA7, 0x4E, 0xB7, 0x55,
		  0x7D, 0x4E, 0xA2, 0x9D, 0x0D, 0xE8, 0x0C, 0x52, 0x58, 0xC7, 0xE6, 0x5F, 0xDB, 0x7A, 0xE7, 0x5D,
		  0xC1, 0x6D, 0x94, 0x2C, 0x4F, 0x03, 0x6D, 0x34, 0x17, 0x6C, 0xD1, 0xD9, 0x17, 0xF9, 0x06, 0x60,
		  0x20, 0xED, 0xF3, 0x1C, 0xD8, 0x5E, 0x01, 0xB8, 0xBA, 0x15, 0xBF, 0x4F, 0x5A, 0xE9, 0xF1, 0xE5,
		  0x4F, 0xD8, 0xE7, 0x51, 0x28, 0x9C, 0x9A, 0x82, 0x83, 0x74, 0xD0, 0x44, 0x52, 0x1B, 0xEB, 0x65,
		  0x05, 0x68, 0x02, 0x1B, 0x01, 0xD9, 0xC8, 0x16, 0x2B, 0x10, 0xEF, 0x5E, 0x01, 0xFE, 0xF5, 0x47,
		  0x5C, 0x8C, 0xC4, 0xCE, 0x43, 0x6A, 0x44, 0xA1, 0x42, 0x9E, 0x28, 0x8A, 0x56, 0x47, 0x20, 0x5C,
		  0x7F, 0x48, 0x7B, 0xB0, 0xC2, 0xF5, 0x48, 0xA4, 0xC9, 0xCB, 0x71, 0x5F, 0x60, 0x48, 0x22, 0xC6,
		  0x56, 0x55, 0xDA, 0x1E, 0x9F, 0x42, 0x11, 0x1A, 0xA1, 0x03, 0xEC, 0x62, 0x69, 0xFF, 0xDE, 0xBB,
		  0xC7, 0x04, 0xF4, 0xAC, 0xAE, 0x61, 0xE1, 0xB5, 0x71, 0x4C, 0x08, 0x72, 0x4C, 0xDA, 0x96, 0x01, },
	},

	{ //3072
		384,
		//n
		{ 0x8D, 0x99, 0x66, 0xBF, 0x05, 0x8F, 0xA5, 0x49, 0x6F, 0xD9, 0xEF, 0x24, 0xCD, 0x61, 0x5B, 0xB6,
		  0x1F, 0xEC, 0x0F, 0x02, 0x31, 0x4A, 0x26, 0xC2, 0x66, 0x1B, 0x75, 0x26, 0x73, 0x38, 0xDC, 0x16,
		  0x23, 0x36, 0x5F, 0xE2, 0x35, 0xA3, 0x36, 0xB1, 0x31, 0xE6, 0xB2, 0xED, 0x9A, 0xF9, 0xBB, 0x36,
		  0xF0, 0xFE, 0xDE, 0x7B, 0x7A, 0x25, 0x67, 0xD7, 0x71, 0x11, 0x74, 0xEC, 0x96, 0x3E, 0xCB, 0xAE,
		  0x74, 0xB0, 0x2E, 0x43, 0xA5, 0xC0, 0xA6, 0x52, 0x71, 0x3A, 0xC9, 0x0B, 0xA6, 0x53, 0xD8, 0x32,
		  0x00, 0xB6, 0x57, 0x5C, 0x66, 0xA7, 0x1E, 0xDC, 0x3E, 0x65, 0xBE, 0x17, 0xDC, 0xBD, 0xAF, 0x71,
		  0x83, 0x22, 0x2F, 0x28, 0xD4, 0xF2, 0x5C, 0x15, 0x61, 0xD9, 0x47, 0x30, 0x2F, 0x31, 0x6D, 0xB6,
		  0xFA, 0xAE, 0x60, 0xE5, 0x37, 0x21, 0x04, 0xAE, 0x9A, 0x5C, 0x21, 0xCF, 0x92, 0x88, 0xAC, 0xBC,
		  0x07, 0x52, 0x0A, 0x41, 0x6C, 0x3B, 0xA7, 0x92, 0xFE, 0x7F, 0x22, 0x3A, 0x96, 0x51, 0x84, 0x45,
		  0xBF, 0x2B, 0x3F, 0x2F, 0xD1, 0xAE, 0xBD, 0x78, 0x7E, 0x0A, 0x52, 0x2E, 0xE7, 0x39, 0xE4, 0x36,
		  0xD4, 0xDD, 0x96, 0x34, 0x1B, 0x86, 0xC1, 0x32, 0x4B, 0xDB, 0xE7, 0xF7, 0x38, 0x2B, 0x91, 0x70,
		  0x1B, 0xBF, 0x70, 0x5C, 0x87, 0xAB, 0xD0, 0x90, 0xB5, 0xFB, 0x35, 0xE8, 0xA3, 0x4D, 0xF4, 0x74,
		  0xAA, 0xBE, 0x73, 0x3D, 0x54, 0x4A, 0x16, 0xE9, 0x8B, 0x82, 0x36, 0xA8, 0x0A, 0x77, 0x1F, 0xB1,
		  0x04, 0xC7, 0x22, 0xB1, 0xAE, 0xC3, 0x5F, 0x1F, 0xF5, 0x11, 0x0F, 0xB5, 0x28, 0x05, 0x1D, 0x00,
		  0xEB, 0xB2, 0x69, 0x3D, 0x7D, 0xA2, 0xDF, 0xD4, 0x6D, 0xF8, 0x34, 0x69, 0x76, 0x08, 0x7C, 0xC7,
		  0xCB, 0xED, 0xDF, 0x35, 0x41, 0x25, 0xD3, 0x42, 0x76, 0xA7, 0xCB, 0xC2, 0xD0, 0x81, 0x9D, 0xFC,
		  0xF9, 0x52, 0x9B, 0xE3, 0xFD, 0xD5, 0xEA, 0x4A, 0x08, 0x00, 0xFF, 0x5A, 0x48, 0x99, 0xF5, 0x9C,
		  0x25, 0xB7, 0xC6, 0x90, 0xB5, 0x14, 0x95, 0x1D, 0x9B, 0xD5, 0x06, 0x05, 0xEC, 0xE5, 0x4A, 0x61,
		  0x6E, 0x4C, 0xCA, 0x51, 0x3C, 0x86, 0xB7, 0xF2, 0xDA, 0xCD, 0xD8, 0xB8, 0xB7, 0x5C, 0x27, 0xF9,
		  0x81, 0xA3, 0x4A, 0x13, 0xEE, 0xAB, 0x96, 0xD4, 0xBB, 0xC3, 0x1B, 0x03, 0xBF, 0x45, 0x42, 0x3B,
		  0x95, 0x19, 0xDB, 0x36, 0xF3, 0xD3, 0xBB, 0x44, 0xBE, 0xB5, 0x1C, 0x25, 0x97, 0xE1, 0x65, 0xBF,
		  0xF0, 0x0B, 0x1B, 0xBC, 0xCA, 0x52, 0xC2, 0xDD, 0x37, 0x80, 0xC9, 0xDD, 0xC4, 0x25, 0x7F, 0xCE,
		  0x19, 0x3C, 0x02, 0xCB, 0xF3, 0x1B, 0x48, 0x5D, 0x55, 0x64, 0x2A, 0x78, 0x2B, 0xD1, 0x58, 0xB4,
		  0xC4, 0x76, 0x38, 0x45, 0x16, 0xE9, 0x1B, 0xE2, 0xAA, 0x1B, 0xC6, 0x55, 0x55, 0xE6, 0x18, 0x1D, },
		//e
		{ 0x00, 0x01, 0x00, 0x01, },
		//d
		{ 0x11, 0x73, 0x7F, 0x7B, 0x39, 0x67, 0x3B, 0xBA, 0xB2, 0x43, 0x4C, 0xBA, 0xDF, 0x69, 0x09, 0x51,
		  0x87, 0xDB, 0xA2, 0xF9, 0xE5, 0x33, 0x3B, 0x55, 0xA8, 0x19, 0xE8, 0x35, 0x45, 0xEC, 0x13, 0x0B,
		  0xD3, 0x69, 0x27, 0x26, 0x0C, 0xF0, 0x41, 0x94, 0x53, 0x0F, 0x18, 0xAC, 0x39, 0xF6, 0x5F, 0x41,
		  0x65, 0x30, 0x34, 0x21, 0x49, 0xAB, 0x84, 0x81, 0xC3, 0xD8, 0x9F, 0xED, 0x6C, 0x92, 0xEE, 0xAD,
		  0x60, 0x8A, 0x3A, 0x19, 0x72, 0x3B, 0x2D, 0x04, 0x6A, 0x1A, 0x11, 0x9F, 0x12, 0xEF, 0xB0, 0x6C,
		  0x71, 0x34, 0x07, 0xCE, 0x46, 0x84, 0x80, 0x44, 0x2A, 0x98, 0x85, 0x76, 0x11, 0x69, 0x7B, 0x4E,
		  0xE5, 0x17, 0x78, 0x72, 0x72, 0xD4, 0x2F, 0xCF, 0x1E, 0xD1, 0x15, 0x79, 0xF5, 0xC7, 0x04, 0xBB,
		  0x91, 0x67, 0x9E, 0x5F, 0x81, 0x8C, 0xDB, 0x33, 0xDD, 0xA8, 0x4F, 0x2E, 0x72, 0xE3, 0xCF, 0x4E,
		  0x19, 0x24, 0xDE, 0x48, 0xB3, 0xDB, 0x22, 0x4A, 0xF6, 0x7C, 0x9A, 0xAE, 0x57, 0xCA, 0x52, 0x1F,
		  0xFA, 0x70, 0x8D, 0x08, 0x0A, 0xB2, 0x9B, 0x7D, 0x57, 0x23, 0x54, 0x7F, 0x9D, 0x55, 0xC0, 0x2F,
		  0x95, 0xCA, 0x7D, 0x71, 0x8C, 0x96, 0xEE, 0x06, 0x91, 0xDC, 0xD7, 0x58, 0xDB, 0x9E, 0x5A, 0xFD,
		  0x53, 0x1E, 0x23, 0xED, 0xF3, 0x76, 0x94, 0x6C, 0xD1, 0x50, 0xD5, 0x93, 0x07, 0x55, 0x5B, 0x34,
		  0x39, 0x52, 0x1F, 0xB4, 0xE4, 0xE8, 0x0F, 0x45, 0x29, 0x31, 0x35, 0xDF, 0xF7, 0xA8, 0xDE, 0x42,
		  0x48, 0x45, 0x1E, 0x81, 0x00, 0xCE, 0xB4, 0x4F, 0x10, 0x37, 0xEC, 0x7E, 0xF8, 0xBB, 0xD8, 0xFE,
		  0x07, 0x79, 0x0A, 0xE2, 0x37, 0x28, 0xFB, 0x1D, 0x40, 0xFA, 0x10, 0x71, 0x86, 0xC0, 0x8E, 0x63,
		  0xBA, 0x42, 0xFB, 0x9E, 0x06, 0x90, 0x38, 0xCE, 0x95, 0xFA, 0x43, 0x68, 0x69, 0xC3, 0x57, 0xB0,
		  0x95, 0xE3, 0x25, 0x37, 0x5E, 0xC5, 0x5B, 0x16, 0x5A, 0x4A, 0x54, 0x12, 0xC0, 0xA9, 0x67, 0x08,
		  0x2D, 0x64, 0xAD, 0x3C, 0x6C, 0x94, 0x6F, 0xC9, 0xE6, 0x77, 0x5B, 0x98, 0xB9, 0xA6, 0xF6, 0x50,
		  0xDA, 0xE1, 0x7D, 0x30, 0xC4, 0xA9, 0xA9, 0xC5, 0x3E, 0x65, 0x60, 0x6C, 0xBC, 0xD0, 0x2C, 0xF0,
		  0x70, 0x2D, 0xC3, 0xDB, 0x00, 0xBE, 0x02, 0x3C, 0xF6, 0x06, 0x41, 0xA8, 0x8E, 0x89, 0xE6, 0x95,
		  0x85, 0xD1, 0xF7, 0x80, 0xA3, 0x26, 0x7A, 0x1A, 0x04, 0xDB, 0xD7, 0x5A, 0xAB, 0xB3, 0xB6, 0x3D,
		  0x71, 0xAB, 0x7F, 0x79, 0xA0, 0xB0, 0x99, 0x12, 0x1D, 0x5B, 0xBE, 0xDD, 0x4F, 0x0A, 0x62, 0x75,
		  0xFA, 0x10, 0xA1, 0x75, 0x10, 0x66, 0x28, 0x15, 0x6E, 0x5F, 0x6D, 0xC8, 0x98, 0x50, 0x08, 0x51,
		  0x34, 0x49, 0x9A, 0xC5, 0x2E, 0xBE, 0xCF, 0x25, 0x5D, 0x6F, 0x1F, 0x1E, 0xCA, 0xE1, 0xF8, 0x0D, },
		//in
		{ 0x11, 0x73, 0x7F, 0x7B, 0x39, 0x67, 0x3B, 0xBA, 0xB2, 0x43, 0x4C, 0xBA, 0xDF, 0x69, 0x09, 0x51,
		  0x87, 0xDB, 0xA2, 0xF9, 0xE5, 0x33, 0x3B, 0x55, 0xA8, 0x19, 0xE8, 0x35, 0x45, 0xEC, 0x13, 0x0B,
		  0xD3, 0x69, 0x27, 0x26, 0x0C, 0xF0, 0x41, 0x94, 0x53, 0x0F, 0x18, 0xAC, 0x39, 0xF6, 0x5F, 0x41,
		  0x65, 0x30, 0x34, 0x21, 0x49, 0xAB, 0x84, 0x81, 0xC3, 0xD8, 0x9F, 0xED, 0x6C, 0x92, 0xEE, 0xAD,
		  0x60, 0x8A, 0x3A, 0x19, 0x72, 0x3B, 0x2D, 0x04, 0x6A, 0x1A, 0x11, 0x9F, 0x12, 0xEF, 0xB0, 0x6C,
		  0x71, 0x34, 0x07, 0xCE, 0x46, 0x84, 0x80, 0x44, 0x2A, 0x98, 0x85, 0x76, 0x11, 0x69, 0x7B, 0x4E,
		  0xE5, 0x17, 0x78, 0x72, 0x72, 0xD4, 0x2F, 0xCF, 0x1E, 0xD1, 0x15, 0x79, 0xF5, 0xC7, 0x04, 0xBB,
		  0x91, 0x67, 0x9E, 0x5F, 0x81, 0x8C, 0xDB, 0x33, 0xDD, 0xA8, 0x4F, 0x2E, 0x72, 0xE3, 0xCF, 0x4E,
		  0x19, 0x24, 0xDE, 0x48, 0xB3, 0xDB, 0x22, 0x4A, 0xF6, 0x7C, 0x9A, 0xAE, 0x57, 0xCA, 0x52, 0x1F,
		  0xFA, 0x70, 0x8D, 0x08, 0x0A, 0xB2, 0x9B, 0x7D, 0x57, 0x23, 0x54, 0x7F, 0x9D, 0x55, 0xC0, 0x2F,
		  0x95, 0xCA, 0x7D, 0x71, 0x8C, 0x96, 0xEE, 0x06, 0x91, 0xDC, 0xD7, 0x58, 0xDB, 0x9E, 0x5A, 0xFD,
		  0x53, 0x1E, 0x23, 0xED, 0xF3, 0x76, 0x94, 0x6C, 0xD1, 0x50, 0xD5, 0x93, 0x07, 0x55, 0x5B, 0x34,
		  0x39, 0x52, 0x1F, 0xB4, 0xE4, 0xE8, 0x0F, 0x45, 0x29, 0x31, 0x35, 0xDF, 0xF7, 0xA8, 0xDE, 0x42,
		  0x48, 0x45, 0x1E, 0x81, 0x00, 0xCE, 0xB4, 0x4F, 0x10, 0x37, 0xEC, 0x7E, 0xF8, 0xBB, 0xD8, 0xFE,
		  0x07, 0x79, 0x0A, 0xE2, 0x37, 0x28, 0xFB, 0x1D, 0x40, 0xFA, 0x10, 0x71, 0x86, 0xC0, 0x8E, 0x63,
		  0xBA, 0x42, 0xFB, 0x9E, 0x06, 0x90, 0x38, 0xCE, 0x95, 0xFA, 0x43, 0x68, 0x69, 0xC3, 0x57, 0xB0,
		  0x95, 0xE3, 0x25, 0x37, 0x5E, 0xC5, 0x5B, 0x16, 0x5A, 0x4A, 0x54, 0x12, 0xC0, 0xA9, 0x67, 0x08,
		  0x2D, 0x64, 0xAD, 0x3C, 0x6C, 0x94, 0x6F, 0xC9, 0xE6, 0x77, 0x5B, 0x98, 0xB9, 0xA6, 0xF6, 0x50,
		  0xDA, 0xE1, 0x7D, 0x30, 0xC4, 0xA9, 0xA9, 0xC5, 0x3E, 0x65, 0x60, 0x6C, 0xBC, 0xD0, 0x2C, 0xF0,
		  0x70, 0x2D, 0xC3, 0xDB, 0x00, 0xBE, 0x02, 0x3C, 0xF6, 0x06, 0x41, 0xA8, 0x8E, 0x89, 0xE6, 0x95,
		  0x85, 0xD1, 0xF7, 0x80, 0xA3, 0x26, 0x7A, 0x1A, 0x04, 0xDB, 0xD7, 0x5A, 0xAB, 0xB3, 0xB6, 0x3D,
		  0x71, 0xAB, 0x7F, 0x79, 0xA0, 0xB0, 0x99, 0x12, 0x1D, 0x5B, 0xBE, 0xDD, 0x4F, 0x0A, 0x62, 0x75,
		  0xFA, 0x10, 0xA1, 0x75, 0x10, 0x66, 0x28, 0x15, 0x6E, 0x5F, 0x6D, 0xC8, 0x98, 0x50, 0x08, 0x51,
		  0x34, 0x49, 0x9A, 0xC5, 0x2E, 0xBE, 0xCF, 0x25, 0x5D, 0x6F, 0x1F, 0x1E, 0xCA, 0xE1, 0xF8, 0x0D, },
		//out
		{ 0x1A, 0x7A, 0xD9, 0x9A, 0x20, 0x37, 0xB8, 0x70, 0x43, 0x12, 0xF6, 0x4A, 0xAD, 0xA7, 0xC8, 0x32,
		  0xDA, 0xBA, 0xB5, 0x25, 0x51, 0x2B, 0x8B, 0xA6, 0xA2, 0x36, 0xEF, 0xEF, 0x06, 0x53, 0x56, 0x95,
		  0x1B, 0xB1, 0xCC, 0x59, 0x20, 0x63, 0x55, 0x64, 0x6B, 0x0A, 0xBE, 0x36, 0xBA, 0xCC, 0xCB, 0xBB,
		  0xA0, 0x0E, 0x00, 0x8E, 0x00, 0x12, 0xBF, 0x67, 0xEE, 0xB5, 0x77, 0xDE, 0x03, 0x88, 0x3C, 0x17,
		  0x9B, 0xAB, 0xEB, 0x2F, 0x36, 0x3C, 0xB9, 0x54, 0x65, 0x1E, 0xFC, 0xCF, 0x41, 0x5C, 0x76, 0x69,
		  0x78, 0x64, 0x1B, 0xB0, 0x46, 0x2A, 0xC0, 0x0A, 0x68, 0x24, 0xD8, 0xF3, 0xF9, 0xA0, 0x02, 0x0A,
		  0xC8, 0x54, 0x24, 0x40, 0x47, 0xC8, 0x9C, 0x5E, 0xA6, 0xBC, 0xA3, 0xD1, 0x4F, 0x10, 0xCA, 0x98,
		  0xF1, 0xB8, 0x72, 0xD9, 0x73, 0x8C, 0x48, 0x44, 0x73, 0xDD, 0xE0, 0x35, 0x5E, 0x04, 0x1F, 0x39,
		  0x38, 0xF9, 0x66, 0x6B, 0xAE, 0xDD, 0x7E, 0x64, 0x83, 0xA5, 0x1A, 0x2F, 0xCB, 0x81, 0x0F, 0xE2,
		  0x4C, 0x04, 0x4F, 0x4C, 0xE7, 0x0F, 0xE6, 0xC0, 0xEC, 0xEC, 0x9B, 0x90, 0xAA, 0xA9, 0xA3, 0x84,
		  0x5D, 0xB6, 0x5C, 0x17, 0xCC, 0xFC, 0xCA, 0x9D, 0xD1, 0x6E, 0x98, 0x62, 0x61, 0x83, 0x61, 0x62,
		  0xA0, 0x5A, 0x40, 0x06, 0x49, 0x2C, 0x01, 0x4A, 0xB8, 0x68, 0x90, 0x1C, 0x95, 0x5D, 0x8D, 0x9B,
		  0x99, 0x1E, 0x4D, 0xF5, 0x70, 0x6A, 0x27, 0xDB, 0xAD, 0x96, 0x45, 0x02, 0xA1, 0x26, 0x76, 0x03,
		  0x28, 0x61, 0xC6, 0x93, 0x3D, 0x70, 0x81, 0xD9, 0xE4, 0x6C, 0x96, 0x8E, 0xF6, 0x1A, 0xA3, 0xEF,
		  0x19, 0x83, 0x4B, 0xC3, 0x68, 0x62, 0x2D, 0x78, 0xD5, 0xF7, 0x68, 0x88, 0x82, 0x59, 0xDC, 0x84,
		  0x95, 0x0F, 0x29, 0xA6, 0xD4, 0x1C, 0x78, 0x82, 0x2B, 0x96, 0xC8, 0x95, 0x3B, 0xB3, 0x03, 0xDD,
		  0x97, 0x2D, 0xC5, 0xC4, 0xD5, 0xB1, 0xB7, 0x52, 0x47, 0x2D, 0xCC, 0x55, 0xAD, 0xAD, 0x43, 0x46,
		  0x7A, 0xA2, 0x3B, 0x3D, 0x5C, 0x42, 0x5E, 0xE0, 0xAE, 0x87, 0x34, 0xB0, 0x63, 0xB0, 0xF3, 0x10,
		  0xDC, 0xC7, 0x76, 0x4D, 0xE0, 0x5D, 0x7A, 0xB4, 0xC4, 0xAC, 0x54, 0x8F, 0x7B, 0x6A, 0x38, 0x86,
		  0xE6, 0x7E, 0x63, 0x9D, 0x5F, 0x1F, 0x96, 0xB0, 0xC2, 0x40, 0x02, 0xE6, 0x15, 0xF1, 0xE3, 0xDC,
		  0x0E, 0x23, 0xC4, 0x35, 0xA1, 0x70, 0x89, 0x0D, 0xC5, 0x63, 0x7C, 0xE9, 0x8A, 0x40, 0x5D, 0xB4,
		  0x4C, 0x7A, 0x86, 0x1F, 0x0B, 0x2E, 0x79, 0x2A, 0x0B, 0x2E, 0x5A, 0x31, 0x7A, 0xB6, 0xC0, 0x96,
		  0x1A, 0xB7, 0xDA, 0x88, 0xCF, 0x99, 0x3A, 0xC9, 0x18, 0x6F, 0x41, 0x0A, 0xCA, 0x65, 0x4A, 0x13,
		  0x60, 0xCE, 0x95, 0x34, 0x49, 0x07, 0x6A, 0xD1, 0xB7, 0x92, 0xDB, 0x29, 0xF3, 0xF1, 0x57, 0x18, },
	},

	{ //4096
		512,
		//n
		{ 0x75, 0x55, 0x2F, 0xF8, 0x78, 0x92, 0x38, 0xAA, 0xE6, 0xE0, 0x87, 0x4B, 0xB1, 0xFC, 0x3B, 0x91,
		  0x54, 0x0B, 0x04, 0xC2, 0xBC, 0x31, 0xE2, 0xB7, 0x5B, 0x05, 0x22, 0x22, 0x7C, 0x02, 0x72, 0x9E,
		  0xD1, 0x3E, 0x5C, 0x60, 0x02, 0xB5, 0xDE, 0xD2, 0x56, 0xC6, 0xDF, 0x49, 0x33, 0x5B, 0xA4, 0x1E,
		  0x89, 0xAD, 0x5F, 0xF0, 0x6D, 0x61, 0xEC, 0x0B, 0xDE, 0x55, 0xAA, 0x21, 0xFC, 0x13, 0x95, 0xC5,
		  0x65, 0x66, 0x7A, 0xCE, 0x89, 0x2D, 0xBB, 0x4E, 0x6B, 0x71, 0xED, 0xC8, 0xC6, 0x35, 0xB1, 0xB4,
		  0x7B, 0xE5, 0xA7, 0xEB, 0x36, 0xE6, 0x20, 0x7A, 0x6E, 0xFE, 0xDF, 0x06, 0x5C, 0xB1, 0xB3, 0x8A,
		  0x68, 0x35, 0x71, 0x50, 0xD2, 0x5B, 0x50, 0xBA, 0x45, 0x6D, 0xB6, 0xDC, 0xA7, 0x76, 0xF8, 0xAF,
		  0x4B, 0xF0, 0x29, 0xC1, 0xBA, 0x9A, 0xEE, 0x76, 0xFF, 0xBB, 0xBB, 0x43, 0x75, 0x26, 0x57, 0xB7,
		  0x66, 0x49, 0x94, 0xCA, 0x42, 0xF3, 0x20, 0xD7, 0xAE, 0xBF, 0x02, 0x79, 0x51, 0x4C, 0x16, 0x46,
		  0x48, 0xF3, 0x9E, 0xCC, 0x99, 0x62, 0x96, 0xEF, 0x24, 0x8F, 0xBD, 0x93, 0x97, 0xD1, 0xEF, 0x79,
		  0x69, 0xE5, 0xAE, 0x07, 0x83, 0x16, 0xFE, 0x38, 0x53, 0xD1, 0x3E, 0x52, 0x9E, 0x36, 0xD2, 0x41,
		  0xA9, 0x62, 0xC4, 0xB5, 0x90, 0x1A, 0x23, 0x2A, 0x05, 0x29, 0x5F, 0x64, 0xF2, 0x41, 0xFD, 0xDD,
		  0xE7, 0x98, 0xDA, 0xBA, 0x38, 0x2A, 0xB4, 0x0F, 0x89, 0xCC, 0xDA, 0x0B, 0x7D, 0x8C, 0x1A, 0xCE,
		  0x50, 0x84, 0x42, 0x2E, 0xBC, 0xD8, 0x77, 0x2D, 0x0C, 0xD5, 0x39, 0xFC, 0xE3, 0x71, 0xB6, 0xFA,
		  0x6D, 0xD0, 0xE1, 0xBE, 0x9C, 0x0A, 0x2C, 0x99, 0x85, 0x05, 0x24, 0xE0, 0xB6, 0x22, 0x82, 0x3A,
		  0x5A, 0xD1, 0xD1, 0x16, 0x97, 0x97, 0x2C, 0xDF, 0x7A, 0xB5, 0x6F, 0x10, 0x08, 0x02, 0x91, 0x36,
		  0x20, 0x70, 0x45, 0xDF, 0x2B, 0xC2, 0xD4, 0xF8, 0x21, 0xD2, 0xB4, 0x5E, 0x9A, 0x70, 0xB8, 0x21,
		  0xEC, 0xDD, 0x5D, 0x72, 0xE5, 0x0E, 0x38, 0xB5, 0x9E, 0x6C, 0x39, 0x96, 0x4B, 0x9A, 0x36, 0x15,
		  0xFE, 0x70, 0x7C, 0x07, 0xEB, 0xF6, 0x22, 0xDD, 0x69, 0x48, 0x3D, 0xC3, 0x5D, 0xF2, 0xC7, 0xD6,
		  0x34, 0x0D, 0x37, 0x76, 0xD5, 0x26, 0xB7, 0x43, 0x5D, 0x25, 0x7D, 0x11, 0x42, 0x1D, 0x95, 0xD0,
		  0x0A, 0x47, 0xDE, 0xFB, 0xC6, 0x58, 0x02, 0x6B, 0xAD, 0x28, 0xE7, 0x86, 0xE3, 0x4A, 0x0C, 0x3F,
		  0xC0, 0xD1, 0x75, 0x12, 0x13, 0x91, 0x07, 0xE9, 0x22, 0x93, 0x1C, 0xD0, 0xC7, 0x6C, 0x88, 0x50,
		  0xD1, 0x32, 0xF1, 0xA8, 0x4C, 0x6E, 0xBE, 0x32, 0x76, 0x8B, 0xA6, 0x9B, 0xCF, 0xB1, 0x5B, 0x3B,
		  0xB6, 0x18, 0xE8, 0xFA, 0x34, 0xCD, 0x24, 0x4A, 0xA7, 0x7B, 0x3A, 0x9B, 0x51, 0x15, 0x75, 0xE6,
		  0xF2, 0x4C, 0xDE, 0x77, 0xC6, 0x0F, 0x49, 0x7A, 0x3C, 0x1F, 0x34, 0x72, 0x58, 0x12, 0x63, 0xA9,
		  0x48, 0x32, 0x84, 0x25, 0x30, 0x4C, 0x98, 0x5B, 0xAE, 0x29, 0x4F, 0xED, 0xE9, 0x9B, 0x43, 0x58,
		  0x5E, 0xAF, 0x29, 0x48, 0xC6, 0xA4, 0xC2, 0x1E, 0xDC, 0xEC, 0xC6, 0x21, 0xC0, 0x10, 0x89, 0xDA,
		  0xED, 0x21, 0x80, 0xD6, 0x15, 0xF9, 0x24, 0xCA, 0x67, 0x09, 0xCE, 0x4B, 0xAA, 0x99, 0xBC, 0x74,
		  0xAB, 0x9C, 0xB2, 0x5F, 0xCB, 0x88, 0xC1, 0x75, 0x87, 0xAB, 0x56, 0x27, 0x51, 0x4D, 0x34, 0x3F,
		  0xB4, 0xB9, 0x81, 0x58, 0xDF, 0xDD, 0x24, 0x45, 0xE9, 0xD6, 0x20, 0x1F, 0xD2, 0x61, 0x5C, 0x26,
		  0x93, 0xE5, 0x7B, 0x58, 0xE2, 0xD1, 0x1E, 0x7D, 0x5B, 0xBC, 0x02, 0xDD, 0x26, 0xC2, 0x7B, 0xFF,
		  0x71, 0x52, 0xC2, 0xFA, 0x08, 0xCE, 0x9E, 0x7A, 0xCB, 0xD5, 0xE2, 0x2E, 0xD4, 0x1B, 0x64, 0xB7, },
		//e
		{ 0x00, 0x01, 0x00, 0x01, },
		//d
		{ 0x2C, 0xC3, 0x04, 0xFB, 0xFB, 0xB3, 0x7C, 0xDE, 0xE6, 0x19, 0x7E, 0x44, 0x08, 0x70, 0xBB, 0xA0,
		  0xE3, 0xB9, 0x18, 0x65, 0xDA, 0x3A, 0x05, 0xCE, 0x01, 0x71, 0x61, 0xE6, 0x59, 0xFC, 0xED, 0x11,
		  0x5D, 0xAE, 0x36, 0xBB, 0x82, 0x0D, 0x34, 0x26, 0x76, 0x68, 0x84, 0x42, 0x7E, 0xCF, 0x55, 0x3B,
		  0x39, 0x36, 0xE5, 0x44, 0xE9, 0xD5, 0xD3, 0xA1, 0x6B, 0x7E, 0xAE, 0xDB, 0x2C, 0x39, 0xA4, 0x87,
		  0x9B, 0xF9, 0x8E, 0x9C, 0x40, 0x85, 0x2B, 0xD1, 0xEC, 0xF7, 0x97, 0xC9, 0x62, 0xA4, 0x95, 0x58,
		  0xCF, 0x73, 0x7B, 0xAE, 0x26, 0x51, 0x80, 0xCE, 0x74, 0x8D, 0xD3, 0x33, 0xB0, 0x25, 0x32, 0xE3,
		  0x78, 0x81, 0xFA, 0xEA, 0xE4, 0x75, 0x65, 0xC4, 0xCA, 0x3B, 0xE2, 0xE9, 0x27, 0x12, 0x22, 0x29,
		  0x6E, 0x04, 0xFF, 0x49, 0x23, 0x11, 0x7C, 0x2B, 0xF5, 0xBF, 0xFE, 0xDE, 0xEB, 0x50, 0x67, 0x62,
		  0x56, 0x29, 0x78, 0x13, 0xF9, 0x9A, 0x9B, 0x4A, 0xED, 0x25, 0x7D, 0xA2, 0x1E, 0xBB, 0xB2, 0x3B,
		  0xBA, 0x15, 0x06, 0xDD, 0xF3, 0x1E, 0x43, 0x8A, 0x94, 0x1E, 0x2A, 0x2A, 0xA6, 0x5E, 0xB6, 0xC7,
		  0x50, 0xF9, 0x08, 0x7D, 0x61, 0x2B, 0x62, 0x6C, 0xC6, 0xBD, 0x2A, 0xD3, 0x85, 0xFC, 0x50, 0x16,
		  0x30, 0xB2, 0xB7, 0x6C, 0xB4, 0xBE, 0xE3, 0xEF, 0x61, 0xEC, 0xB8, 0xB1, 0xE0, 0x22, 0x00, 0xE1,
		  0xA9, 0x3B, 0x0D, 0x26, 0xC1, 0xCA, 0xB8, 0xCA, 0xBC, 0xBD, 0x63, 0xE9, 0xC2, 0x49, 0xB2, 0xE8,
		  0x46, 0x9B, 0x4E, 0x4C, 0x5A, 0x4B, 0x12, 0x9C, 0x23, 0x2B, 0x2D, 0x66, 0x26, 0xB6, 0xF9, 0x21,
		  0x6C, 0xC7, 0xA5, 0x77, 0x7C, 0x3B, 0xFD, 0x6B, 0xCB, 0xED, 0x7C, 0x76, 0x25, 0xC5, 0xE0, 0x7C,
		  0xB6, 0xAD, 0x18, 0xE1, 0x4F, 0x8F, 0xA2, 0xD4, 0xD7, 0x11, 0x64, 0x7F, 0x6F, 0x2E, 0xDB, 0x8A,
		  0x8B, 0x88, 0xD0, 0xB4, 0xC5, 0xCB, 0xB4, 0xCB, 0x10, 0xD1, 0xBD, 0x55, 0x9D, 0x46, 0x6C, 0x94,
		  0x6A, 0x1F, 0x17, 0x60, 0x6E, 0x24, 0xFA, 0x84, 0xED, 0x7C, 0x69, 0xBD, 0x8E, 0x7F, 0x28, 0x6A,
		  0x62, 0x67, 0xB1, 0x7E, 0x5C, 0xC1, 0x17, 0x37, 0x01, 0xBC, 0xFD, 0x99, 0xBA, 0xC8, 0x68, 0x85,
		  0xCB, 0xFC, 0x5B, 0x38, 0x61, 0x72, 0x6E, 0x71, 0x5F, 0xA3, 0xBD, 0x98, 0x05, 0x0A, 0xB2, 0x3A,
		  0x11, 0x8F, 0x94, 0x12, 0x01, 0x11, 0x41, 0xED, 0x83, 0xCE, 0x04, 0x69, 0x20, 0x7D, 0x30, 0xEC,
		  0xB8, 0xAC, 0x74, 0x90, 0x0A, 0x27, 0x85, 0xA9, 0x92, 0x19, 0x2A, 0xF2, 0x0E, 0xD3, 0x6D, 0xCF,
		  0x6B, 0xF4, 0xBE, 0x74, 0x15, 0xF1, 0xEE, 0x5E, 0x97, 0x22, 0xA9, 0x28, 0x47, 0x08, 0x3E, 0xB3,
		  0x9C, 0xF3, 0xD8, 0xBC, 0xB2, 0xD2, 0xE4, 0xDD, 0xE4, 0x71, 0xF5, 0x1D, 0x2F, 0x26, 0x52, 0xEB,
		  0x34, 0x96, 0x44, 0x95, 0x39, 0x3E, 0xF7, 0x5E, 0x07, 0x8A, 0x1D, 0x47, 0x89, 0x61, 0x2B, 0xC9,
		  0x69, 0x8A, 0x48, 0x64, 0x51, 0x3C, 0xC9, 0x6A, 0x4E, 0xEF, 0xDB, 0xA8, 0x57, 0x55, 0x6D, 0x5B,
		  0xF4, 0x5E, 0x85, 0x41, 0x1D, 0x1C, 0xC3, 0x2B, 0xF9, 0x59, 0x74, 0x52, 0x79, 0x4B, 0x56, 0xAF,
		  0xC2, 0x25, 0x43, 0x9D, 0xB0, 0xE3, 0x58, 0x0B, 0xAC, 0xC6, 0x2A, 0x3F, 0x1E, 0xDF, 0xD0, 0x8D,
		  0x5A, 0x67, 0xEE, 0xD7, 0x3C, 0x78, 0x06, 0xFE, 0xD7, 0xE4, 0x7E, 0xA1, 0x1A, 0x3B, 0xC2, 0xB3,
		  0x5A, 0x30, 0x41, 0xA4, 0x25, 0xD2, 0x56, 0x62, 0x0A, 0x49, 0xB0, 0x91, 0x11, 0xB2, 0x08, 0x04,
		  0xC6, 0x24, 0x80, 0x85, 0x30, 0xEE, 0xA9, 0xC0, 0xB6, 0xB5, 0xF5, 0xC9, 0x9F, 0x02, 0xE5, 0x67,
		  0x32, 0x22, 0x60, 0x34, 0x32, 0x4D, 0x31, 0x8F, 0x3D, 0x9A, 0xF0, 0xB8, 0x92, 0x23, 0x6A, 0xF1, },
		//in
		{ 0x2C, 0xC3, 0x04, 0xFB, 0xFB, 0xB3, 0x7C, 0xDE, 0xE6, 0x19, 0x7E, 0x44, 0x08, 0x70, 0xBB, 0xA0,
		  0xE3, 0xB9, 0x18, 0x65, 0xDA, 0x3A, 0x05, 0xCE, 0x01, 0x71, 0x61, 0xE6, 0x59, 0xFC, 0xED, 0x11,
		  0x5D, 0xAE, 0x36, 0xBB, 0x82, 0x0D, 0x34, 0x26, 0x76, 0x68, 0x84, 0x42, 0x7E, 0xCF, 0x55, 0x3B,
		  0x39, 0x36, 0xE5, 0x44, 0xE9, 0xD5, 0xD3, 0xA1, 0x6B, 0x7E, 0xAE, 0xDB, 0x2C, 0x39, 0xA4, 0x87,
		  0x9B, 0xF9, 0x8E, 0x9C, 0x40, 0x85, 0x2B, 0xD1, 0xEC, 0xF7, 0x97, 0xC9, 0x62, 0xA4, 0x95, 0x58,
		  0xCF, 0x73, 0x7B, 0xAE, 0x26, 0x51, 0x80, 0xCE, 0x74, 0x8D, 0xD3, 0x33, 0xB0, 0x25, 0x32, 0xE3,
		  0x78, 0x81, 0xFA, 0xEA, 0xE4, 0x75, 0x65, 0xC4, 0xCA, 0x3B, 0xE2, 0xE9, 0x27, 0x12, 0x22, 0x29,
		  0x6E, 0x04, 0xFF, 0x49, 0x23, 0x11, 0x7C, 0x2B, 0xF5, 0xBF, 0xFE, 0xDE, 0xEB, 0x50, 0x67, 0x62,
		  0x56, 0x29, 0x78, 0x13, 0xF9, 0x9A, 0x9B, 0x4A, 0xED, 0x25, 0x7D, 0xA2, 0x1E, 0xBB, 0xB2, 0x3B,
		  0xBA, 0x15, 0x06, 0xDD, 0xF3, 0x1E, 0x43, 0x8A, 0x94, 0x1E, 0x2A, 0x2A, 0xA6, 0x5E, 0xB6, 0xC7,
		  0x50, 0xF9, 0x08, 0x7D, 0x61, 0x2B, 0x62, 0x6C, 0xC6, 0xBD, 0x2A, 0xD3, 0x85, 0xFC, 0x50, 0x16,
		  0x30, 0xB2, 0xB7, 0x6C, 0xB4, 0xBE, 0xE3, 0xEF, 0x61, 0xEC, 0xB8, 0xB1, 0xE0, 0x22, 0x00, 0xE1,
		  0xA9, 0x3B, 0x0D, 0x26, 0xC1, 0xCA, 0xB8, 0xCA, 0xBC, 0xBD, 0x63, 0xE9, 0xC2, 0x49, 0xB2, 0xE8,
		  0x46, 0x9B, 0x4E, 0x4C, 0x5A, 0x4B, 0x12, 0x9C, 0x23, 0x2B, 0x2D, 0x66, 0x26, 0xB6, 0xF9, 0x21,
		  0x6C, 0xC7, 0xA5, 0x77, 0x7C, 0x3B, 0xFD, 0x6B, 0xCB, 0xED, 0x7C, 0x76, 0x25, 0xC5, 0xE0, 0x7C,
		  0xB6, 0xAD, 0x18, 0xE1, 0x4F, 0x8F, 0xA2, 0xD4, 0xD7, 0x11, 0x64, 0x7F, 0x6F, 0x2E, 0xDB, 0x8A,
		  0x8B, 0x88, 0xD0, 0xB4, 0xC5, 0xCB, 0xB4, 0xCB, 0x10, 0xD1, 0xBD, 0x55, 0x9D, 0x46, 0x6C, 0x94,
		  0x6A, 0x1F, 0x17, 0x60, 0x6E, 0x24, 0xFA, 0x84, 0xED, 0x7C, 0x69, 0xBD, 0x8E, 0x7F, 0x28, 0x6A,
		  0x62, 0x67, 0xB1, 0x7E, 0x5C, 0xC1, 0x17, 0x37, 0x01, 0xBC, 0xFD, 0x99, 0xBA, 0xC8, 0x68, 0x85,
		  0xCB, 0xFC, 0x5B, 0x38, 0x61, 0x72, 0x6E, 0x71, 0x5F, 0xA3, 0xBD, 0x98, 0x05, 0x0A, 0xB2, 0x3A,
		  0x11, 0x8F, 0x94, 0x12, 0x01, 0x11, 0x41, 0xED, 0x83, 0xCE, 0x04, 0x69, 0x20, 0x7D, 0x30, 0xEC,
		  0xB8, 0xAC, 0x74, 0x90, 0x0A, 0x27, 0x85, 0xA9, 0x92, 0x19, 0x2A, 0xF2, 0x0E, 0xD3, 0x6D, 0xCF,
		  0x6B, 0xF4, 0xBE, 0x74, 0x15, 0xF1, 0xEE, 0x5E, 0x97, 0x22, 0xA9, 0x28, 0x47, 0x08, 0x3E, 0xB3,
		  0x9C, 0xF3, 0xD8, 0xBC, 0xB2, 0xD2, 0xE4, 0xDD, 0xE4, 0x71, 0xF5, 0x1D, 0x2F, 0x26, 0x52, 0xEB,
		  0x34, 0x96, 0x44, 0x95, 0x39, 0x3E, 0xF7, 0x5E, 0x07, 0x8A, 0x1D, 0x47, 0x89, 0x61, 0x2B, 0xC9,
		  0x69, 0x8A, 0x48, 0x64, 0x51, 0x3C, 0xC9, 0x6A, 0x4E, 0xEF, 0xDB, 0xA8, 0x57, 0x55, 0x6D, 0x5B,
		  0xF4, 0x5E, 0x85, 0x41, 0x1D, 0x1C, 0xC3, 0x2B, 0xF9, 0x59, 0x74, 0x52, 0x79, 0x4B, 0x56, 0xAF,
		  0xC2, 0x25, 0x43, 0x9D, 0xB0, 0xE3, 0x58, 0x0B, 0xAC, 0xC6, 0x2A, 0x3F, 0x1E, 0xDF, 0xD0, 0x8D,
		  0x5A, 0x67, 0xEE, 0xD7, 0x3C, 0x78, 0x06, 0xFE, 0xD7, 0xE4, 0x7E, 0xA1, 0x1A, 0x3B, 0xC2, 0xB3,
		  0x5A, 0x30, 0x41, 0xA4, 0x25, 0xD2, 0x56, 0x62, 0x0A, 0x49, 0xB0, 0x91, 0x11, 0xB2, 0x08, 0x04,
		  0xC6, 0x24, 0x80, 0x85, 0x30, 0xEE, 0xA9, 0xC0, 0xB6, 0xB5, 0xF5, 0xC9, 0x9F, 0x02, 0xE5, 0x67,
		  0x32, 0x22, 0x60, 0x34, 0x32, 0x4D, 0x31, 0x8F, 0x3D, 0x9A, 0xF0, 0xB8, 0x92, 0x23, 0x6A, 0xF1, },
		//out
		{ 0x28, 0x38, 0x67, 0xE9, 0x39, 0x91, 0xF5, 0xEE, 0x77, 0x78, 0x99, 0xA6, 0x47, 0x82, 0x64, 0xC4,
		  0x37, 0x62, 0xBD, 0xB5, 0xC8, 0x12, 0xDB, 0xE3, 0x1E, 0xC3, 0xA2, 0xB9, 0xF1, 0xA7, 0xD3, 0xB1,
		  0x1C, 0xAD, 0x9E, 0xDF, 0x6C, 0xCE, 0xE6, 0x7C, 0xD0, 0x7F, 0xBD, 0xE0, 0x7A, 0x94, 0x8D, 0xA0,
		  0xFF, 0x5C, 0x96, 0x34, 0x86, 0xB4, 0xD7, 0x1B, 0x1E, 0xAF, 0x55, 0x44, 0x92, 0x23, 0x14, 0x11,
		  0xF5, 0x0A, 0xA0, 0xF6, 0x54, 0xB9, 0x40, 0x57, 0x79, 0x99, 0x9C, 0x32, 0x54, 0x32, 0xB6, 0x65,
		  0x8D, 0x0D, 0x11, 0x5A, 0x50, 0xD8, 0xDA, 0x8C, 0xCC, 0x67, 0x61, 0xAB, 0xD0, 0xD7, 0xE5, 0x4F,
		  0xA3, 0x04, 0x22, 0x6C, 0x51, 0xE0, 0x4C, 0x25, 0x16, 0x50, 0x42, 0x14, 0x8B, 0xE4, 0xE6, 0xEB,
		  0x94, 0xB4, 0x9F, 0x2D, 0x46, 0x98, 0x84, 0x62, 0xD6, 0x5E, 0xA4, 0x23, 0x51, 0x40, 0xF2, 0xF9,
		  0xB5, 0x53, 0x74, 0x13, 0x0B, 0xEF, 0xC6, 0x71, 0x42, 0x99, 0xA7, 0xDB, 0xC1, 0xED, 0xA9, 0xB3,
		  0x55, 0x06, 0xFA, 0xE1, 0x31, 0x02, 0xEF, 0xD8, 0x9D, 0xEA, 0xDE, 0x65, 0x66, 0x69, 0x44, 0x39,
		  0x0C, 0x37, 0xB1, 0xEA, 0x23, 0xA5, 0x6E, 0xB4, 0xDE, 0x2F, 0xE4, 0x0C, 0x1A, 0x40, 0xA1, 0xE2,
		  0xA1, 0x25, 0x35, 0xF3, 0xCD, 0x47, 0x83, 0x6F, 0x41, 0xE6, 0xED, 0x71, 0x6A, 0x63, 0x7A, 0x10,
		  0x28, 0x0B, 0xAB, 0xB2, 0xCF, 0x1D, 0x20, 0xD1, 0x78, 0x29, 0x76, 0xE6, 0x43, 0x62, 0x69, 0xCB,
		  0x0A, 0x00, 0x33, 0x41, 0xE8, 0x00, 0x4E, 0x89, 0x53, 0x9D, 0xD0, 0x35, 0xDF, 0x5B, 0xAF, 0x16,
		  0x6A, 0xDF, 0x8F, 0xEE, 0xE7, 0x01, 0xC7, 0x00, 0x23, 0xA5, 0x5A, 0x65, 0xF7, 0xC7, 0xAA, 0x75,
		  0xB1, 0xB0, 0x6D, 0xC4, 0x5E, 0xCD, 0x27, 0x27, 0x3B, 0xF6, 0x85, 0xFF, 0xE7, 0xD5, 0xCE, 0xE5,
		  0xF9, 0x16, 0x2D, 0x1C, 0xB6, 0xEE, 0x5E, 0x0C, 0x8F, 0x6A, 0x9F, 0x96, 0xA4, 0x72, 0x2E, 0x99,
		  0xF9, 0x0D, 0x28, 0xA3, 0xBB, 0xBE, 0xE1, 0x3A, 0xEE, 0x44, 0x1A, 0xA5, 0x58, 0xE5, 0x5E, 0x1A,
		  0x38, 0x58, 0x34, 0xE9, 0xB4, 0x52, 0xA1, 0x10, 0x8A, 0xE9, 0x21, 0x5C, 0x33, 0xA3, 0xD5, 0x60,
		  0xED, 0x8D, 0x40, 0xDA, 0x84, 0x3F, 0x08, 0xFC, 0x86, 0x29, 0x45, 0x03, 0x40, 0xD3, 0xC4, 0xDB,
		  0xC4, 0x5F, 0x1C, 0x3F, 0x29, 0xC8, 0xA3, 0xCA, 0x2F, 0xFE, 0x06, 0xA9, 0x79, 0xDA, 0x45, 0x68,
		  0x8B, 0x9C, 0x77, 0xCE, 0xD5, 0xBD, 0xA7, 0x68, 0x05, 0x41, 0x8F, 0xD2, 0xA5, 0x26, 0x51, 0x70,
		  0xF3, 0x84, 0xA9, 0xF2, 0x9F, 0x04, 0x70, 0x49, 0x3A, 0xB7, 0x42, 0xC1, 0x17, 0xFF, 0x26, 0xA1,
		  0x49, 0xD7, 0x4E, 0xDE, 0xBE, 0x1E, 0x7B, 0x20, 0x28, 0xAB, 0x8A, 0x9F, 0xEB, 0x1F, 0x4E, 0x03,
		  0xA9, 0xFA, 0x01, 0x25, 0xDA, 0xA0, 0xA3, 0x3C, 0xBA, 0xAF, 0x5C, 0x89, 0x5C, 0x6B, 0x17, 0xBB,
		  0xE5, 0xEB, 0x13, 0xA7, 0xAA, 0x23, 0xEC, 0x29, 0xC9, 0x43, 0xA1, 0x72, 0x1D, 0x8E, 0xC6, 0x36,
		  0xFF, 0x26, 0xE1, 0x93, 0x73, 0xB8, 0x41, 0x45, 0x2A, 0x12, 0xD0, 0x43, 0x53, 0x73, 0x13, 0x40,
		  0xC3, 0xEF, 0x65, 0xEA, 0x24, 0xC8, 0x3E, 0x1C, 0x6B, 0xD3, 0x6A, 0x4C, 0x8D, 0x8C, 0x49, 0xDE,
		  0xF5, 0x19, 0x5A, 0x11, 0xCF, 0x50, 0x34, 0x62, 0x54, 0xBC, 0x85, 0xD5, 0x2E, 0x2A, 0x80, 0xD6,
		  0x65, 0xF7, 0xC4, 0x98, 0x90, 0x5E, 0x0A, 0xA3, 0x37, 0x6A, 0x21, 0xC8, 0x51, 0xF2, 0x57, 0xFC,
		  0xD7, 0x32, 0xF0, 0x74, 0x84, 0x62, 0xA6, 0x80, 0x90, 0x58, 0x7D, 0xB8, 0x67, 0x11, 0xF8, 0x23,
		  0xDB, 0x4B, 0xA8, 0xC1, 0x1D, 0x4F, 0xAB, 0xF2, 0x7E, 0x34, 0xA6, 0xE7, 0x0E, 0xC0, 0xF4, 0x21, },
	},
};
sprd_crypto_err_t
sprd_rsa_test_enc (void) {
	sprd_crypto_err_t err;
	int32_t i;
	uint8_t out_temp[512];
	sprd_rsa_pubkey_t pub_key;
	sprd_rsa_padding_t padding;

	for (i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++) {
		pub_key.n = tests[i].key_n;
		pub_key.n_len = tests[i].data_len;
		pub_key.e = tests[i].key_e;
		pub_key.e_len = 4;
		padding.type = SPRD_RSA_NOPAD;
		err = sprd_rsa_public_encrypt(&pub_key,
				tests[i].din, tests[i].data_len,
				out_temp, NULL,
				padding);
		if (err != SPRD_CRYPTO_SUCCESS
			|| sprd_pal_memcmp(out_temp, tests[i].dout, tests[i].data_len) != 0) {
			SPRD_CRYPTO_LOG_DEBUG("test[%d] FAILED\n", i);
			return SPRD_CRYPTO_ERR_RESULT;
		}
	}

	return SPRD_CRYPTO_SUCCESS;
}

sprd_crypto_err_t
sprd_rsa_test_dec (void) {
	sprd_crypto_err_t err;
	int32_t i;
	uint8_t in_temp[512];
	sprd_rsa_keypair_t priv_key;
	sprd_rsa_padding_t padding;

	for (i = 0; i < (int)(sizeof(tests) / sizeof(tests[0])); i++) {
		priv_key.n = tests[i].key_n;
		priv_key.n_len = tests[i].data_len;
		priv_key.d = tests[i].key_d;
		priv_key.d_len = tests[i].data_len;
		padding.type = SPRD_RSA_NOPAD;
		err = sprd_rsa_private_decrypt(&priv_key,
				tests[i].dout, tests[i].data_len,
				in_temp, NULL,
				padding);
		if (err != SPRD_CRYPTO_SUCCESS
			|| sprd_pal_memcmp(in_temp, tests[i].din, tests[i].data_len) != 0) {
			SPRD_CRYPTO_LOG_DEBUG("test[%d] FAILED\n", i);
			return SPRD_CRYPTO_ERR_RESULT;
		}
	}

	return SPRD_CRYPTO_SUCCESS;
}

sprd_crypto_err_t
sprd_rsa_test_key_gen (void) {
	sprd_crypto_err_t err;
	int32_t i;
	uint8_t temp[512];
	sprd_rsa_pubkey_t pub_key;
	sprd_rsa_keypair_t priv_key;
	sprd_rsa_padding_t padding;

	for (i = 1; i < (int)(sizeof(tests) / sizeof(tests[0])); i++) {
		temp[0] = tests[i].key_e[3];
		temp[1] = tests[i].key_e[2];
		temp[2] = tests[i].key_e[1];
		temp[3] = tests[i].key_e[0];

		err = sprd_rsa_key_gen(temp, 4,
				tests[i].data_len,
				tests[i].key_n, tests[i].key_d);

		pub_key.n = tests[i].key_n;
		pub_key.n_len = tests[i].data_len;
		pub_key.e = tests[i].key_e;
		pub_key.e_len = 4;
		padding.type = SPRD_RSA_NOPAD;
		err |= sprd_rsa_public_encrypt(&pub_key,
				tests[i].din, tests[i].data_len,
				temp, NULL,
				padding);

		priv_key.n = tests[i].key_n;
		priv_key.n_len = tests[i].data_len;
		priv_key.d = tests[i].key_d;
		priv_key.d_len = tests[i].data_len;
		padding.type = SPRD_RSA_NOPAD;
		err |= sprd_rsa_private_decrypt(&priv_key,
				temp, tests[i].data_len,
				tests[i].dout, NULL,
				padding);

		if (err != SPRD_CRYPTO_SUCCESS
			|| sprd_pal_memcmp(tests[i].dout, tests[i].din, tests[i].data_len) != 0) {
			SPRD_CRYPTO_LOG_DEBUG("test[%d] FAILED\n", i);
			return SPRD_CRYPTO_ERR_RESULT;
		}
	}

	return SPRD_CRYPTO_SUCCESS;
}

sprd_crypto_err_t
sprd_rsa_test_sign_verify (void) {
	sprd_crypto_err_t err = SPRD_CRYPTO_SUCCESS;
	uint32_t in_len, out_len, i;
	int32_t result1, result2, result3;
	sprd_rsa_padding_t padding;
	sprd_rsa_keypair_t keypair;
	sprd_rsa_pubkey_t pubkey;

	padding.type = SPRD_RSASSA_PKCS1_V1_5;

	for (i = 1; i < (int)(sizeof(tests) / sizeof(tests[0])); i++) {
		keypair.n = tests[i].key_n;
		keypair.e = tests[i].key_e;
		keypair.d = tests[i].key_d;
		keypair.n_len = tests[i].data_len;
		keypair.e_len = 4;
		pubkey.n = tests[i].key_n;
		pubkey.e = tests[i].key_e;
		pubkey.n_len = tests[i].data_len;
		pubkey.e_len = 4;
		in_len = 32;
		out_len = tests[i].data_len;
		sprd_pal_memset(tests[i].din, 0xa, 32);

		err = sprd_rsa_sign((const sprd_rsa_keypair_t*)(&keypair),
				(const uint8_t*)(tests[i].din), in_len,
				tests[i].dout, &out_len, padding);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("sign fail(0x%x)\n", err);
			goto failed;
		}

		err = sprd_rsa_verify((const sprd_rsa_pubkey_t*)(&pubkey),
				(const uint8_t*)(tests[i].din), in_len,
				tests[i].dout, out_len, padding, &result1);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("verify1 failed(%08x)\n", err);
			goto failed;
		}

		tests[i].dout[i] = tests[i].dout[i] + 1;
		err = sprd_rsa_verify((const sprd_rsa_pubkey_t*)(&pubkey),
				(const uint8_t*)(tests[i].din), in_len,
				tests[i].dout, out_len, padding,  &result2);
		if (err == SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("verify2 successful(%08x)\n", err);
			err = SPRD_CRYPTO_INVALID_PACKET;
			goto failed;
		}

		tests[i].dout[i] = tests[i].dout[i] - 1;
		tests[i].din[i] = tests[i].din[i] + 1;
		err = sprd_rsa_verify((const sprd_rsa_pubkey_t*)(&pubkey),
				(const uint8_t*)(tests[i].din), in_len,
				tests[i].dout, out_len, padding,  &result3);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("verify3 failed(%08x)\n", err);
			err = SPRD_CRYPTO_INVALID_PACKET;
			goto failed;
		}

		if (result1 == SPRD_VERIFY_SUCCESS
			&& result2 == SPRD_VERIFY_FAILED
			&& result3 == SPRD_VERIFY_FAILED ) {
			err = SPRD_CRYPTO_SUCCESS;
		} else {
			err = SPRD_CRYPTO_INVALID_PACKET;
			goto failed;
		}
	}

failed:
	return err;
}

sprd_crypto_err_t
sprd_rsa_test (void) {
	sprd_crypto_err_t err = SPRD_CRYPTO_SUCCESS;
	int32_t rsa_enc = 0, rsa_dec = 0, rsa_sign_verify = 0;

	err = sprd_rsa_test_enc();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sprd_rsa_test_enc FAILED!****\n");
		goto failed;
	} else {
		rsa_enc = 1;
	}

	err = sprd_rsa_test_dec();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sprd_rsa_test_dec FAILED!****\n");
		goto failed;
	} else {
		rsa_dec = 1;
	}

	err = sprd_rsa_test_sign_verify();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sprd_rsa_test_sign_verify FAILED!****\n");
		goto failed;
	} else {
		rsa_sign_verify = 1;
	}

failed:
	if (rsa_enc == 1) {
		SPRD_CRYPTO_LOG_WARN("sprd_rsa_test_enc pass!\n");
	}

	if (rsa_dec == 1) {
		SPRD_CRYPTO_LOG_WARN("sprd_rsa_test_dec pass!\n");
	}

	if (rsa_sign_verify == 1) {
		SPRD_CRYPTO_LOG_WARN("sprd_rsa_test_sign_verify pass!\n");
	}
	return err;
}


