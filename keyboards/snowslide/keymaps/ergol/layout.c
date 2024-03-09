//! this file is not intended to be compiled, it's included in `keymap.c`
//! I've done this so the keymap is more easily accessible

#include <keymap_bepo.h>
#include "../keymap_ergol.h"

// move window to left screen
#define MV_LFT SWIN(KC_LEFT)

// move window to right screen
#define MV_RGT SWIN(KC_RIGHT)

#define DITTO LWIN(KC_MINS)
#define PASSMAN RCS(KC_RBRC)
#define DEL_LINE RCS(EL_K)
#define LAUNCH A(KC_SPC)
#define WD_LFT C(KC_LEFT)
#define WD_RGT C(KC_RIGHT)
#define UNDO C(EL_Z)
#define REDO C(EL_Y)
#define TLG A(KC_GRV)
#define DSCRD C(KC_GRV)
#define CUT C(EL_X)
#define COPY C(EL_C)
#define PASTE C(EL_V)
#define SPOTI_FAV LSA(EL_B)
#define FFX_DEL RCS(KC_DEL)
#define OTHER_QUOT ALGR(BP_COMM)
#define ACC_CIR EL_CIR

// LAYERS SECTION
enum snowslide_layers {
    _DEFAULTS = 0,
    _ERGOL = 0,
    _BEPO,
    _NAV,
    _NUM,
    _SYM,
    _MEDIA
};

enum custom_keycodes {
    BP_SHARP = SAFE_RANGE,
    // BP_AMP,
    TGL_GAME,
    LLOCK,
    GRV_CIR,
    MY_QUOT,
    EL_POUND
};

