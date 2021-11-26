/* Copyright 2020 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  ADJUST,
  RGBRST,
  // defined by yuukive
  LOWEI, // Tap Eisu or Hold LOWER
  RAIKN, // Tap Kana or Hold RAISE
  ADJSP, // Tap Space or Hold ADJUST
  CTLES  // Tap ESC+Eisu or Hold Ctrl
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// defined by yuukive
#define CAD LCTL(LALT(KC_DEL)) // Ctrl + Alt + Del
#define CTLBC LCTL(KC_LBRC)
#define CTRBC LCTL(KC_RBRC)
#define CT_Z LCTL(KC_Z)
#define CT_X LCTL(KC_X)
#define CT_C LCTL(KC_C)
#define CT_V LCTL(KC_V)
#define CT_A LCTL(KC_A)

#define SFSP SFT_T(KC_SPC)
#define SFSC SFT_T(KC_SCLN)
#define GUILB GUI_T(KC_LBRC)
#define ALTRB ALT_T(KC_RBRC)
#define RGUIQT RGUI_T(KC_QUOT)
#define RALTEQ RALT_T(KC_EQL)

#define LOWET LT(_LOWER, KC_ENT)
// #define ADJSP LT(_ADJUST, KC_SPC) // does't work for helix: achieved by process_record_user




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        GUILB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    SFSC,    RGUIQT, \
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        ALTRB,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   RAISE,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RALTEQ, \
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, KC_LALT, KC_LGUI, _______, CTLES,   SFSP,    LOWEI,   RAIKN,   LOWET,   ADJSP,   _______, KC_RGUI, KC_RALT, _______ \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
    ),

  [_LOWER] = LAYOUT( \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, KC_DEL,  KC_BSPC, KC_UP,   CTLBC,   CTRBC,                     KC_ASTR, KC_P7,   KC_P8,   KC_P9,   KC_BSPC, KC_MINS,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, CT_A,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_ENT,                    KC_ENT,  KC_P4,   KC_P5,   KC_P6,   KC_P0,   KC_PLUS,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, CT_Z,    CT_X,    CT_C,    CT_V,    KC_SPC,  _______, _______, KC_SLSH, KC_P1,   KC_P2,   KC_P3,   KC_DOT,  KC_COMM,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
      ),

  [_RAISE] = LAYOUT( \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_F12,  KC_BSLS, KC_UP,   KC_BSPC, KC_DEL,  KC_GRV, \
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                   KC_ENT,  KC_LEFT, KC_DOWN, KC_RIGHT,KC_TILD, KC_PIPE,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
      ),

  [_ADJUST] =  LAYOUT( \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        RGBRST,  RGB_RMOD,RGB_HUI, RGB_SAI, RGB_VAI, RESET,                     KC_NLCK, KC_CAPS, KC_PGUP, XXXXXXX, XXXXXXX, CAD,    \
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        RGB_TOG, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                   KC_PSCR, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    AG_NORM, AG_SWAP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,\
    // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    // .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
      )

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define PROCESS_OVERRIDE_BEHAVIOR (false)
#define PROCESS_USUAL_BEHAVIOR (true)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t mem_keycode;
    uint16_t        prev_keycode = mem_keycode;
    bool            is_tapped    = ((!record->event.pressed) && (keycode == prev_keycode));
    mem_keycode                  = keycode;

    switch (keycode) {
        case EISU:
        if (record->event.pressed) {
            if (is_mac_mode()) {
                register_code(KC_LANG2);
            }else{
                tap_code16(LALT(KC_GRAVE));
            }
        } else {
            unregister_code(KC_LANG2);
        }
        return PROCESS_OVERRIDE_BEHAVIOR;
        break;
        case KANA:
        if (record->event.pressed) {
            if (is_mac_mode()) {
                register_code(KC_LANG1);
            }else{
                tap_code16(LALT(KC_GRAVE));
            }
        } else {
            unregister_code(KC_LANG1);
        }
        return PROCESS_OVERRIDE_BEHAVIOR;
        break;
        case ADJUST:
        if (record->event.pressed) {
            layer_on(_LOWER);
            layer_on(_RAISE);
        } else {
            layer_off(_LOWER);
            layer_off(_RAISE);
        }
        break;
        case RGBRST:
        #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
        #endif
        break;
        // defined by yuukive
        case LOWEI: {
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
                if (is_tapped) {
                    tap_code(KC_MHEN);
                    tap_code(KC_LANG2);
                }
            }
            return PROCESS_OVERRIDE_BEHAVIOR;
        }
        break;
        case RAIKN: {
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
                if (is_tapped) {
                    tap_code(KC_HENK);
                    tap_code(KC_LANG1);
                }
            }
            return PROCESS_OVERRIDE_BEHAVIOR;
        }
        break;
        case ADJSP: {
            if (record->event.pressed) {
                layer_on(_RAISE);
                layer_on(_LOWER);
            } else {
                layer_off(_RAISE);
                layer_off(_LOWER);
                if (is_tapped) {
                    tap_code(KC_SPC);
                }
            }
            return PROCESS_OVERRIDE_BEHAVIOR;
        }
        break;
        case CTLES: {
            if (record->event.pressed) {
                register_code(KC_LCTRL);
            } else {
                unregister_code(KC_LCTRL);
                if (is_tapped) {
                    tap_code(KC_ESC);
                    tap_code(KC_MHEN);
                    tap_code(KC_LANG2);
                }
            }
            return PROCESS_OVERRIDE_BEHAVIOR;
        }
        break;
        default: {}
        break;
    }
    return PROCESS_USUAL_BEHAVIOR;
}
