// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_japanese.h"
#include "features/achordion.h"

enum layer_names {
    _DEFAULT,
    _NAV,
    _NUM,
    _SYM,
    _SYM2,
    _NUMPAD
};

// Alias -- home row
#define HOME_A LT(_SYM, KC_A)
#define HOME_SCLN LT(_SYM2, KC_SCLN)
// Alias -- bottom row
#define W_T_Z WIN_T(KC_Z)
#define A_T_X ALT_T(KC_X)
#define BTM_C CTL_T(KC_C)
#define BTM_V SFT_T(KC_V)
#define BTM_M SFT_T(KC_M)
#define BTM_COMM CTL_T(KC_COMM)
#define A_T_DOT ALT_T(KC_DOT)
#define W_T_SLSH WIN_T(KC_SLSH)

// Alias -- Mod-Tap
#define ENT_NUM LT(_NUM, KC_ENT)
#define ESC_NUMP LT(_NUMPAD, KC_ESC)
#define MHEN_CTL CTL_T(KC_INT5)  // JP_MHEN

// Alias -- One Shot Modifier
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_RGUI OSM(MOD_RGUI)

enum combos {
    TG_COMBO,
    ED_COMBO,
    RF_COMBO,
    ZX_COMBO,
    XC_COMBO,
    CV_COMBO,
    ZC_COMBO,
    ZV_COMBO,
    FG_COMBO,
    UJ_COMBO,
    IK_COMBO,
    LSCLN_COMBO,
    COMMDOT_COMBO,
    DOTSLSH_COMBO,
    NUM_COMBO,
};

const uint16_t PROGMEM tg_combo[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM ed_combo[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM rf_combo[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {W_T_Z, A_T_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {A_T_X, BTM_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {BTM_C, BTM_V, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM uj_combo[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM ik_combo[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {KC_L, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {BTM_COMM, A_T_DOT, COMBO_END};
const uint16_t PROGMEM dotslsh_combo[] = {A_T_DOT, W_T_SLSH, COMBO_END};
const uint16_t PROGMEM num_combo[] = {KC_N, KC_U, KC_M, COMBO_END};

combo_t key_combos[] = {
    [TG_COMBO] = COMBO(tg_combo, CW_TOGG),
    [ED_COMBO] = COMBO(ed_combo, KC_BSPC),
    [RF_COMBO] = COMBO(rf_combo, JP_MHEN),
    [ZX_COMBO] = COMBO(zx_combo, KC_LGUI),
    [XC_COMBO] = COMBO(xc_combo, KC_LALT),
    [FG_COMBO] = COMBO(fg_combo, JP_MHEN),
    [UJ_COMBO] = COMBO(uj_combo, JP_HENK),
    [IK_COMBO] = COMBO(ik_combo, KC_DEL),
    [LSCLN_COMBO] = COMBO(lscln_combo, JP_COLN),
    [COMMDOT_COMBO] = COMBO(commdot_combo, KC_RALT),
    [DOTSLSH_COMBO] = COMBO(dotslsh_combo, KC_RGUI),
    [NUM_COMBO] = COMBO(num_combo, KC_NUM),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS,
        ESC_NUMP,HOME_A,  KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    HOME_SCLN,JP_COLN,
        KC_LSFT, W_T_Z,   A_T_X,   BTM_C,   BTM_V,   KC_B,                      KC_N,    BTM_M,   BTM_COMM,A_T_DOT, W_T_SLSH, JP_BSLS,
                                            KC_LALT, KC_LCTL, KC_SPC,  ENT_NUM, MO(_NAV),KC_DEL
    ),
    // navigation
    [_NAV] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______, _______, _______
    ),
    // num
    [_NUM] = LAYOUT_split_3x6_3(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F4,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        XXXXXXX, W_T_Z,   A_T_X,   BTM_C,   BTM_V,   XXXXXXX,                   XXXXXXX, BTM_M,   BTM_COMM,A_T_DOT, W_T_SLSH, JP_BSLS,
                                            _______, _______, _______, _______, _______, _______
    ),
    // symbol 1
    [_SYM] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   JP_CIRC, JP_AMPR, JP_ASTR, JP_PIPE, JP_GRV,  XXXXXXX,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   JP_QUOT, JP_TILD, JP_LPRN, JP_RPRN, JP_PLUS, JP_ASTR,
        _______, OSM_RGUI,OSM_LALT,OSM_LCTL,OSM_LSFT,XXXXXXX,                   XXXXXXX, XXXXXXX, JP_LABK, JP_RABK, XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______, _______, _______
    ),
    // symbol 2
    [_SYM2] = LAYOUT_split_3x6_3(
        _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, JP_UNDS, JP_EQL,  JP_LBRC, JP_RBRC, JP_DQUO,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, JP_LCBR, JP_RCBR, XXXXXXX,                   _______, OSM_RSFT,OSM_RCTL,OSM_RALT,OSM_RGUI,XXXXXXX,
                                            _______, _______, _______, _______, _______, _______
    ),

    // numpad
    [_NUMPAD] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX,                   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, XXXXXXX,
        _______, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   XXXXXXX,                   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
        _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   XXXXXXX,                   KC_COMM, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
                                            _______, _______, _______, _______, _______, KC_P0
    )
};

// permissive hold per key settings
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_NUM:
        case ESC_NUMP:
        case BTM_V:
        case BTM_M:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

// quick tap term per key settings
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_NUM:
        case ESC_NUMP:
            return 0;
        case HOME_A:
        case HOME_SCLN:
            return QUICK_TAP_TERM - 100;
        default:
            return QUICK_TAP_TERM;
    }
}

// Restrict oppisite hand holds by mod-tap
bool achordion_chord(uint16_t tap_hold_keycode,
                    keyrecord_t* tap_hold_record,
                    uint16_t other_keycode,
                    keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        // case BTM_SLSH:
        //     if (other_keycode == KC_H || other_keycode == KC_J || other_keycode == KC_K || other_keycode == KC_L)
        //         { return true; }
        //         break;
        case MO(_NAV):  // Allow all
        case ENT_NUM:   // Allow all
        case ESC_NUMP:  // Allow all
            return true;
    }
    switch (other_keycode) {
        case KC_SPC:
        case KC_ENT:
            return true;
    }
    // Allow same-hand holds when the other key is in the rows below the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    // if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}
