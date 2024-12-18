/* 
 * Conversion table for CP437 charset also known as IBM437
 *
 * Copyright (C) Alexander Bokovoy		2003
 *
 * Conversion tables are generated using GNU libc 2.2.5's 
 * localedata/charmaps/IBM437 table and source/script/gen-8bit-gap.sh script
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "includes.h"

static const uint16 to_ucs2[256] = {
 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
 0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017,
 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
 0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
 0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
 0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
 0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
 0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
 0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x007F,
 0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7,
 0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5,
 0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9,
 0x00FF, 0x00D6, 0x00DC, 0x00A2, 0x00A3, 0x00A5, 0x20A7, 0x0192,
 0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA,
 0x00BF, 0x2310, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
 0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
 0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510,
 0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F,
 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567,
 0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B,
 0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580,
 0x03B1, 0x00DF, 0x0393, 0x03C0, 0x03A3, 0x03C3, 0x00B5, 0x03C4,
 0x03A6, 0x0398, 0x03A9, 0x03B4, 0x221E, 0x03C6, 0x03B5, 0x2229,
 0x2261, 0x00B1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00F7, 0x2248,
 0x00B0, 0x2219, 0x00B7, 0x221A, 0x207F, 0x00B2, 0x25A0, 0x00A0,
};

static const struct charset_gap_table from_idx[] = {
  { 0x0000, 0x007f,     0 },
  { 0x00a0, 0x00c9,   -32 },
  { 0x00d1, 0x00ff,   -39 },
  { 0x0192, 0x0192,  -185 },
  { 0x0393, 0x0398,  -697 },
  { 0x03a3, 0x03a9,  -707 },
  { 0x03b1, 0x03b5,  -714 },
  { 0x03c0, 0x03c6,  -724 },
  { 0x207f, 0x207f, -8076 },
  { 0x20a7, 0x20a7, -8115 },
  { 0x2219, 0x221e, -8484 },
  { 0x2229, 0x2229, -8494 },
  { 0x2248, 0x2248, -8524 },
  { 0x2261, 0x2265, -8548 },
  { 0x2310, 0x2310, -8718 },
  { 0x2320, 0x2321, -8733 },
  { 0x2500, 0x2502, -9211 },
  { 0x250c, 0x251c, -9220 },
  { 0x2524, 0x2524, -9227 },
  { 0x252c, 0x252c, -9234 },
  { 0x2534, 0x2534, -9241 },
  { 0x253c, 0x253c, -9248 },
  { 0x2550, 0x256c, -9267 },
  { 0x2580, 0x2593, -9286 },
  { 0x25a0, 0x25a0, -9298 },
  { 0xffff, 0xffff,     0 }
};

static const unsigned char from_ucs2[] = {

  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
  0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
  0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
  0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
  0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
  0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
  0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
  0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
  0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
  0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
  0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
  0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
  0xff, 0xad, 0x9b, 0x9c, 0x00, 0x9d, 0x00, 0x00,
  0x00, 0x00, 0xa6, 0xae, 0xaa, 0x00, 0x00, 0x00,
  0xf8, 0xf1, 0xfd, 0x00, 0x00, 0xe6, 0x00, 0xfa,
  0x00, 0x00, 0xa7, 0xaf, 0xac, 0xab, 0x00, 0xa8,
  0x00, 0x00, 0x00, 0x00, 0x8e, 0x8f, 0x92, 0x80,
  0x00, 0x90, 0xa5, 0x00, 0x00, 0x00, 0x00, 0x99,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x00, 0x00,
  0xe1, 0x85, 0xa0, 0x83, 0x00, 0x84, 0x86, 0x91,
  0x87, 0x8a, 0x82, 0x88, 0x89, 0x8d, 0xa1, 0x8c,
  0x8b, 0x00, 0xa4, 0x95, 0xa2, 0x93, 0x00, 0x94,
  0xf6, 0x00, 0x97, 0xa3, 0x96, 0x81, 0x00, 0x00,
  0x98, 0x9f, 0xe2, 0x00, 0x00, 0x00, 0x00, 0xe9,
  0xe4, 0x00, 0x00, 0xe8, 0x00, 0x00, 0xea, 0xe0,
  0x00, 0x00, 0xeb, 0xee, 0xe3, 0x00, 0x00, 0xe5,
  0xe7, 0x00, 0xed, 0xfc, 0x9e, 0xf9, 0xfb, 0x00,
  0x00, 0x00, 0xec, 0xef, 0xf7, 0xf0, 0x00, 0x00,
  0xf3, 0xf2, 0xa9, 0xf4, 0xf5, 0xc4, 0x00, 0xb3,
  0xda, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00,
  0xc0, 0x00, 0x00, 0x00, 0xd9, 0x00, 0x00, 0x00,
  0xc3, 0xb4, 0xc2, 0xc1, 0xc5, 0xcd, 0xba, 0xd5,
  0xd6, 0xc9, 0xb8, 0xb7, 0xbb, 0xd4, 0xd3, 0xc8,
  0xbe, 0xbd, 0xbc, 0xc6, 0xc7, 0xcc, 0xb5, 0xb6,
  0xb9, 0xd1, 0xd2, 0xcb, 0xcf, 0xd0, 0xca, 0xd8,
  0xd7, 0xce, 0xdf, 0x00, 0x00, 0x00, 0xdc, 0x00,
  0x00, 0x00, 0xdb, 0x00, 0x00, 0x00, 0xdd, 0x00,
  0x00, 0x00, 0xde, 0xb0, 0xb1, 0xb2, 0xfe,
};

SMB_GENERATE_CHARSET_MODULE_8_BIT_GAP(CP437)
