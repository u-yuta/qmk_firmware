#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_japanese.h"
#include "features/achordion.h"

enum combos {
  DF_COMBO,
  FJ_COMBO,
  HJ_COMBO,
  JK_COMBO,
  KL_COMBO,
  LSCLN_COMBO,
  MCOMM_PGDN,
  COMMDOT_COMBO,
};

const uint16_t PROGMEM df_combo[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM fj_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {RALT_T(KC_L), RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [DF_COMBO] = COMBO(df_combo, KC_ESC),
  [FJ_COMBO] = COMBO(fj_combo, CW_TOGG),
  [HJ_COMBO] = COMBO(hj_combo, KC_HOME),
  [JK_COMBO] = COMBO(jk_combo, KC_BSPC),
  [KL_COMBO] = COMBO(kl_combo, KC_DEL),
  [LSCLN_COMBO] = COMBO(lscln_combo, KC_END),
  [MCOMM_PGDN] = COMBO(mcomm_combo, KC_PGDN),
  [COMMDOT_COMBO] = COMBO(commdot_combo, KC_PGUP),
};

enum layer_names {
    _DEFAULT,
    _SYM,  // symbol
    _NAV,  // nav
    _NUM   // number, function
};

// S(KC_INT3) : JP_PIPE
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT_ortho_5x12(
        KC_NO,      KC_1,        KC_2,        KC_3,        KC_4,        KC_5,            KC_6,    KC_7,        KC_8,        KC_9,        KC_0,           KC_DEL,
        KC_TAB,     KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,            KC_Y,    KC_U,        KC_I,        KC_O,        KC_P,           KC_MINS,
        KC_ESC,     LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,            KC_H,    RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN),KC_ENT,
        KC_LSFT,    KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,            KC_N,    KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,        KC_RSFT,
        KC_BSPC,    KC_NO,       KC_LGUI,     KC_LALT,     JP_MHEN,     LT(_NAV, KC_SPC),MO(_SYM),JP_HENK,     KC_RCTL,     KC_RALT,     KC_NO,          KC_ENT
    ),
	[_SYM] = LAYOUT_ortho_5x12(
        KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,    KC_F12,
        KC_TRNS,    JP_EXLM,    JP_DQUO,    JP_LBRC,    JP_RBRC,    JP_PERC,    KC_NO,      JP_AMPR,    JP_ASTR,    JP_EQL,     JP_YEN,    KC_TRNS,
        KC_TRNS,    JP_UNDS,    JP_QUOT,    JP_LPRN,    JP_RPRN,    JP_AT,      KC_LEFT,    KC_RSFT,    KC_RCTL,    KC_RGHT,    JP_COLN,   KC_TRNS,
        KC_TRNS,    JP_CIRC,    JP_DLR,     JP_LCBR,    JP_RCBR,    JP_HASH,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      JP_MINS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS
	),
	[_NAV] = LAYOUT_ortho_5x12(
        KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,    KC_F12,
        KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_BSPC,    KC_DEL,     KC_NO,     KC_TRNS,
        KC_TRNS,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,      KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,     KC_TRNS,
        KC_TRNS,    C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    KC_NO,      KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS
	)
};

// SYM + NAV -> NUM
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }

    return true;
}
void matrix_scan_user(void) {
    achordion_task();
}
