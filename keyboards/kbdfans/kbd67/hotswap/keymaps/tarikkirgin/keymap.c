#include QMK_KEYBOARD_H

// increase readability
#define _______ KC_TRNS
#define RHYP_T(kc) MT(MOD_RCTL | MOD_RSFT | MOD_RALT | MOD_RGUI, kc)

enum layers {
    _DEFAULT,
    _FN,
    _MAC,
    _GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV, KC_PSCR,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,
        LCTL_T(KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MAC] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV, KC_PSCR,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,
        LGUI_T(KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
        KC_LCTL, KC_LALT, RHYP_T(KC_ESC), KC_SPC, KC_RALT, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14, _______,
        _______, KC_F15, KC_UP, KC_F16, KC_F17, KC_F18, _______, _______, _______, _______, _______, _______, _______, _______, QK_LOCK,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F19, TG(_GAME), _______, _______, _______, _______, _______, _______, _______, KC_SCRL,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, QK_BOOT, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_INS,
        _______, _______, _______, KC_F20, _______, _______, KC_HOME, KC_PAUS, KC_END
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, MO(_FN), KC_LALT, _______, _______, KC_RCTL, _______, _______, _______
    )
};

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    switch (detected_os) {
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
            default_layer_set(1UL << _DEFAULT);
            break;

        case OS_MACOS:
        case OS_IOS:
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
            default_layer_set(1UL << _MAC);
            break;
    }

    return true;
}
#endif
