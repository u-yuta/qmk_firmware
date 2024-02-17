#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_japanese.h"

enum combos {
  DF_ESC,
  DS_TAB,
  CV_DEL,
  JK_MHEN,
  KL_HENK,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
  [DF_ESC] = COMBO(df_combo, KC_ESC),
  [DS_TAB] = COMBO(ds_combo, KC_TAB),
  [CV_DEL] = COMBO(cv_combo, KC_DEL),
  [JK_MHEN] = COMBO(jk_combo, JP_MHEN),
  [KL_HENK] = COMBO(kl_combo, JP_HENK),
};

enum layer_names {
    _DEFAULT,
    _NAV,
    _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT_ortho_5x12(
		KC_1,         KC_2,    KC_3,    KC_4,    KC_5,          KC_ESC,    KC_DEL,      KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    
		KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,          KC_TAB,    KC_BSPC,     KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,    
		KC_A,         KC_S,    KC_D,    KC_F,    KC_G,          KC_ESC,    KC_ENT,      KC_H,       KC_J,    KC_K,    KC_L,   KC_SCLN, 
		SFT_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,          SC_LSPO,   KC_LSFT,     KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, 
		MO(3),        KC_LGUI, KC_LALT, KC_LCTL, SFT_T(KC_SPC), KC_BSPC,   KC_ENT,      MO(1),      MO(2),   KC_NO,   KC_NO,  KC_RALT
	),
	[_NAV] = LAYOUT_ortho_5x12(
		KC_TRNS, KC_F1,      KC_F2,         KC_F3,          KC_F4,          KC_F5,         KC_F11,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                  
		KC_TRNS, LSFT(KC_1), KC_LBRC,       LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),    KC_TRNS,   KC_EQL,   JP_AMPR,  JP_ASTR,  JP_LPRN,  JP_RPRN,       
		KC_TRNS, LSFT(KC_7), LSFT(KC_2),    KC_RBRC,        KC_NUHS,        JP_GRV,        KC_TRNS,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_QUOT,              
		KC_TRNS, JP_UNDS,    LSFT(KC_MINS), LSFT(KC_RBRC),  LSFT(KC_NUHS),  LSFT(KC_EQL),  KC_TRNS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INT1,               
		KC_TRNS, KC_TRNS,    KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,   KC_TRNS,  KC_INT4,  KC_TRNS,  KC_TRNS,  KC_TRNS
	),
	[_NUM] = LAYOUT_ortho_5x12(
		KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   
		JP_ASTR,  KC_7,     KC_8,     KC_9,     KC_SLSH,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   
		JP_PLUS,  KC_4,     KC_5,     KC_6,     KC_MINS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   
		KC_0,     KC_1,     KC_2,     KC_3,     JP_UNDS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
	)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

