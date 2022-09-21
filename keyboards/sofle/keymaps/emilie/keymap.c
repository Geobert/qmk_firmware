 /* Copyright 2021 Geobert Quach
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
  // Based on SOFLE rgb_default
#include <stdio.h>

#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
// char wpm_str[4];
#endif

#include <keymap_bepo.h>

// move window to left screen
#define MV_LFT SWIN(KC_LEFT)

// move window to right screen
#define MV_RGT SWIN(KC_RIGHT)

#define DITTO LWIN(BP_AGRV)
#define KEEPASS RCS(BP_W)
#define DEL_LINE RCS(BP_K)
#define LAUNCH A(KC_SPC)
#define WD_LFT C(KC_LEFT)
#define WD_RGT C(KC_RIGHT)
#define UNDO C(BP_Z)
#define REDO C(BP_Y)
#define TLG A(BP_DLR)
#define DSCRD C(BP_DLR)
#define CUT C(BP_X)
#define COPY C(BP_C)
#define PASTE C(BP_V)
#define BP_POUND ALGR(BP_L)
#define DISC_MUTE C(BP_AGRV)

// LAYERS SECTION
enum sofle_layers {
    _DEFAULTS = 0,
    _BEPO = 0,
    _GAME,
    _RED,
    _BLUE
};

enum custom_keycodes {
    BP_SHARP = SAFE_RANGE,
    BP_SUP,
    BP_AMP,
    BP_NAVTAB,
    TGL_GAME,
};

//
// For graphical layout visualisation see:
// http://www.keyboard-layout-editor.com/#/gists/d944d2f559bbeb5de92b941b30687559
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BEPO] = LAYOUT(
  KC_ESC,   BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                   BP_AT,  BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR,  BP_W ,
  KC_TAB,    BP_B,   BP_EACU,  BP_P,   BP_O,   BP_EGRV,                   BP_DCIR,  BP_V,   BP_D,    BP_L,    BP_J,    BP_Z,
  KC_LSFT,   BP_A,   BP_U,    BP_I,    BP_E,   BP_COMM,                   BP_C,    BP_T,   BP_S,   BP_R,     BP_N,      BP_M,
     BP_EQL, BP_AGRV, BP_Y, BP_X,   BP_DOT,  BP_K,  KC_MPLY,  DISC_MUTE,  BP_QUOT, BP_Q,   BP_G,    BP_H,    BP_F,   BP_CCED ,
                 KC_DEL, KC_LALT, KC_LCTL, TT(_RED), KC_SPC,     KC_ENT, TT(_BLUE), KC_RALT, KC_BSPC, KC_RSFT
),

[_GAME] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
    KC_ESC, BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                   BP_AT,  BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR,  BP_W ,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    KC_TAB, BP_B,   BP_EACU,  BP_W,   BP_O,   BP_EGRV,                    BP_DCIR,  BP_V,   BP_D,    BP_L,    BP_J,    BP_Z,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
     KC_LSFT, BP_A,   BP_A,    BP_S,    BP_D,   BP_COMM,                   BP_C,    BP_T,     BP_S,  BP_R,     BP_N,   BP_M,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
     BP_EQL, BP_AGRV, BP_Y,    BP_X,  BP_DOT,  BP_K,  KC_MPLY,  DISC_MUTE,  BP_QUOT, BP_Q,   BP_G,    BP_H,    BP_F,   BP_CCED ,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_DEL, KC_LALT, KC_LCTL, TT(_RED), KC_SPC,     KC_ENT, TT(_BLUE), KC_RALT, KC_BSPC, KC_RSFT
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[_RED] = LAYOUT(
  //,------------------------------------------------.                             ,---------------------------------------------------.
  _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|------+-------+--------+--------+--------+------|                            |--------+-------+--------+--------+--------+---------|
  _______,  C(BP_B), MV_RGT, C(KC_SPC), C(KC_PSCR), KC_NO,                           KC_DEL, WD_LFT, KC_UP,   WD_RGT, KC_APP  ,  KC_F12,
  //|------+-------+--------+--------+--------+------|                            |--------+-------+--------+--------+--------+---------|
  _______,   UNDO,   KC_LALT, KC_RCTRL, KC_LSFT, TLG,                              KC_PGUP,  KC_LEFT, KC_DOWN, KC_RGHT, KC_LGUI, KC_PSCR,
  //|------+-------+--------+--------+--------+------      |  ===  |      |  ===  |--------+-------+--------+--------+--------+---------|
    KC_CAPS,  REDO,    CUT,     COPY,   PASTE, DSCRD,   _______,          KC_MUTE, KC_PGDOWN, KC_HOME,  KC_NO, KC_END,  KC_NO, KC_NO,
  //|------+-------+--------+--------+--------+------|      ===  |        |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,              _______,  KC_MNXT,  KC_MPRV, _______, TGL_GAME
  //            \--------+--------+--------+---------+-------|            |--------+---------+--------+---------+-------/
),

[_BLUE] = LAYOUT(
  //,------------------------------------------------.                              ,---------------------------------------------------.
  _______, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|------+-------+--------+--------+--------+------|                             |--------+-------+--------+--------+--------+---------|
  _______,  BP_SHARP,BP_DLR, BP_LPRN, BP_RPRN, BP_EQL,                               KC_PMNS , KC_P7,  KC_P8,  KC_P9,  KC_PSLS, KC_F12,
  //|------+-------+--------+--------+--------+------|                             |--------+-------+--------+--------+--------+---------|
  _______,  BP_PIPE, BP_LABK ,BP_SUP,  BP_AMP, BP_COLN,                            KC_PPLS , RSFT_T(KC_P4), ALGR_T(KC_P5), KC_P6, KC_PAST, BP_EURO,
  //|------+-------+--------+--------+--------+------|  ===  |             |  ===  |--------+-------+--------+--------+--------+---------|
  BP_PERC ,BP_BSLS, BP_LCBR, BP_RCBR, BP_LBRC,BP_RBRC,_______,             DISC_MUTE, KC_PDOT , KC_P1,  KC_P2, KC_P3 , KC_INS,   BP_POUND,
  //|------+-------+--------+--------+--------+------|  ===  |             |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, BP_GRV, BP_UNDS,                _______, _______, KC_P0,  _______, _______
  //            \--------+--------+--------+---------+-------|             |--------+---------+--------+---------+-------/
),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(BP_T):
        case RCTL_T(BP_S):
        case RSFT_T(KC_P5):
        case ALGR_T(KC_P6):
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT(_RED):
        case TT(_BLUE):
            return 150;
        default:
            return TAPPING_TERM;
    }
}

bool is_nav_tab_active = false;
uint16_t nav_tab_timer = 0;
#define NAV_TAB_TIMEOUT 800
bool is_game = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TGL_GAME:
            if (record->event.pressed) {
                if (is_game) {
                    is_game = false;
                    default_layer_set(1UL << _BEPO);
                } else {
                    is_game = true;
                    default_layer_set(1UL << _GAME);
                }
            }
            break;
        case BP_SHARP:
            if (record->event.pressed) {
                uint8_t cur_mods = get_mods();
                if (cur_mods & MOD_MASK_SHIFT) {
                    register_mods(mod_config(MOD_RALT));
                } else {
                    register_mods(mod_config(MOD_LSFT));
                }
                tap_code16(BP_DLR);
                if (cur_mods & MOD_MASK_SHIFT) {
                    unregister_mods(mod_config(MOD_RALT));
                } else {
                    unregister_mods(mod_config(MOD_LSFT));
                }
                set_mods(cur_mods);
            }
            break;
        case BP_SUP:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    uint8_t temp_mods = get_mods();  //store held mods
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code16(BP_EQL);
                    tap_code16(BP_RABK);
                    set_mods(temp_mods);             //reset SHIFT
                } else {
                    tap_code16(BP_RABK);
                }
            }
            break;
        case BP_AMP:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    uint8_t temp_mods = get_mods();  //store held mods
                    unregister_mods(MOD_MASK_SHIFT);
                    tap_code16(BP_MINS);
                    tap_code16(BP_RABK);
                    set_mods(temp_mods);             //reset SHIFT
                } else {
                    tap_code16(BP_AMPR);
                }
            }
            break;
        case BP_NAVTAB:
            if (record->event.pressed) {
                if (!is_nav_tab_active) {
                    is_nav_tab_active = true;
                    register_code(KC_LCTL);
                }
                nav_tab_timer = timer_read();
                tap_code16(KC_TAB);
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#define ALT_TAB_TIMEOUT 800

void do_alt_tab(bool clockwise) {
    if (clockwise) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
    } else {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
    }
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > ALT_TAB_TIMEOUT) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }

  if (is_nav_tab_active) {
    if (timer_elapsed(nav_tab_timer) > NAV_TAB_TIMEOUT) {
      unregister_code(KC_LCTL);
      is_nav_tab_active = false;
    }
  }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _BEPO:
            case _GAME:
                do_alt_tab(clockwise);
                break;
            case _RED:
                if (clockwise) {
                    tap_code(KC_PGDOWN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _BLUE:
                // Scrolling through search results
                if (clockwise) {
                    tap_code(KC_F3);
                } else {
                    tap_code16(S(KC_F3));
                }
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _BEPO:
            case _BLUE:
            case _GAME:
                if (clockwise) {
                    tap_code(KC_DEL);
                } else {
                    tap_code(KC_BSPC);
                }
                break;
             case _RED:
                if (clockwise) {
                    tap_code(KC_VOLU);
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    return true;
}

#endif

// OLED screen

#ifdef OLED_DRIVER_ENABLE

void render_mod_status_caps_alt(uint8_t modifiers) {
    static const char PROGMEM caps_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM caps_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM caps_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM caps_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    led_t led_usb_state = host_keyboard_led_state();
    // oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    if(led_usb_state.caps_lock) {
        oled_write_P(caps_on_1, false);
    } else {
        oled_write_P(caps_off_1, false);
    }

    if ((led_usb_state.caps_lock) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(led_usb_state.caps_lock) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(led_usb_state.caps_lock) {
        oled_write_P(caps_on_2, false);
    } else {
        oled_write_P(caps_off_2, false);
    }

    if (led_usb_state.caps_lock && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_2, false);
    } else if(led_usb_state.caps_lock) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    // static const char PROGMEM adjust_layer[] = {
    //     0x20, 0x9d, 0x9e, 0x9f, 0x20,
    //     0x20, 0xbd, 0xbe, 0xbf, 0x20,
    //     0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    // if(layer_state_is(_ADJUST)) {
    //     oled_write_P(adjust_layer, false);
    // } else
    if(layer_state_is(_BLUE)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RED)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    // oled_write_P(PSTR("corne"), false);
}

static void print_status_narrow(void) {
    render_logo();
    oled_write_P(PSTR("\n"), false);
    render_layer_state();
    oled_write_P(PSTR("\n"), false);
    render_mod_status_caps_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());

    switch (get_highest_layer(default_layer_state)) {
        case _BEPO:
            oled_write_ln_P(PSTR("\nBepo"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("\nGame"), false);
            break;
        default:
            oled_write_ln_P(PSTR("\nUndef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

/* Animation bit by j-inc https://github.com/qmk/qmk_firmware/tree/master/keyboards/kyria/keymaps/j-inc */
// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 30 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 45 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 320 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Implementation credit j-inc(/James Incandenza), pixelbenny, and obosob.
// Bongo cat images changed and adapted for sofle keyboard oled size.
// Original gif can be found here: https://www.pixilart.com/art/bongo-cat-bd2a8e9323aa705
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        }
    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0x7c, 0x70, 0x40, 0x40,
        0x61, 0x5e, 0x80, 0xc0, 0xbc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0f, 0x3f, 0xf8, 0xf0, 0xf0, 0x20,
        0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        },
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0f, 0x3f, 0xff, 0x03, 0x01, 0x03, 0x07, 0x18, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01
        },
    };

    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            /*
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
            */
            oled_write_raw_P(idle[0], ANIM_SIZE);
         }
         /*
         if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }*/
         if(get_current_wpm() >=TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        oled_write_P(PSTR("\n"), false);
        render_anim();
        oled_set_cursor(0,12);
        // sprintf(wpm_str, "WPM\n%03d", get_current_wpm());
        // oled_write(wpm_str, false);
    }
}

#endif



