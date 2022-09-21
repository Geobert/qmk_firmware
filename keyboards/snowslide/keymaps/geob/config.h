#pragma once

#define OLED_FONT_H "keyboards/snowslide/keymaps/geob/glcdfont.c"
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 30000 // ms

//#define USE_MATRIX_I2C

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/


// #define CUSTOM_FONT

// #define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

// #define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define RETRO_TAPPING

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 190
#define TAPPING_TERM_PER_KEY
#define TAPPING_TOGGLE 2

#ifdef DEBOUNCE
    #undef DEBOUNCE
#endif
#define DEBOUNCE 6

