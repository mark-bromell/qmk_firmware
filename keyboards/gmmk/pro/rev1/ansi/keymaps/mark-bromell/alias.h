#pragma once

#define NO_IMPL KC_NO
#define CTL_ESC RCTL_T(KC_ESC)

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    EARROW,
    UPDIR,
    VI_SAVE,

    WINDOWS,
    MAC,
    CTL_CMD, // Ctrl or Cmd
    CTL_OPT, // Ctrl or Opt

    ALT_TAB,
    MV_FULL_TOGGLE,
    MV_MAX_SIZE,
    MV_RESET_SIZE,
    MV_SPLIT_LEFT,
    MV_SPLIT_RIGHT,
    MV_2THIRDS_LEFT,
    MV_1THIRDS_RIGHT,
    MV_TOP_RIGHT,
    MV_BOTTOM_RIGHT,
    MV_ALL,
    MV_LEFT_WORKSPACE,
    MV_RIGHT_WORKSPACE,
};

// Aliases for custom window management keycodes
#define MV_FULL MV_FULL_TOGGLE
#define MV_MAX MV_MAX_SIZE
#define MV_RSET MV_RESET_SIZE
#define MV_L MV_SPLIT_LEFT
#define MV_R MV_SPLIT_RIGHT
#define MV_2TL MV_2THIRDS_LEFT
#define MV_1TR MV_1THIRDS_RIGHT
#define MV_TOPR MV_TOP_RIGHT
#define MV_BOTR MV_BOTTOM_RIGHT
#define MV_WSL MV_LEFT_WORKSPACE
#define MV_WSR MV_RIGHT_WORKSPACE
