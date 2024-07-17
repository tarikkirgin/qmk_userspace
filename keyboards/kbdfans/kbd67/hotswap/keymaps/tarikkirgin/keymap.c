#include QMK_KEYBOARD_H

// add right hyper keycode
enum custom_keycodes {
    KC_RHYPR = SAFE_RANGE,
};

// increase readability
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_PSCR,
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL,
  LCTL_T(KC_BSPC), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,      KC_PGUP,
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,       KC_RSFT,             KC_UP,   KC_PGDN,
  KC_LGUI, KC_LALT, MT(KC_RHYPR, KC_F20),                KC_SPC,                   KC_RALT, MO(1),                KC_LEFT, KC_DOWN, KC_RGHT),

[1] = LAYOUT(
  _______, KC_F1 , KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F14, _______,
  _______, KC_F15, KC_UP, KC_F16, KC_F17, KC_F18, _______, _______, _______, _______, _______, _______, _______, _______, QK_LOCK,
  _______,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_F19, TG(2), _______, _______, _______, _______, _______, _______,    _______,  KC_SCRL,
  KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, _______, QK_BOOT, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_CAPS,  KC_INS, _______,
  _______, _______, _______,                   KC_F21,                           _______, _______,   KC_HOME, KC_PAUS, KC_END),

[2] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______, _______,
  KC_LCTL, MO(1)  , KC_LALT,                   _______,                            _______, KC_RCTL,                    _______, _______, _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_RHYPR:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RGUI));
            } else {
                unregister_mods(MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSHIFT) | MOD_BIT(KC_RALT) | MOD_BIT(KC_RGUI));
            }
            return false;
    }
    return true;
}

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
    return false;
  }
  switch (detected_os) {
  case OS_MACOS:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
    break;
  case OS_IOS:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
    break;
  case OS_WINDOWS:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
    break;
  case OS_LINUX:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
    break;
  case OS_UNSURE:
    keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
    break;
  }
  return true;
}
#endif
