#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_japanese.h"
#include "features/achordion.h"

enum layer_names {
    _DEFAULT,
    _NAV,
    _NUM,
    _SYM,
    _SYM2,
    _MOUSE
};

// Alias -- home row
#define HOME_A LT(_SYM, KC_A)
#define HOME_S KC_S
#define HOME_D KC_D
#define HOME_F KC_F
#define HOME_J KC_J
#define HOME_K KC_K
#define HOME_L KC_L
#define HOME_SCLN LT(_SYM2, KC_SCLN)
// Alias -- bottom row
#define BTM_Z KC_Z
#define BTM_C CTL_T(KC_C)
#define BTM_V SFT_T(KC_V)
#define BTM_B KC_B
#define BTM_N KC_N
#define BTM_M SFT_T(KC_M)
#define BTM_COMM CTL_T(KC_COMM)
#define BTM_SLSH KC_SLSH


// Alias -- Mod-Tap
#define SPC_NUM LT(_NUM, KC_SPC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
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
    RT_COMBO,
    SD_COMBO,
    DF_COMBO,
    ZX_COMBO,
    XC_COMBO,
    CV_COMBO,
    ZC_COMBO,
    ZV_COMBO,
    FG_COMBO,
    HJ_COMBO,
    JK_COMBO,
    KL_COMBO,
    LSCLN_COMBO,
    COMMDOT_COMBO,
    DOTSLSH_COMBO,
};

const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {HOME_S, HOME_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {BTM_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, BTM_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {BTM_C, BTM_V, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {HOME_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, HOME_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {HOME_L, HOME_SCLN, COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {BTM_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dotslsh_combo[] = {KC_DOT, BTM_SLSH, COMBO_END};

combo_t key_combos[] = {
    [RT_COMBO] = COMBO(rt_combo, CW_TOGG),
    [SD_COMBO] = COMBO(sd_combo, KC_TAB),
    [DF_COMBO] = COMBO(df_combo, MO(_NAV)),
    [ZX_COMBO] = COMBO(zx_combo, KC_LGUI),
    [XC_COMBO] = COMBO(xc_combo, KC_LALT),
    [FG_COMBO] = COMBO(fg_combo, JP_MHEN),
    [HJ_COMBO] = COMBO(hj_combo, JP_HENK),
    [JK_COMBO] = COMBO(jk_combo, MO(_MOUSE)),
    [KL_COMBO] = COMBO(kl_combo, KC_DEL),
    [LSCLN_COMBO] = COMBO(lscln_combo, JP_COLN),
    [COMMDOT_COMBO] = COMBO(commdot_combo, KC_RALT),
    [DOTSLSH_COMBO] = COMBO(dotslsh_combo, KC_RGUI),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT_ortho_5x12(
        TO(0),      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_MINS,
        KC_ESC,     HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,       KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_SCLN,  KC_BSPC,
        KC_LSFT,    BTM_Z,      KC_X,       BTM_C,      BTM_V,      BTM_B,      BTM_N,      BTM_M,      BTM_COMM,   KC_DOT,     BTM_SLSH,   KC_RSFT,
        KC_LCTL,    XXXXXXX,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_SPC,     KC_ENT,     MO(_NAV),   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT
    ),
    // navigation + number + function
	[_NAV] = LAYOUT_ortho_5x12(
        _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    XXXXXXX,    KC_F12,
        _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    XXXXXXX,    _______,
        _______,    OSM_LGUI,   OSM_LALT,   OSM_LCTL,   OSM_LSFT,   XXXXXXX,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     XXXXXXX,    XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
	),
    // symbol 1
	[_SYM] = LAYOUT_ortho_5x12(
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    JP_CIRC,    JP_AMPR,    JP_ASTR,    JP_PIPE,    XXXXXXX,    XXXXXXX,
        _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    JP_QUOT,    JP_LPRN,    JP_RPRN,    JP_YEN,     JP_COLN,    _______,
        _______,    OSM_RGUI,   OSM_LALT,   OSM_LCTL,   OSM_LSFT,   XXXXXXX,    XXXXXXX,    JP_GRV,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
	),
    // symbol 2
	[_SYM2] = LAYOUT_ortho_5x12(
        KC_F11,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F12,
        _______,    JP_EXLM,    JP_AT,      JP_HASH,    JP_DLR,     JP_PERC,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    JP_UNDS,    JP_EQL,     JP_LBRC,    JP_RBRC,    JP_DQUO,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,
        _______,    _______,    JP_TILD,    JP_LCBR,    JP_RCBR,    XXXXXXX,    _______,    OSM_RSFT,   OSM_RCTL,   OSM_RALT,   OSM_RGUI,   XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
	),
    // mouse
	[_MOUSE] = LAYOUT_ortho_5x12(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    KC_WH_L,    KC_MS_U,    KC_WH_R,    KC_WH_U,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_D,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    XXXXXXX,    KC_BTN1,    KC_BTN3,    KC_BTN2,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
	)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUM, _MOUSE);
}

// settings for CAPS_WORD
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // treat as tap of Mod-Tap when no other keys are tapped while holding
        // (did not work)
        // case HOME_A:
        // case HOME_S:
        // case HOME_L:
        // case HOME_SCLN:
        //     return -1;
        default:
            return TAPPING_TERM;
    }
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// Restrict oppisite hand holds by mod-tap
bool achordion_chord(uint16_t tap_hold_keycode,
                    keyrecord_t* tap_hold_record,
                    uint16_t other_keycode,
                    keyrecord_t* other_record) {

    switch (tap_hold_keycode) {
        // case HOME_D:
        //     // Allow HOME_D + W
        //     if (other_keycode == KC_W || other_keycode == KC_SPC || other_keycode == SPC_NUM) { return true; }
        //         break;
        case BTM_SLSH:
            if (other_keycode == KC_H || other_keycode == KC_J || other_keycode == KC_K || other_keycode == KC_L)
                { return true; }
                break;
        case MO(_NAV):  // Allow all
        case MO(_NUM):  // Allow all
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
