 /* Copyright 2021 Dane Evans
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#define OLED_FONT_H "keyboards/sofle/keymaps/geobert/glcdfont.c"
//#define USE_MATRIX_I2C

/* Select hand configuration */

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/


#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

// #define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 230
#define TAPPING_TERM_PER_KEY
#define TAPPING_TOGGLE 2

#define ENCODER_DIRECTION_FLIP
#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTIONS {4, 3}


