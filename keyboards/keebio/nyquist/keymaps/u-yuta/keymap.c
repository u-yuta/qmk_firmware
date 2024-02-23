#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_japanese.h"

enum combos {
  DF_ESC,
  DS_TAB,
  CV_COMBO,
  HJ_COMBO,
  KL_COMBO,
  JK_COMBO,
  LCLN_COMBO,
  MCOMM_PGDN,
  COMMDOT_COMBO,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lcln_combo[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [DF_ESC] = COMBO(df_combo, KC_ESC),
  [DS_TAB] = COMBO(ds_combo, KC_TAB),
  [CV_COMBO] = COMBO(cv_combo, CW_TOGG),
  [HJ_COMBO] = COMBO(hj_combo, KC_HOME),
  [JK_COMBO] = COMBO(jk_combo, KC_BSPC),
  [KL_COMBO] = COMBO(kl_combo, KC_DEL),
  [LCLN_COMBO] = COMBO(lcln_combo, KC_END),
  [MCOMM_PGDN] = COMBO(mcomm_combo, KC_PGDN),
  [COMMDOT_COMBO] = COMBO(commdot_combo, KC_PGUP),
};

enum layer_names {
    _DEFAULT,
    // _NAV,
    _SYM,  // symbol, cursor
    _SYM2,  // symbol2, cursor
    _NUM,  // number, mouse
};

// S(KC_INT3) : JP_PIPE
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT_ortho_5x12(
        KC_1,         KC_2,    KC_3,    KC_4,           KC_5,             KC_NO,       KC_NO,       KC_6,      KC_7,        KC_8,    KC_9,   KC_0,
        KC_Q,         KC_W,    KC_E,    KC_R,           KC_T,             KC_TAB,      KC_BSPC,     KC_Y,      KC_U,        KC_I,    KC_O,   KC_P,
        KC_A,         KC_S,    KC_D,    KC_F,           KC_G,             KC_ESC,      KC_ENT,      KC_H,      KC_J,        KC_K,    KC_L,   JP_COLN,
        SFT_T(KC_Z),  KC_X,    KC_C,    KC_V,           KC_B,             SC_LSPO,     KC_LSFT,     KC_N,      KC_M,        KC_COMM, KC_DOT, RSFT_T(KC_MINS),
        KC_NO,        KC_LGUI, KC_LALT, CTL_T(JP_MHEN), LT(_SYM, KC_SPC), KC_BSPC,       KC_ENT,      MO(_SYM2), JP_HENK,     KC_NO,   KC_RALT,KC_NO
    ),
	[_SYM] = LAYOUT_ortho_5x12(
        KC_F1,       KC_F2,       KC_F3,      KC_F4,      KC_F5,      KC_F11,    KC_F12,    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
        JP_EXLM,     JP_CIRC,     JP_HASH,    JP_DLR,     JP_PERC,    KC_NO,     KC_NO,     JP_AMPR,   JP_UNDS,   JP_LPRN,   JP_RPRN,   JP_YEN,
        JP_QUOT,     JP_DQUO,     JP_LBRC,    JP_RBRC,    JP_GRV,     KC_NO,     KC_NO,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_SCLN,
        KC_LSFT,     JP_PIPE,     JP_LCBR,    JP_RCBR,    JP_TILD,    KC_NO,     KC_NO,     JP_QUES,   JP_PLUS,   KC_TRNS,   KC_TRNS,   KC_SLSH,
        KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS
	),
	[_SYM2] = LAYOUT_ortho_5x12(
        KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,      KC_F11,    KC_F12,    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
        JP_EXLM,     JP_CIRC,     JP_HASH,     JP_DLR,      JP_PERC,    KC_NO,     KC_NO,     JP_AMPR,   JP_UNDS,   JP_LPRN,   JP_RPRN,   JP_YEN,
        JP_QUOT,     JP_DQUO,     JP_LBRC,     JP_RBRC,     JP_GRV,     KC_NO,     KC_NO,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   KC_SCLN,
        CW_TOGG,     JP_AT,       JP_LCBR,     JP_RCBR,     JP_TILD,     KC_NO,     KC_NO,    JP_QUES,   JP_PLUS,   KC_TRNS,   KC_TRNS,   KC_SLSH,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS
	),
	[_NUM] = LAYOUT_ortho_5x12(
        KC_F1,      KC_F2,      KC_F3,      KC_F3,      KC_F5,       KC_F11,    KC_F12,    KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
        KC_NO,      KC_7,       KC_8,       KC_9,       KC_NO,       KC_NO,     KC_NO,     KC_WH_U,   KC_BTN1,   KC_BTN3,   KC_BTN2,   KC_WH_D,
        KC_NO,      KC_4,       KC_5,       KC_6,       KC_NO,       KC_NO,     KC_NO,     KC_MS_L,   KC_MS_D,   KC_MS_U,   KC_MS_R,   KC_NO,
        KC_0,       KC_1,       KC_2,       KC_3,       KC_NO,       KC_NO,     KC_NO,     KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,    KC_NO,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS
	)
};

// SYM + NUM -> FUN
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _SYM2, _NUM);
}

// not seem to work
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case JP_MINS:
        case JP_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
