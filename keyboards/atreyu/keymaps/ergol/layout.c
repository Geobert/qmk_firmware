//! this file is not intended to be compiled, it's included in `keymap.c`
//! I've done this so the keymap is more easily accessible

#include QMK_KEYBOARD_H

// move window to left screen
#define MV_LFT SWIN(KC_LEFT)
// move window to right screen
#define MV_RGT SWIN(KC_RIGHT)

#define DITTO LWIN(KC_MINS)
#define PASSMAN RCS(KC_T)
#define DEL_LINE RCS(KC_SLSH)
#define LAUNCH A(KC_SPC)
#define WD_LFT C(KC_LEFT)
#define WD_RGT C(KC_RIGHT)
#define UNDO C(KC_Z)
#define REDO C(KC_Y)
#define TLG A(KC_GRV)
#define DSCRD C(KC_GRV)
#define CUT C(KC_X)
#define COPY C(KC_W)
#define PASTE C(KC_V)
#define FFX_DEL RCS(KC_DEL)
#define ACC_CIR ALGR(KC_Q)
#define BACKTICK ALGR(KC_P)

// LAYERS SECTION
enum snowslide_layers {
    _DEFAULTS = 0,
    _ERGOL = 0,
    _GAME,
    _NAV,
    _NUM,
    _MEDIA
};

enum custom_keycodes {
    TGL_GAME = SAFE_RANGE,
    LLOCK,
    GRV_CIR
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ERGOL] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,      KC_7,      KC_8,      KC_9,    KC_0,    DSCRD,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,      KC_U,      KC_I,      KC_O,    KC_P,    KC_NO,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,      KC_J,      KC_K,      KC_L,    KC_SCLN, KC_RSFT,
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,      KC_M,      KC_COMM,   KC_DOT,  KC_SLSH, LAUNCH,
    KC_ENT,           KC_LALT, KC_LCTL, MO(_NAV),  KC_SPC, KC_DEL     BACKTICK, KC_BSPC,   KC_RALT,   MO(_NUM),  KC_RALT,          KC_ENT
),

[_GAME] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,      KC_7,      KC_8,      KC_9,    KC_0,    DSCRD,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,      KC_U,      KC_I,      KC_O,    KC_P,    KC_NO,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,      KC_J,      KC_K,      KC_L,    KC_SCLN, KC_RSFT,
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,      KC_M,      KC_COMM,   KC_DOT,  KC_SLSH, LAUNCH,
    KC_ENT,           KC_LALT, KC_LCTL, MO(_NAV),  KC_SPC, KC_DEL     BACKTICK, KC_BSPC,   KC_RALT,   MO(_NUM),  KC_RALT,          KC_ENT
),

[_NAV] = LAYOUT(
    _______,  KC_F1,   KC_F2,     KC_F3,     KC_F4,    KC_F5,                        KC_F6,      KC_F7,     KC_F8,   KC_F9,   KC_F10,     KC_F11,
    KC_MUTE,  MV_LFT,  SPOTI_FAV, C(KC_SPC), FFX_DEL,  C(KC_PSCR),                   DEL_LINE,   WD_LFT,    KC_UP,   WD_RGT,  KC_APP,     KC_F12,
    KC_LGUI,  UNDO,    KC_LALT,   KC_LCTRL,  KC_LSFT,  ALGR(KC_TAB),                 KC_PGUP,    KC_LEFT,   KC_DOWN, KC_RGHT, S(KC_F12),  KC_LGUI,
    KC_CAPS,  REDO,    CUT,       COPY,      PASTE,    DITTO,                        KC_PGDOWN,  KC_HOME,   KC_NO,   KC_END,  _______,    LGUI(KC_SPC),
    KC_MPLY,           LLOCK,  TG(_MEDIA),   TG(_NAV), KC_SPC,       TLG,   PASSMAN, KC_ENT,  _______,    KC_RSFT,   KC_RCTL,             TGL_GAME
),

[_NUM] = LAYOUT(
    KC_NUM ,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                          KC_F6,     KC_F7,      KC_F8,    KC_F9,  KC_F10,  KC_F11,
    _______,  BP_ARRO,  BP_SHARP,  BP_AMPR,   BP_LABK,  BP_RABK,                        KC_PPLS,   KC_P7,      KC_P8,    KC_P9,  KC_PSLS, KC_F12,
    _______,  BP_PIPE,  BP_RCBR,   BP_LCBR,   BP_LPRN,  BP_RPRN,                        KC_PMNS,   KC_P4,      KC_P5,    KC_P6,  KC_PAST, BP_POUND,
    LLOCK,    BP_BSLS,  BP_PERC,   BP_DLR,    BP_LBRC,  BP_RBRC,                        KC_P0,     KC_P1,      KC_P2,    KC_P3,  BP_EURO, BP_DLR,
    CAPSWRD,            _______,   _______,   LLOCK,    UNDS,    KC_DEL,     KC_PDOT,   KC_ENT,    TG(_BLUE),  KC_BSPC,  _______,         A(KC_F4)
),

[_MEDIA] = LAYOUT(
    _______ ,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                          KC_F6,     KC_F7,   KC_F8,    KC_F9,     KC_F10,  KC_F11,
    _______,   _______,  BP_F,      KC_UP,     _______,  _______,                        KC_PPLS,   KC_P7,   KC_UP,    KC_P9,     KC_PSLS, KC_F12,
    _______,   _______,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,                       KC_PMNS,   KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_PAST, BP_F,
    _______,   _______,  _______,   _______,   _______,  _______,                        KC_P0,     KC_P1,   KC_P2,    KC_P3,      BP_F, BP_DLR,
    _______,             _______,   TG(_MEDIA),  TG(_MEDIA), KC_SPC, BP_F,    KC_PDOT,   KC_ENT,  TG(_BLUE), KC_BSPC,  _______,          TG(_MEDIA)
)
};
