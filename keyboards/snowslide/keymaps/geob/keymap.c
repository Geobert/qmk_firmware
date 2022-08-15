#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
#endif

#include <keymap_bepo.h>

// move window to left screen
#define MV_LFT SWIN(KC_LEFT)

// move window to right screen
#define MV_RGT SWIN(KC_RIGHT)

#define DITTO LWIN(BP_AGRV)
#define PASSMAN RCS(BP_W)
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
#define SPOTI_FAV LSA(BP_B)
// #define ALT_T_U ALT_T(BP_U)
// #define LCTL_T_I LCTL_T(BP_I)
// #define LSFT_T_E LSFT_T(BP_E)
#define RSFT_T_T RSFT_T(BP_T)
#define RCTL_T_S RCTL_T(BP_S)
#define RCTL_T_R RCTL_T(BP_R)
#define RSFT_T_P4 RSFT_T(KC_P4)
#define ALGR_T_P5 ALGR_T(KC_P5)

// LAYERS SECTION
enum snowslide_layers {
    _DEFAULTS = 0,
    _BEPO = 0,
    _GAME,
    _RED,
    _BLUE,
};

enum custom_keycodes {
    BP_SHARP = SAFE_RANGE,
    BP_AMP,
    // BP_NAVTAB,
    BP_ARRO,
    BP_FARRO,
    TGL_GAME,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BEPO] = LAYOUT(
                 KC_ESC,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                        BP_AT,     BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_CCED,
                 KC_TAB,  BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV,                        BP_DCIR,   BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
        KC_MPLY, KC_LSFT, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM,   KC_DEL,     KC_BSPC, BP_C,      BP_T,    BP_S,    BP_R,    BP_N,    BP_M,     BP_W,
                 BP_GRV,  BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,      KC_BSPC,    KC_DEL,  BP_QUOT,   BP_Q,    BP_G,    BP_H,    BP_F,    BP_EQL,
                 KC_ENT,                    KC_LALT, KC_LCTL, TT(_RED),  KC_SPC,     KC_ENT,  TT(_BLUE), KC_RALT, KC_RSFT,                   LAUNCH
    ),

    [_GAME] = LAYOUT(
                 KC_ESC,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                        BP_AT,     BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_CCED,
                 KC_TAB,  BP_B,    BP_EACU, BP_CCED, BP_O,    BP_EGRV,                        BP_DCIR,   BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
        KC_MPLY, KC_LSFT, BP_A,    BP_A,    BP_S,    BP_D,    BP_COMM,   KC_DEL,     KC_BSPC, BP_C,      BP_T,    BP_S,    BP_R,    BP_N,    BP_M,     BP_W,
                 BP_GRV,  BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,      KC_BSPC,    KC_DEL,  BP_QUOT,   BP_Q,    BP_G,    BP_H,    BP_F,    BP_EQL,
                 KC_ENT,                    KC_LALT, KC_LCTL, TT(_RED),  KC_SPC,     KC_ENT,  TT(_BLUE), KC_RALT, KC_RSFT,                   LAUNCH
    ),

    [_RED] = LAYOUT(
                 _______,  KC_F1,   KC_F2,     KC_F3,     KC_F4,    KC_F5,                             KC_F6,      KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 _______,  MV_LFT,  SPOTI_FAV, C(KC_SPC), PASSMAN,  C(KC_PSCR),                        DEL_LINE,   WD_LFT,    KC_UP,   WD_RGT,  KC_APP,  KC_F12,
        KC_MUTE, _______,  UNDO,    BP_A,      BP_S,      BP_D,     ALGR(KC_TAB), TLG,        KC_BSPC, KC_PGUP,    KC_LEFT,   KC_DOWN, KC_RGHT, KC_NO,   KC_LGUI, KC_PSCR,
                 KC_CAPS,  REDO,    BP_Y,      BP_X,      BP_DOT,   BP_K,         KC_MNXT,    KC_VOLU, KC_PGDOWN,  KC_HOME,   KC_NO,   KC_END,  BP_F,    KC_NO,
                 KC_NO,                        _______,   _______,  TT(_RED),     KC_SPC,     KC_ENT,  KC_VOLD,    KC_MPRV,   KC_NO,                     TGL_GAME
    ),

    [_BLUE] = LAYOUT(
                 _______,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                             KC_F6,      KC_F7,     KC_F8,  KC_F9,  KC_F10,  KC_F11,
                 _______,  KC_NO,    BP_SHARP,  BP_LABK,   BP_RABK,  BP_FARRO,                          KC_PMNS,    KC_P7,     KC_P8,  KC_P9,  KC_PSLS, KC_F12,
        KC_NO,   _______,  BP_PIPE,  BP_RCBR,   BP_LCBR,   BP_AMP,   BP_ARRO,    KC_ENT,       KC_BSPC, KC_PPLS,    KC_P4,     KC_P5,  KC_P6,  KC_PAST, BP_EURO, KC_INS,
                 BP_BSLS,  BP_PERC,  BP_DLR,    BP_LBRC,   BP_RBRC,  _______,    KC_DEL,       KC_RALT, KC_PDOT,    KC_P1,     KC_P2,  KC_P3,  BP_DLR,  BP_POUND,
                 _______,                       _______,   _______,  _______,    BP_UNDS,      KC_ENT,  TT(_BLUE),  KC_P0,     _______,                 _______
    )
};


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case ALT_T_U:
        // case LCTL_T_I:
        // case LSFT_T_E:
        case RSFT_T_T:
        case RCTL_T_S:
        case RCTL_T_R:
        case RSFT_T_P4:
        case ALGR_T_P5:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT(_RED):
        case TT(_BLUE):
            return 90;
        default:
            return TAPPING_TERM;
    }
}

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
        case BP_AMP:
            if (record->event.pressed) {
                tap_code16(BP_AMPR);
            }
            break;
        case BP_ARRO:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();  //store held mods
                clear_mods();
                if (temp_mods & MOD_MASK_SHIFT) {
                    tap_code16(BP_EQL);
                } else {
                    tap_code16(BP_MINS);
                }
                tap_code16(BP_RABK);
                set_mods(temp_mods);
            }
            break;
        case BP_FARRO:
            if (record->event.pressed) {
                uint8_t temp_mods = get_mods();  //store held mods
                clear_mods();
                if (temp_mods & MOD_MASK_SHIFT) {
                    tap_code16(BP_MINS);
                } else {
                    tap_code16(BP_EQL);
                }
                tap_code16(BP_RABK);
                set_mods(temp_mods);
            }
    }
    return true;
}

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
    // static const char PROGMEM game_layer[] = {
    //     0x20, 0x9d, 0x9e, 0x9f, 0x20,
    //     0x20, 0xbd, 0xbe, 0xbf, 0x20,
    //     0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    // if(layer_state_is(_GAME)) {
    //     oled_write_P(game_layer, false);
    // } else
    if (layer_state_is(_BLUE)) {
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
    return OLED_ROTATION_0;
}

void oled_task_user(void) {
    print_status_narrow();
}

#endif
