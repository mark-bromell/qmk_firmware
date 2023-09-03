/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

#include "features/custom_shift_keys.h"

#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

enum custom_keycodes {
    MAC = SAFE_RANGE,
    CTL_CMD, // Ctrl or Cmd
    CTL_OPT, // Ctrl or Opt

    ARROW,
    EARROW,
    UPDIR,
};

#define xxxxxxx = _______ // Not free for mapping for ergonomic or logical reasons

// Window Management
#define ALT_TAB = LALT(KC_TAB)
// MacOS
#define MV_MAX = LCA(KC_ENTER)     // Maximize window
#define MV_BAK = LCA(KC_BACKSPACE) // Undo window change
#define MV_SPL = LCA(KC_LEFT)      // Split left
#define MV_SPR = LCA(KC_RIGHT)     // Split right
#define MV_BIG = LCA(KC_EQUAL)     // Make window bigger
#define MV_SML = LCA(KC_MINUS)     // Make window smaller
#define MV_THL = LCA(KC_G)         // 2 thirds on the left
#define MV_THR = LCA(KC_H)         // 1 third on the right
#define MV_TOP = KC_LSFT
#define MV_BOT = KC_LGUI
#define MV_VEW = KC_MCTL           // Mission control
#define MV_LWS = LCTL(KC_LEFT)     // Previous workspace
#define MV_RWS = LCTL(KC_RIGHT)    // Next workspace
// Windows
#define W_LWS = LGUI(LCTL(KC_LEFT))
#define W_RWS = LGUI(LCTL(KC_RIGHT))\


// User config
typedef union {
    uint32_t raw;
    struct {
        bool macos :1;
    };
} user_config_t;
user_config_t user_config;


// clang-format off
#define BASE_LAYOUT = LAYOUT( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          KC_MUTE, \
        KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,  KC_DEL,  KC_BSPC,          _______, \
        KC_LCTL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCTL, KC_TAB,  ALT_TAB,          _______, \
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_DQUO, MO(3),            KC_ENT,           MV_BIG, \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,         KC_RSFT, MV_MAX,  MV_SML, \
        KC_LALT, _______, KC_LGUI,                            KC_SPC,                             KC_RGUI, _______, KC_RALT, MV_SPL,  MV_BAK,  MV_SPR \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// To put the keyboard into boot loader mode, press the key directly to the left of the rotary knob.
// To reset the keyboard, hold the traditional caps-lock key and then then press the boot loader key (key next to the rotary knob)

    // Right symbols
    [0] = BASE_LAYOUT,
    [1] = LAYOUT(
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, QK_RBT,           xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______,
        KC_TRNS, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, KC_RALT, KC_TRNS, MV_VEW,           _______,
        xxxxxxx, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, KC_HASH, KC_LPRN, KC_RPRN, KC_COLN, KC_ESC,  _______,          _______,          _______,
        KC_TRNS,          CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, KC_PERC, KC_DLR,  ARROW,   EARROW,  _______,          MV_RWS,  KC_LSFT, _______,
        KC_TRNS, xxxxxxx, MO(5),                              _______,                            xxxxxxx, xxxxxxx, xxxxxxx, MV_THL,  KC_LGUI, MV_THR
    ),

    // Left symbols
    [2] = BASE_LAYOUT,
    [3] = LAYOUT(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        _______, KC_CIRC, KC_PLUS, KC_LBRC, KC_RBRC, KC_AT,   CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, KC_TRNS, xxxxxxx, xxxxxxx,          xxxxxxx,
        _______, KC_MINS, KC_EQL,  KC_ASTR, KC_UNDS, KC_AMPR, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, xxxxxxx,          xxxxxxx,          xxxxxxx,
        MV_LWS,           KC_TILD, KC_EXLM, KC_LABK, KC_RABK, UPDIR,   CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD,          KC_TRNS, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx,                            _______,                            _______, xxxxxxx, KC_TRNS, xxxxxxx, xxxxxxx, xxxxxxx
    ),

    // Navigation
    [4] = LAYOUT(
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_PGUP, KC_PGDN, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, xxxxxxx, xxxxxxx,          xxxxxxx,          xxxxxxx,
        KC_LSFT,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_LEFT, KC_RGHT, KC_END,  xxxxxxx, xxxxxxx,          xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx,                            _______,                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx
    ),
    [5] = LAYOUT(
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, xxxxxxx, xxxxxxx,          xxxxxxx,          xxxxxxx,
        KC_TRNS,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_TRNS, CTL_OPT, CTL_OPT, KC_TRNS, xxxxxxx, xxxxxxx,          xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx,                            KC_TRNS,                            xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx
    ),
};
// clang-format on

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DQUO, KC_SEMICOLON},
    {KC_COMMA, KC_QUOTE},
    {KC_DOT, KC_GRAVE},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
        case MAC: // MacOS toggle
            if(record->event.pressed) {
                user_config.macos ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
            break;

        case CTL_CMD:
            if(record->event.pressed) {
                register_code16((user_config.macos) ? LGUI(KC_TRNS) : LCTL(KC_TRNS));
            } else {
                unregister_code16((user_config.macos) ? LGUI(KC_TRNS) : LCTL(KC_TRNS));
            }
            return false;
            break;

        case CTL_OPT:
            if(record->event.pressed) {
                register_code16((user_config.macos) ? LOPT(KC_TRNS) : LCTL(KC_TRNS));
            } else {
                unregister_code16((user_config.macos) ? LOPT(KC_TRNS) : LCTL(KC_TRNS));
            }
            return false;
            break;

        case ARROW:
            SEND_STRING("->");
            break;

        case EARROW:
            SEND_STRING("=>");
            break;

        case UPDIR:
            SEND_STRING("../")
            break;
    }
  return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
