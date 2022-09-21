//! this file is not intended to be compiled, it's included in `keymap.c`
//! I've done this so the keymap is more easily accessible

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
#define DISC_MUTE C(BP_AGRV)
#define CUT C(BP_X)
#define COPY C(BP_C)
#define PASTE C(BP_V)
#define BP_POUND ALGR(BP_L)
#define SPOTI_FAV LSA(BP_B)
#define RSFT_T_P4 RSFT_T(KC_P4)
#define ALGR_T_P5 ALGR_T(KC_P5)
#define DSCRD C(BP_DLR)

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
    BP_ARRO,
    BP_FARRO,
    TGL_GAME,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BEPO] = LAYOUT(
                 KC_ESC,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                                            BP_AT,     BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_W,
                 KC_TAB,  BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV,                                            BP_DCIR,   BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
        KC_MPLY, KC_LSFT, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM,  KC_DEL,                        DISC_MUTE, BP_C,      BP_T,    BP_S,    BP_R,    BP_N,    BP_M,   KC_MUTE,
                 BP_EQL,  BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,     KC_BSPC,                       KC_DEL,    BP_QUOT,   BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED,
                 KC_ENT,                             KC_LALT, KC_LCTL,  TT(_RED),  KC_SPC,     KC_ENT, TT(_BLUE), KC_BSPC,   KC_RALT,                            KC_RSFT
    ),

    [_GAME] = LAYOUT(
                 KC_ESC,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                                            BP_AT,     BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_W,
                 KC_TAB,  BP_B,    BP_EACU, BP_CCED, BP_O,    BP_EGRV,                                            BP_DCIR,   BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
        KC_MPLY, KC_LSFT, BP_A,    BP_A,    BP_S,    BP_D,    BP_COMM,  KC_DEL,                        KC_BSPC,   BP_C,      BP_T,    BP_S,    BP_R,    BP_N,    BP_M,   KC_MUTE,
                 BP_EQL,  BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,     KC_BSPC,                       KC_DEL,    BP_QUOT,   BP_Q,    BP_G,    BP_H,    BP_F,    BP_CCED,
                 KC_ENT,                             KC_LALT, KC_LCTL,  TT(_RED),  KC_SPC,     KC_ENT, TT(_BLUE), KC_BSPC,   KC_RALT,                            KC_RSFT
    ),

    [_RED] = LAYOUT(
                 _______,  KC_F1,    KC_F2,     KC_F3,     KC_F4,      KC_F5,                                                      KC_F6,      KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,
                 _______,  C(BP_B),  MV_RGT,    C(KC_SPC), C(KC_PSCR), KC_NO,                                                      KC_DEL,     WD_LFT,    KC_UP,   WD_RGT,  KC_APP,  KC_F12,
        KC_MUTE, _______,  UNDO,     KC_LALT,   KC_LCTRL,  KC_LSFT,    ALGR(KC_TAB), KC_MNXT,                             KC_BSPC, KC_PGUP,    KC_LEFT,   KC_DOWN, KC_RGHT, KC_NO,   KC_LGUI, KC_PSCR,
                 KC_CAPS,  REDO,     CUT,       COPY,      PASTE,      DSCRD,        DISC_MUTE,                           KC_VOLU, KC_PGDOWN,  KC_HOME,   KC_NO,   KC_END,  BP_F,    KC_NO,
                 KC_NO,                                    _______,    _______,      TG(_RED),   KC_SPC,         KC_ENT,  KC_VOLD, KC_MPRV,    KC_NO,                                TGL_GAME
    ),

    [_BLUE] = LAYOUT(
                 _______,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                                                  KC_F6,      KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
                 _______,  BP_SHARP, BP_DLR,    BP_LPRN,   BP_RPRN,  BP_EQL,                                                 KC_PMNS,    KC_P7,   KC_P8,  KC_P9,  KC_PSLS, KC_F12,
        BP_GRV,  _______,  BP_PIPE,  BP_LABK,   BP_RABK,   BP_AMP,   BP_COLN,   KC_ENT,                            KC_BSPC,  KC_PPLS,    KC_P4,   KC_P5,  KC_P6,  KC_PAST, BP_EURO, KC_INS,
                 BP_PERC,  BP_BSLS,  BP_LCBR,   BP_RCBR,   BP_LBRC,  BP_RBRC,   KC_DEL,                            KC_RALT,  KC_PDOT,    KC_P1,   KC_P2,  KC_P3,  BP_DLR,  BP_POUND,
                 _______,                                  _______,   _______,  _______,  BP_UNDS,        KC_ENT,  TG(_BLUE),  KC_P0,   _______,                           A(KC_F4)
    )
};
