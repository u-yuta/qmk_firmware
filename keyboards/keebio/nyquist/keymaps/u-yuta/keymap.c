#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_japanese.h"

enum combos {
  DF_ESC,
  DS_TAB,
  CV_DEL,
  JK_MHEN,
  KL_HENK,
  NM_HOME,
  MCOMM_PGDN,
  COMMDOT_PGUP,
  DOTSLSH_END,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dotslsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
  [DF_ESC] = COMBO(df_combo, KC_ESC),
  [DS_TAB] = COMBO(ds_combo, KC_TAB),
  [CV_DEL] = COMBO(cv_combo, KC_DEL),
  [JK_MHEN] = COMBO(jk_combo, JP_MHEN),
  [KL_HENK] = COMBO(kl_combo, JP_HENK),
  [NM_HOME] = COMBO(nm_combo, KC_HOME),
  [MCOMM_PGDN] = COMBO(mcomm_combo, KC_PGDN),
  [COMMDOT_PGUP] = COMBO(commdot_combo, KC_PGUP),
  [DOTSLSH_END] = COMBO(dotslsh_combo, KC_END),
};

enum layer_names {
    _DEFAULT,
    // _NAV,
    _SYM,  // symbol, cursor
    _NUM,  // number, cursor
    _FUN   // function, mouse
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT_ortho_5x12(
		KC_1,         KC_2,    KC_3,    KC_4,    KC_5,          KC_ESC,    KC_DEL,      KC_6,       KC_7,     KC_8,    KC_9,   KC_0,
		KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,          KC_TAB,    KC_BSPC,     KC_Y,       KC_U,     KC_I,    KC_O,   KC_P,
		KC_A,         KC_S,    KC_D,    KC_F,    KC_G,          KC_ESC,    KC_ENT,      KC_H,       KC_J,     KC_K,    KC_L,   KC_SCLN,
		SFT_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,          SC_LSPO,   KC_LSFT,     KC_N,       KC_M,     KC_COMM, KC_DOT, KC_SLSH,
		KC_NO,        KC_LGUI, KC_LALT, KC_LCTL, SFT_T(KC_SPC), KC_BSPC,   KC_ENT,      MO(_SYM),   MO(_NUM), KC_NO,   KC_NO,  KC_RALT
	),
	[_SYM] = LAYOUT_ortho_5x12(
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,     KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        JP_EXLM,    JP_CIRC,     JP_HASH,     JP_DLR,      JP_PERC,    KC_NO,     KC_NO,     JP_EQL,   JP_UNDS,  JP_LPRN,  JP_RPRN,  JP_YEN,
        JP_QUOT,    JP_DQUO,     JP_LBRC,     JP_RBRC,     JP_ASTR,    KC_NO,     KC_NO,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  JP_COLN,
        JP_PIPE,    JP_AT,       JP_LCBR,     JP_RCBR,     JP_GRV,     KC_NO,     KC_NO,     JP_PLUS,  JP_MINS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
	),
	[_NUM] = LAYOUT_ortho_5x12(
        KC_F1,      KC_F2,       KC_F3,       KC_F4,       KC_F5,      KC_TRNS,   KC_F11,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
        JP_AMPR,    KC_7,        KC_8,        KC_9,        JP_PERC,    KC_NO,     KC_NO,    JP_EQL,   JP_UNDS,  JP_LPRN,  JP_RPRN,  JP_YEN,
        JP_QUOT,    KC_4,        KC_5,        KC_6,        JP_ASTR,    KC_NO,     KC_NO,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  JP_COLN,
        KC_0,       KC_1,        KC_2,        KC_3,        JP_TILD,    KC_NO,     KC_NO,    JP_PLUS,  JP_MINS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
	),
	[_FUN] = LAYOUT_ortho_5x12(
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,      KC_NO,     KC_NO,      KC_F10,     KC_F11,     KC_F12,     KC_NO,
        KC_NO,      KC_MS_U,     KC_NO,       KC_WH_U,     JP_PERC,    KC_NO,      KC_NO,     KC_NO,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
        KC_MS_L,    KC_MS_D,     KC_MS_R,     KC_WH_D,     JP_ASTR,    KC_NO,      KC_NO,     KC_NO,      KC_F4,      KC_F5,      KC_F6,      KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,      KC_NO,     KC_0,       KC_F1,      KC_F2,      KC_F3,      KC_NO,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_MS_BTN1,  KC_MS_BTN2, KC_MS_BTN3, KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
	)
};

// SYM + NUM -> FUN
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NUM, _FUN);
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