// for bépo 1.1g
// diff from 1.1rc2:
// - npsp is on ALGR(KC_SPC), underscore on ALGR(S(KC_SPC))
// - apostrophe on BP_QUOT and typo apostrophe on ALGR(BP_COMM) (like 1.0)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ERGOL] = LAYOUT(
                   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    LAUNCH,
                   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                              KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    DSCRD,
        RCS(EL_F), KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL,                         GRV_CIR,  KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,   KC_RSFT,
                   KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,                        KC_QUOT,  KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, C(EL_K),
                   KC_ENT,                             KC_LALT, KC_LCTL, MO(_NAV),  KC_SPC,     KC_ENT, MO(_SYM), MO(_NUM), LAUNCH,                            KC_BSPC
    ),

    [_BEPO] = LAYOUT(
                   KC_ESC,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                                            BP_AT,     BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_CCED,
                   KC_TAB,  BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV,                                            BP_DCIR,   BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
        RCS(BP_F), KC_LSFT, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, KC_DEL,                         GRV_CIR,   BP_C,      BP_T,    BP_S,    BP_R,    BP_N,    BP_M,   KC_RSFT,
                   BP_EQL,  BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    KC_BSPC,                        MY_QUOT,   BP_QUOT,   BP_Q,    BP_G,    BP_H,    BP_F,    BP_W,
                   KC_ENT,                             KC_LALT, KC_LCTL, MO(_NAV),  KC_SPC,     KC_ENT,  MO(_SYM), KC_BSPC,   KC_RALT,                            LAUNCH
    ),

    [_NAV] = LAYOUT(
                   _______,  KC_F1,   KC_F2,     KC_F3,     KC_F4,    KC_F5,                                                    KC_F6,      KC_F7,     KC_F8,   KC_F9,   KC_F10,     KC_F11,
                   KC_MUTE,  MV_LFT,  SPOTI_FAV, C(KC_SPC), FFX_DEL,  C(KC_PSCR),                                               DEL_LINE,   WD_LFT,   KC_UP,  WD_RGT,  KC_WH_U,     KC_F12,
        KC_MNXT,   _______,  UNDO,    KC_LALT,   KC_LCTRL,  KC_LSFT,  ALGR(KC_TAB), DSCRD,                          PASSMAN,    KC_PGUP,    KC_LEFT,   KC_DOWN,  KC_RGHT, KC_WH_D,    KC_LGUI, KC_PSCR,
                   KC_CAPS,  REDO,    CUT,       COPY,      PASTE,    DITTO,        TLG,                            KC_MPRV,    KC_PGDOWN,  KC_HOME,   KC_END, KC_WH_L, KC_WH_R,    LGUI(KC_SPC),
                   KC_MPLY,                                 LLOCK,  TG(_MEDIA), TG(_NAV), KC_SPC,          KC_ENT,  _______,    KC_RSFT,   KC_RCTL,                                  TGL_GAME
    ),

    [_NUM] = LAYOUT(
                   _______,  KC_F1,   KC_F2,     KC_F3,     KC_F4,    KC_F5,                                                    KC_F6,      KC_F7,     KC_F8,   KC_F9,   KC_F10,     KC_F11,
                   _______,  KC_NO,   KC_PPLS,   KC_PMNS, KC_PAST, KC_PSLS,                                               DEL_LINE,   WD_LFT,    KC_UP,   WD_RGT,  KC_APP,     KC_F12,
        KC_MNXT,   KC_NUM,   KC_1,    KC_2,      KC_3,      KC_4,     KC_5,        DSCRD,                          PASSMAN,     KC_6,       KC_7,      KC_8,    KC_9,    KC_0,       KC_LGUI,     KC_PSCR,
                   _______,  KC_NO,   S(KC_4),   EL_POUND,  S(KC_1),    KC_N,        TLG,                            KC_MPRV,    KC_N,    KC_PPLS,   KC_PMNS, KC_PAST, KC_PSLS,      LGUI(KC_SPC),
                   _______,                                 LLOCK,  TG(_MEDIA), TG(_NAV), KC_SPC,          TG(_NUM),  TG(_NUM),    TG(_NUM),   KC_RCTL,                                KC_ENT
    ),

    [_SYM] = LAYOUT(
                   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                    KC_6,           KC_7,          KC_8,          KC_9,          KC_0,          KC_NO,
                   KC_TAB,  ALGR(KC_Q), ALGR(KC_W),    ALGR(KC_E),    ALGR(KC_R),    ALGR(KC_T),                         ALGR(KC_Y),     ALGR(KC_U),    ALGR(KC_I),    ALGR(KC_O),    ALGR(KC_P),    KC_NO,
        RCS(KC_G), KC_LSFT, ALGR(KC_A), ALGR(KC_S),    ALGR(KC_D),    ALGR(KC_F),    ALGR(KC_G),    KC_DEL,    GRV_CIR,  ALGR(KC_H),     ALGR(KC_J),    ALGR(KC_K),    ALGR(KC_L),    ALGR(KC_SCLN), KC_RSFT,   KC_RSFT,
                   KC_NO,   ALGR(KC_Z), ALGR(KC_X),    ALGR(KC_C),    ALGR(KC_V),    ALGR(KC_B),    KC_BSPC,   KC_QUOT,  ALGR(KC_N),     ALGR(KC_M),    ALGR(KC_COMM), ALGR(KC_DOT),  ALGR(KC_SLSH), KC_NO,
                   CAPSWRD,                                           LLOCK, KC_LCTL, _______,    KC_SPC,     KC_BSPC, TG(_SYM),       MO(_NUM), _______,                                          KC_ENT
    ),

    [_MEDIA] = LAYOUT(
                 _______ ,  KC_F1,    KC_F2,     KC_F3,     KC_F4,    KC_F5,                                            KC_F6,     KC_F7,   KC_F8,    KC_F9,  KC_F10,  KC_F11,
                 _______,  _______,  EL_F,      KC_UP,     _______,  _______,                                           KC_PPLS,   KC_P7,   KC_P8,    KC_P9,  KC_PSLS, KC_F12,
        _______, _______,  _______,  KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,   BP_F,                       KC_RALT,   KC_PMNS,   KC_P4,   KC_P5,    KC_P6,  KC_PAST, S(KC_1), KC_INS,
                 _______,   _______,  _______,   _______,   _______,  _______,   _______,                    KC_PDOT,    KC_P0,    KC_P1,   KC_P2,    KC_P3,  KC_PDOT, EL_POUND,
                 _______,                                  _______,   TG(_MEDIA),  TG(_MEDIA), KC_SPC,      KC_ENT,  TG(_SYM),  KC_BSPC,  _______,                           TG(_MEDIA)
    )
};
