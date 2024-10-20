/*
Copyright 2022 Stefan Sundin "4pplet" <mail@4pplet.com>

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
#include "poorkoi.h"

typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

/* User preference */
user_config_t user_config;

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.rgb_layer_change = false; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv(HSV_PURPLE);  // Set it to PURPLE by default
  rgblight_mode(1); // set to solid by default
}

void keyboard_pre_init_kb(void) {
    rgblight_set_effect_range(0, 16);
    keyboard_pre_init_user();
}

void keyboard_post_init_user(void) {
  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Set default layer, if enabled
  if (user_config.rgb_layer_change) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_at(HSV_OFF, 16);
  }
}

/* Updating LED located under capslock */
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    // Dealing with capslock
    if (CAPS_LOCK_ENABLE && res) {
        if(led_state.caps_lock) {
            rgblight_sethsv_at(CAPS_LOCK_COLOR, 16);
        }
        // Color of activated layer
        else{
            layer_state_set(layer_state);
        }
    }

    return res;
}

/* Use capslock led for layer indicator */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        if(host_keyboard_led_state().caps_lock) {
            rgblight_sethsv_at(CAPS_LOCK_COLOR, 16);
        }
        else{
            if (user_config.rgb_layer_change) { rgblight_sethsv_at(HSV_OFF, 16);}
        }
        break;
    case _FN:
        if (user_config.rgb_layer_change) { rgblight_sethsv_at(LAYER_FN_COLOR, 16); }
        break;
    case _MEDIA:
        if (user_config.rgb_layer_change) { rgblight_sethsv_at(LAYER_MEDIA_COLOR, 16); }
        break;
     case _GAME:
        if (user_config.rgb_layer_change) { rgblight_sethsv_at(LAYER_GAMING_COLOR, 16); }
        break;
    case _MAC:
        if (user_config.rgb_layer_change) { rgblight_sethsv_at(LAYER_MAC_COLOR, 16); }
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_at(HSV_OFF, 16);
        break;
    }

    return state;
}

/* Update user preference on layer indicator*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAY_INDIC_RGB:
      if (record->event.pressed) {
        user_config.rgb_layer_change ^= 1; // Toggles the status
        eeconfig_update_user(user_config.raw); // Writes the new status to EEPROM
        if (user_config.rgb_layer_change) { // if layer state indication is enabled,
            layer_state_set(layer_state);   // then immediately update the layer color
        }
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
