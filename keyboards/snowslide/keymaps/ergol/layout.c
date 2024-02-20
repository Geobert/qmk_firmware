//! this file is not intended to be compiled, it's included in `keymap.c`
//! I've done this so the keymap is more easily accessible

#include <keymap_bepo.h>
#include "../keymap_ergol.h"

// move window to left screen
#define MV_LFT SWIN(KC_LEFT)

// move window to right screen
#define MV_RGT SWIN(KC_RIGHT)

#define DITTO LWIN(EL_GRV)
#define PASSMAN RCS(EL_W)
#define DEL_LINE RCS(EL_K)
#define LAUNCH A(KC_SPC)
#define WD_LFT C(KC_LEFT)
#define WD_RGT C(KC_RIGHT)
#define UNDO C(EL_Z)
#define REDO C(EL_Y)
#define TLG A(EL_DLR)
#define DSCRD C(EL_DLR)
#define CUT C(EL_X)
#define COPY C(EL_C)
#define PASTE C(EL_V)
#define BP_POUND ALGR(S(BP_L)) //1.1
#define SPOTI_FAV LSA(EL_B)
#define FFX_DEL RCS(KC_DEL)
#define OTHER_QUOT ALGR(BP_COMM)
#define ACC_CIR EL_CIR
#define UNDS ALGR(S(KC_SPC)) //1.1g

// LAYERS SECTION
enum snowslide_layers {
    _DEFAULTS = 0,
    _ERGOL = 0,
    _BEPO,
    _RED,
    _BLUE,
    _MEDIA
};

enum custom_keycodes {
    BP_SHARP = SAFE_RANGE,
    // BP_AMP,
    BP_ARRO,
    BP_FARRO,
    TGL_GAME,
    LLOCK,
    GRV_CIR,
    MY_QUOT
};

// for bépo 1.1g
// diff from 1.1rc2:
// - npsp is on ALGR(KC_SPC), underscore on ALGR(S(KC_SPC))
// - apostrophe on BP_QUOT and typo apostrophe on ALGR(BP_COMM) (like 1.0)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ERGOL] = LAYOUT(
                   KC_ESC,  EL_1,    EL_2,    EL_3,    EL_4,    EL_5,                                               EL_6,      EL_7,    EL_8,    EL_9,    EL_0,    EL_SLSH,
                   KC_TAB,  EL_Q,    EL_C,    EL_O,    EL_P,    EL_W,                                               EL_J,      EL_M,    EL_D,    EL_DEAD, EL_F,    EL_EQL,
        RCS(EL_F), KC_LSFT, EL_A,    EL_S,    EL_E,    EL_N,    EL_COMM, KC_DEL,                         GRV_CIR,   EL_L,      EL_R,    EL_T,    EL_I,    EL_U,    KC_RSFT,   KC_RSFT,
                   EL_LABK, EL_Z,    EL_X,    EL_MINS, EL_V,    EL_B,    KC_BSPC,                        EL_QUOT,   EL_DOT,    EL_H,    EL_G,    EL_Y,    EL_K,    KC_LGUI,
                   KC_ENT,                             KC_LALT, KC_LCTL, MO(_RED),  KC_SPC,     KC_ENT,  MO(_BLUE), KC_BSPC,   KC_RALT,                            LAUNCH
    ),

    [_BEPO] = LAYOUT(
                   KC_ESC,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                                            BP_AT,     BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_CCED,
                   KC_TAB,  BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV,                                            BP_DCIR,   BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
        RCS(BP_F), KC_LSFT, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, KC_DEL,                         GRV_CIR,   BP_C,      BP_T,    BP_S,    BP_R,    BP_N,    BP_M,   KC_RSFT,
                   BP_EQL,  BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    KC_BSPC,                        MY_QUOT,   BP_QUOT,   BP_Q,    BP_G,    BP_H,    BP_F,    BP_W,
                   KC_ENT,                             KC_LALT, KC_LCTL, MO(_RED),  KC_SPC,     KC_ENT,  MO(_BLUE), KC_BSPC,   KC_RALT,                            LAUNCH
    ),

    [_RED] = LAYOUT(
                   _______,  KC_F1,   KC_F2,     KC_F3,     KC_F4,    KC_F5,                                                    KC_F6,      KC_F7,     KC_F8,   KC_F9,   KC_F10,     KC_F11,
                   KC_MUTE,  MV_LFT,  SPOTI_FAV, C(KC_SPC), FFX_DEL,  C(KC_PSCR),                                               DEL_LINE,   WD_LFT,    KC_UP,   WD_RGT,  KC_APP,     KC_F12,
        KC_MNXT,   _______,  UNDO,    KC_LALT,   KC_LCTRL,  KC_LSFT,  ALGR(KC_TAB), DSCRD,                          PASSMAN,    KC_PGUP,    KC_LEFT,   KC_UP,   KC_DOWN, KC_RGHT,  KC_LGUI, KC_PSCR,
                   KC_CAPS,  REDO,    CUT,       COPY,      PASTE,    DITTO,        TLG,                            KC_MPRV,    KC_PGDOWN,  KC_HOME,   KC_NO,   KC_END,  KC_NO,      LGUI(KC_SPC),
                   KC_MPLY,                                 LLOCK,  TG(_MEDIA), TG(_RED), KC_SPC,          KC_ENT,  _______,    KC_RSFT,   KC_RCTL,                                  TGL_GAME
    ),

    [_BLUE] = LAYOUT(
                 KC_NUM ,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                                            KC_F6,     KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,
                 _______,  EL_AT,    EL_LBRK,   EL_RBRK,   EL_DLR,   EL_PERC,                                          EL_CIR,    EL_AMPR, EL_ASTR,  EL_QUOT,  EL_GRV,  KC_F12,
        LLOCK,   _______,  EL_LCBR,  EL_LPRN,   EL_RPRN,   EL_RCBR,  EL_UNDS,   BP_FARRO,                  KC_RALT,    EL_BSLS,   EL_PLUS, EL_MINS,  EL_SLSH,  EL_DQUO, BP_POUND, KC_INS,
                 _______,  EL_TILD,  EL_LABK,   EL_RABK,   EL_EQL,   EL_HASH,   KC_DEL,                    KC_PDOT,    EL_PIPE,   EL_EXLM, EL_SCLN,  EL_COLN,  EL_QUES, BP_DLR,
                 CAPSWRD,                                  _______,   _______,  LLOCK, UNDS,      KC_ENT,  TG(_BLUE),  KC_BSPC,   _______,                              _______
    ),

    [_MEDIA] = LAYOUT(
                 _______ ,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                                            KC_F6,     KC_F7,   KC_F8,    KC_F9,  KC_F10,  KC_F11,
                 _______,  _______,  BP_F,      KC_UP,     _______,  _______,                                           KC_PPLS,   KC_P7,   KC_P8,    KC_P9,  KC_PSLS, KC_F12,
        _______, _______,  _______,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,   BP_F,                       KC_RALT,   KC_PMNS,   KC_P4,   KC_P5,    KC_P6,  KC_PAST, BP_POUND, KC_INS,
                 _______,   _______,  _______,   _______,   _______,  _______,   _______,                    KC_PDOT,    KC_P0,    KC_P1,   KC_P2,    KC_P3,  KC_PDOT, BP_EURO,
                 _______,                                  _______,   TG(_MEDIA),  TG(_MEDIA), KC_SPC,      KC_ENT,  TG(_BLUE),  KC_BSPC,  _______,                           TG(_MEDIA)
    )
};
