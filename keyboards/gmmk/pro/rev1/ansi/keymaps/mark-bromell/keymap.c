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

#include "alias.h"
#include "features/custom_shift_keys.h"

// clang-format off
#define BASE_LAYOUT LAYOUT( \
        MV_FULL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, QK_BOOT,          KC_MUTE, \
        KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,  KC_DEL,  KC_BSPC,          NO_IMPL, \
        KC_LCTL, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CTL_ESC, KC_TAB,  ALT_TAB,          NO_IMPL, \
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_DQUO, MO(3),            KC_ENT,           NO_IMPL, \
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,         KC_RSFT, KC_UP,   NO_IMPL, \
        KC_LALT, WINDOWS, KC_LGUI,                            KC_SPC,                             KC_RGUI, MAC,     KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// To put the keyboard into boot loader mode, press the key directly to the left of the rotary knob.
// To reset the keyboard, hold the traditional caps-lock key and then then press the boot loader key (key next to the rotary knob)

    // Right symbols
    [0] = BASE_LAYOUT,
    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,           XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  CTL_OPT,          MV_2TL,
        KC_TRNS, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, NO_IMPL, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,   KC_RALT, KC_TRNS, MV_ALL,           MV_1TR,
        _______, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, KC_EXLM, KC_LPRN, KC_RPRN, KC_COLN, KC_GRV,  NO_IMPL,          VI_SAVE,          MV_TOPR,
        KC_TRNS,          CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, KC_SCLN, KC_HASH, ARROW,   EARROW,  UPDIR,            MV_WSR,  MV_MAX,  MV_BOTR,
        KC_TRNS, XXXXXXX, MO(5),                              NO_IMPL,                            XXXXXXX, XXXXXXX, XXXXXXX, MV_L,    MV_RSET, MV_R
    ),

    // Left symbols
    [2] = BASE_LAYOUT,
    [3] = LAYOUT(
        NO_IMPL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        NO_IMPL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        NO_IMPL, NO_IMPL, KC_PERC, KC_LBRC, KC_RBRC, KC_BSLS, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, KC_TRNS, XXXXXXX, XXXXXXX,          XXXXXXX,
        NO_IMPL, KC_PLUS, KC_MINS, KC_ASTR, KC_UNDS, KC_CIRC, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, _______,          XXXXXXX,          XXXXXXX,
        MV_WSL,           KC_TILD, KC_EQL,  KC_PIPE, KC_AMPR, NO_IMPL, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD, CTL_CMD,          KC_TRNS, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            NO_IMPL,                            NO_IMPL, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // Navigation
    [4] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NO_IMPL, KC_PGUP, KC_PGDN, NO_IMPL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        KC_LSFT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_RGHT, KC_END,  XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______,                            NO_IMPL,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [5] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        KC_TRNS,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, CTL_OPT, CTL_OPT, KC_TRNS, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______,                            KC_TRNS,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
// clang-format on


typedef union {
    uint32_t raw;
    struct {
        bool macos: 1;
    };
} user_config_t;
user_config_t user_config;

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DQUO, KC_QUOT},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    switch (keycode) {
        case ARROW:
            if(record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case EARROW:
            if(record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
        case UPDIR:
            if(record->event.pressed) {
                SEND_STRING("../");
            }
            break;
        case VI_SAVE:
            if (record->event.pressed) {
                tap_code16_delay(KC_ESCAPE, 10);
                SEND_STRING_DELAY(":", 10);
                SEND_STRING("w");
            }
            break;

        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case WINDOWS:
            if(record->event.pressed) {
                user_config.macos = 0;
                eeconfig_update_user(user_config.raw);
            }
            break;
        case MAC:
            if(record->event.pressed) {
                user_config.macos = 1;
                eeconfig_update_user(user_config.raw);
            }
            break;
        case CTL_CMD:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? LGUI(KC_TRNS) : LCTL(KC_TRNS));
            }
            break;
        case CTL_OPT:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? LALT(KC_TRNS) : LCTL(KC_TRNS));
            }
            break;
        case MV_FULL_TOGGLE:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? LGUI(LCTL(KC_F)) : LGUI(LCTL(KC_F)));
            }
            break;
        case MV_MAX_SIZE:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? LCA(KC_ENTER) : LGUI(KC_UP));
            }
            break;
        case MV_RESET_SIZE:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? LCA(KC_BACKSPACE) : LGUI(KC_DOWN));
            }
            break;
        case MV_SPLIT_LEFT:
            if (record->event.pressed) {
                if (user_config.macos) {
                    tap_code16(LCA(KC_LEFT));
                } else {
                    tap_code16_delay(LCAG(KC_0), 25);
                    tap_code16(LGUI(KC_LEFT));
                }
            }
            break;
        case MV_SPLIT_RIGHT:
            if (record->event.pressed) {
                if (user_config.macos) {
                    tap_code16(LCA(KC_RIGHT));
                } else {
                    tap_code16_delay(LCAG(KC_0), 25);
                    tap_code16(LGUI(KC_RIGHT));
                }
            }
            break;
        case MV_2THIRDS_LEFT:
            if (record->event.pressed) {
                if (user_config.macos) {
                    tap_code16(LCA(KC_G));
                } else {
                    tap_code16_delay(LCAG(KC_1), 25);
                    tap_code16(LGUI(KC_LEFT));
                }
            }
            break;
        case MV_1THIRDS_RIGHT:
            if (record->event.pressed) {
                if (user_config.macos) {
                    tap_code16(LCA(KC_H));
                } else {
                    tap_code16_delay(LCAG(KC_1), 25);
                    tap_code16(LGUI(KC_RIGHT));
                }
            }
            break;
        case MV_TOP_RIGHT:
            if (record->event.pressed) {
                if (user_config.macos) {
                    tap_code16(MEH(KC_H));
                } else {
                    tap_code16_delay(LCAG(KC_2), 25);
                    tap_code16(LGUI(KC_RIGHT));
                }
            }
            break;
        case MV_BOTTOM_RIGHT:
            if (record->event.pressed) {
                if (user_config.macos) {
                    tap_code16(LCAG(KC_H));
                } else {
                    tap_code16_delay(LCAG(KC_2), 25);
                    tap_code16(LGUI(KC_RIGHT));
                }
            }
            break;
        case MV_ALL:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? KC_MCTL : LGUI(KC_TAB));
            }
            break;
        case MV_LEFT_WORKSPACE:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? LCTL(KC_LEFT) : LGUI(LCTL(KC_LEFT)));
            }
            break;
        case MV_RIGHT_WORKSPACE:
            if (record->event.pressed) {
                tap_code16((user_config.macos) ? LCTL(KC_RIGHT) : LGUI(LCTL(KC_RIGHT)));
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [5] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
