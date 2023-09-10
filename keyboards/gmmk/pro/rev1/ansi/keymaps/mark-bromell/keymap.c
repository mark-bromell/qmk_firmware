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

#include "os_detection.h"
#include "alias.h"
#include "features/custom_shift_keys.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// To put the keyboard into boot loader mode, press the key directly to the left of the rotary knob.
// To reset the keyboard, hold the traditional caps-lock key and then then press the boot loader key (key next to the rotary knob)

    [BASE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          KC_MUTE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        KC_UNDS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,  ALT_TAB,          XXXXXXX,
        MOD_TAB, KC_A,    MOD_S,   MOD_D,   MOD_F,   MOD_G,   MOD_H,   MOD_J,   MOD_K,   MOD_L,   KC_DQUO, KC_ENT,           KC_ESC,           XXXXXXX,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    MOD_V,   KC_B,    KC_N,    MOD_M,   KC_COMM, KC_DOT,  KC_SLASH,         KC_RSFT, XXXXXXX, XXXXXXX,
        KC_LGUI, NO_IMPL, TG(NUM),                            KC_SPC,                             TG(NAV), NO_IMPL, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [SYM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        _______, KC_BSLS, KC_LABK, KC_RABK, KC_SCLN, KC_AT,   KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_GRV,  W_BACK,  W_DEL,   KC_CAPS,          XXXXXXX,
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH, KC_AMPR, KC_COLN, KC_LPRN, KC_RPRN, KC_QUOT, END_SCL,          VI_SAVE,          XXXXXXX,
        NO_IMPL,          KC_PERC, KC_SLSH, KC_ASTR, KC_CIRC, UPDIR,   KC_PIPE, COLON_2, KC_LBRC, KC_RBRC, KC_QUES,          NO_IMPL, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______,                            _______,                            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        KC_DLR,  KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, EURO,             XXXXXXX,
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH, KC_AMPR, KC_COLN, KC_LPRN, KC_RPRN, KC_QUOT, _______,          _______,          XXXXXXX,
        KC_COMM,          KC_PERC, KC_SLSH, KC_ASTR, KC_CIRC, UPDIR,   KC_PIPE, COLON_2, KC_LBRC, KC_RBRC, KC_QUES,          KC_DOT,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______,                            _______,                            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, MV_EXIT, MV_XTAB, MY_EDIT, MY_REDO, MV_NTAB, NO_IMPL, KC_PGUP, KC_PGDN, NO_IMPL, NO_IMPL, _______, _______, XXXXXXX,          XXXXXXX,
        _______, MY_SALL, MY_SAVE, NO_IMPL, MY_FIND, MY_FNXT, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_TAB,  _______,          _______,          XXXXXXX,
        KC_LSFT,          MY_UNDO, NO_IMPL, MY_COPY, MY_PSTE, NO_IMPL, KC_HOME, W_LEFT,  W_RIGHT, KC_END,  NO_IMPL,          KC_RSFT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______,                            _______,                            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [FUN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        SEE_ALL, MV_2TL,  MV_1TR,  MV_L,    MV_R,    NO_IMPL, WINDOWS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   NO_IMPL, NO_IMPL, QK_BOOT,          XXXXXXX,
        WS_LEFT, KC_F16,  KC_F15,  KC_F14,  KC_F13,  KC_F17,  MAC,     KC_F5,   KC_F6,   KC_F7,   KC_F8,   WS_NEW,           WS_RGHT,          XXXXXXX,
        KC_MEH,           NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, MV_PTAB, MV_NTAB, KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_MEH,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______,                            MV_FULL,                            _______, XXXXXXX, MY_DEBG, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
// clang-format on


const custom_shift_key_t custom_shift_keys[] = {
    {KC_DQUO, NO_IMPL},
    {KC_SLASH, NO_IMPL},
    {KC_DOT, NO_IMPL},
    {KC_COMMA, NO_IMPL},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


#define IS_MACOS detected_host_os() == OS_MACOS
#define IS_WINDOWS detected_host_os() == OS_WINDOWS
#define IS_LINUX detected_host_os() == OS_LINUX
#define IS_IOS detected_host_os() == OS_IOS
#define IS_USURE detected_host_os() == OS_UNSURE

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    if(record->event.pressed) {
        switch (keycode) {
            case UPDIR:
                SEND_STRING("../");
                return false;
            case COLON_2:
                SEND_STRING("::");
                return false;
            case DOT_3:
                SEND_STRING("...");
                return false;
            case QUOTE_3:
                SEND_STRING("\"\"\"");
                return false;
            case GRAVE_3:
                SEND_STRING("```");
                return false;
            case WALRUS:
                SEND_STRING(":=");
                return false;
            case EURO:
                SEND_STRING("€");
                return false;
            case END_SCL:
                tap_code16_delay(KC_END, 10);
                SEND_STRING(";");
                return false;
            case VI_SAVE:
                tap_code16_delay(KC_ESCAPE, 10);
                SEND_STRING_DELAY(":", 10);
                SEND_STRING("w");
                return false;

            case W_BACK:
                tap_code16((IS_MACOS) ? LOPT(KC_BACKSPACE) : LCTL(KC_BACKSPACE));
                return false;
            case W_DEL:
                tap_code16((IS_MACOS) ? LOPT(KC_DELETE) : LCTL(KC_DELETE));
                return false;
            case W_LEFT:
                tap_code16((IS_MACOS) ? LOPT(KC_LEFT) : LCTL(KC_LEFT));
                return false;
            case W_RIGHT:
                tap_code16((IS_MACOS) ? LOPT(KC_RIGHT) : LCTL(KC_RIGHT));
                return false;

            case MY_UNDO:
                tap_code16((IS_MACOS) ? LCMD(KC_Z) : LCTL(KC_Z));
                return false;
            case MY_REDO:
                tap_code16((IS_MACOS) ? LCMD(LSFT(KC_Z)) : LCTL(KC_Y));
                return false;
            case MY_COPY:
                tap_code16((IS_MACOS) ? LCMD(KC_C) : LCTL(KC_INSERT));
                return false;
            case MY_PSTE:
                tap_code16((IS_MACOS) ? LCMD(KC_V) : LSFT(KC_INSERT));
                return false;
            case MY_SALL:
                tap_code16((IS_MACOS) ? LCMD(KC_A) : LCTL(KC_A));
                return false;
            case MY_SAVE:
                tap_code16((IS_MACOS) ? LCMD(KC_S) : LCTL(KC_S));
                return false;
            case MY_FIND:
                tap_code16((IS_MACOS) ? LCMD(KC_F) : LCTL(KC_F));
                return false;
            case MY_FNXT:
                tap_code16((IS_MACOS) ? LCMD(KC_G) : LCTL(KC_G));
                return false;
            case MY_EDIT:
                tap_code16((IS_MACOS) ? LCMD(KC_E) : LCTL(KC_E));
                return false;

            case MV_FULL:
                tap_code16((IS_MACOS) ? LGUI(LCTL(KC_F)) : KC_F11);
                return false;
            case MV_L:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_LEFT));
                } else {
                    tap_code16(LCAG(KC_0));
                    tap_code16(LWIN(KC_LEFT));
                }
                return false;
            case MV_R:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_RIGHT));
                } else {
                    tap_code16(LCAG(KC_0));
                    tap_code16(LWIN(KC_RIGHT));
                }
                return false;
            case MV_2TL:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_G));
                } else {
                    tap_code16(LCAG(KC_1));
                    tap_code16(LWIN(KC_LEFT));
                }
                return false;
            case MV_1TR:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_H));
                } else {
                    tap_code16(LCAG(KC_1));
                    tap_code16(LWIN(KC_RIGHT));
                }
                return false;
            case MV_EXIT:
                tap_code16((IS_MACOS) ? LCMD(KC_Q) : LALT(KC_F4));
                return false;
            case MV_XTAB:
                tap_code16((IS_MACOS) ? LCMD(KC_W) : LCTL(KC_W));
                return false;
            case MV_NTAB:
                tap_code16((IS_MACOS) ? LCMD(LSFT(KC_RBRC)) : LCTL(LSFT(KC_RBRC)));
                return false;
            case MV_PTAB:
                tap_code16((IS_MACOS) ? LCMD(LSFT(KC_LBRC)) : LCTL(LSFT(KC_LBRC)));
                return false;
            case SEE_ALL:
                tap_code16((IS_MACOS) ? KC_MISSION_CONTROL : LWIN(KC_TAB));
                return false;

            case WS_LEFT:
                tap_code16((IS_MACOS) ? LCTL(KC_LEFT) : LWIN(LCTL(KC_LEFT)));
                return false;
            case WS_RGHT:
                tap_code16((IS_MACOS) ? LCTL(KC_RIGHT) : LWIN(LCTL(KC_RIGHT)));
                return false;
            case WS_NEW:
                tap_code16((IS_MACOS) ? KC_MISSION_CONTROL : LWIN(LCTL(KC_D)));
                return false;
        }
    }
    return true;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
