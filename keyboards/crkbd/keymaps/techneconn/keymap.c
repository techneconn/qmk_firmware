/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// defined by techneconn
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NUMBER,
  _ADJUST
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE, // Reset Lighting
  LOWEI, // Tap Eisu or Hold LOWER
  RAIKN, // Tap Kana or Hold RAISE
  ADJSP, // Tap Space or Hold ADJUST
  CTLES, // Tap ESC+Eisu or Hold Ctrl
  HELLO  // Output Hello World
};
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
#define SFBS SFT_T(KC_BSLS)
#define GUILB GUI_T(KC_LBRC)
#define ALTRB ALT_T(KC_RBRC)
#define RGUIQT RGUI_T(KC_QUOT)
#define RALTEQ RALT_T(KC_EQL)

#define NUMET LT(_NUMBER, KC_ENT)
// #define ADJSP LT(_ADJUST, KC_SPC) // does't work for helix: achieved by process_record_user

#define DT_L LGUI(LCTL(KC_LEFT)) // Win + Ctrl + ←
#define DT_R LGUI(LCTL(KC_RIGHT))  // Win + Ctrl + →
#define DT_V LGUI(KC_TAB)  // Win + TAB
#define ALLB LALT(KC_LBRC)  // Alt + [
#define ALRB LALT(KC_RBRC)  // Alt + ]
#define BLANK TG(_BLANK)
#define A_S_O LALT(LSFT(KC_O))  // Alt + Shift + O

// techneconn for cocot46plus
#define MOUSE MO(_TRACKBALL)
#define NUMBER MO(_NUMBER)

#define LW_MHEN LT(_LOWER,KC_MHEN)  // lower
#define RS_HENK LT(_RAISE,KC_HENK)  // raise
#define DEL_ALT ALT_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------.                    |--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     GUILB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    SFSC,    RGUIQT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ALTRB,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         CTLES,   SFSP,    LOWEI,      RAIKN,   NUMET,   ADJSP
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_DEL,  KC_BSPC, KC_UP,   KC_BTN4, KC_BTN5,                      DT_L,    DT_R,    DT_V,    ALLB,    ALRB,    A_S_O,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, CT_A,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_ENT,                       XXXXXXX, KC_GRV,  KC_TILD, KC_PIPE, SFBS,    _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, CT_Z,    CT_X,    CT_C,    CT_V,    KC_SPC,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_PGDN, KC_PGUP, KC_UP,   KC_BSPC, KC_DEL,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                      KC_ENT,  KC_LEFT, KC_DOWN, KC_RIGHT,CT_A,    _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, DM_REC1, DM_REC2, DM_RSTP, DM_PLY1, DM_PLY2,                      KC_SPC,  CT_V,    CT_C,    CT_X,    CT_Z,    _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMBER] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,  XXXXXXX,                       KC_ASTR, KC_P7,   KC_P8,   KC_P9,   KC_BSPC, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_F10,  KC_F4,   KC_F5,   KC_F6,   KC_F11,                       KC_ENT,  KC_P4,   KC_P5,   KC_P6,   KC_P0,   KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,                       KC_SLSH, KC_P1,   KC_P2,   KC_P3,   KC_DOT,  KC_COMM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------.                    |--------+--------+--------+--------+--------+--------|
     RGBRST,  RGB_RMOD,RGB_HUI, RGB_SAI, RGB_VAI, RESET,                        KC_NLCK, KC_PSCR, KC_PGUP, XXXXXXX, XXXXXXX, CAD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_TOG, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      KC_CAPS, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define PROCESS_OVERRIDE_BEHAVIOR (false)
#define PROCESS_USUAL_BEHAVIOR (true)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    static uint16_t mem_keycode;
    uint16_t        prev_keycode = mem_keycode;
    bool            is_tapped    = ((!record->event.pressed) && (keycode == prev_keycode));
    mem_keycode                  = keycode;

    switch (keycode) {
        // defined by techneconn
        case RGBRST:
        #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
        #endif
        break;
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
        case HELLO: {
            if (record->event.pressed) {
                SEND_STRING("Hello, world.");
            }
        }
        break;
        default: {}
        break;
    }
    return PROCESS_USUAL_BEHAVIOR;
}
#endif // OLED_ENABLE
