#pragma once

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    FUN,
};

enum custom_keycodes {
    MY_DEBG = SAFE_RANGE,

    UPDIR,
    COLON_2,
    DOT_3,
    QUOTE_3,
    GRAVE_3,
    WALRUS,
    EURO,
    END_SCL,
    VI_SAVE,

    WINDOWS,
    MAC,

    W_BACK,
    W_DEL,
    W_LEFT,
    W_RIGHT,

    MY_UNDO,
    MY_REDO,
    MY_COPY,
    MY_PSTE,
    MY_SALL,
    MY_SAVE,
    MY_FIND,
    MY_FNXT,
    MY_EDIT,

    MV_FULL,
    MV_L,
    MV_R,
    MV_2TL,
    MV_1TR,
    MV_EXIT,
    MV_XTAB,
    MV_NTAB,
    MV_PTAB,
    SEE_ALL,

    WS_LEFT,
    WS_RGHT,
    WS_NEW,
};

#define NO_IMPL KC_NO
#define ALT_TAB LALT(KC_TAB)

#define MOD_TAB LT(NAV, KC_TAB)
#define MOD_S LCTL_T(KC_S)
#define MOD_D LALT_T(KC_D)
#define MOD_F LT(SYM, KC_F)
#define MOD_G LT(NUM, KC_G)
#define MOD_V LT(FUN, KC_V)
#define MOD_H LT(NUM, KC_H)
#define MOD_J LT(SYM, KC_J)
#define MOD_K RALT_T(KC_K)
#define MOD_L RCTL_T(KC_L)
#define MOD_M LT(FUN, KC_M)
#define LCK_NUM TO(NUM)
#define LCK_NAV TO(NAV)
