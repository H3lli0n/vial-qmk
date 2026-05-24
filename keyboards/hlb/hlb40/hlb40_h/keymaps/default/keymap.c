// Copyright 2026 HLB
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FN,
    _MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// main layer
[_BASE] = LAYOUT(
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,      KC_U,      KC_I,      KC_O,       KC_P,    KC_BSPC,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,       KC_H,      KC_J,      KC_K,      KC_L,       KC_NUHS, KC_ENT,
  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,      KC_N,      KC_M,      KC_COMM,    KC_DOT,  KC_RSFT,
            KC_LGUI,  KC_LALT,            KC_SPC,    MO(2),      KC_SPC,              KC_RALT,   KC_RGUI),

// basic function layer
[_FN] = LAYOUT(
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
            KC_TRNS,  KC_TRNS,               KC_TRNS,     KC_TRNS,       KC_TRNS,                    KC_TRNS,   KC_TRNS),

// rgb/media layer
[_MEDIA] = LAYOUT(
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,
            KC_TRNS,  KC_TRNS,               KC_TRNS,     KC_TRNS,       KC_TRNS,                    KC_TRNS,   KC_TRNS)
};

