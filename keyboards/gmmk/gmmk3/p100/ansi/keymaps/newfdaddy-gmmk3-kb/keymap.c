/* Copyright 2023 Chris Jones
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BL,
    _L1,
    _BM,
    _M1,
};

// Define tap dance actions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for shift, multiple to toggle layer 1
    [0] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RSFT, _BM)
};
// End of define tap dance actions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
[_BL] = LAYOUT(
  KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     KC_F11,  KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,                               KC_MUTE,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             TD(0),             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
  KC_LCTL, KC_LWIN, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_L1), KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
),

  /* Keymap _L1: Function Layer
   */
[_L1] = LAYOUT(
  QK_BOOT,            KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_PSCR,     _______,  _______,  _______,                                   _______,
  QK_RBT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
   EE_CLR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                                      DM_REC1,  DM_REC2,  _______,
  _______,  QK_UNDERGLOW_HUE_UP,  QK_UNDERGLOW_HUE_DOWN,  QK_UNDERGLOW_SPEED_DOWN,  QK_UNDERGLOW_SPEED_UP,  _______,  _______,  _______,  _______,  _______,  _______,            _______,               QK_UNDERGLOW_VALUE_UP,               DM_PLY1,  DM_PLY2,  _______,  _______,
  _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,     QK_UNDERGLOW_MODE_PREVIOUS, QK_UNDERGLOW_VALUE_DOWN,  QK_UNDERGLOW_MODE_NEXT,     _______,            _______
),

[_BM] = LAYOUT(
  KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,  KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,                               KC_MUTE,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,      KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,      KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,               KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,               TD(0),             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
  KC_LCTL,  KC_LALT,  KC_LGUI,                            KC_SPC,                             KC_RCMD, MO(_M1), KC_ROPT, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
),

[_M1] = LAYOUT(
  QK_BOOT,            KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_PSCR,     _______,  _______,  _______,                                   _______,
   QK_RBT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
   EE_CLR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,     _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                                      DM_REC1,  DM_REC2,  _______,
  _______,  QK_UNDERGLOW_HUE_UP,  QK_UNDERGLOW_HUE_DOWN,  QK_UNDERGLOW_SPEED_DOWN,  QK_UNDERGLOW_SPEED_UP,  _______,  _______,  _______,  _______,  _______,  _______,            _______,               QK_UNDERGLOW_VALUE_UP,               DM_PLY1,  DM_PLY2,  _______,  _______,
  _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,     QK_UNDERGLOW_MODE_PREVIOUS, QK_UNDERGLOW_VALUE_DOWN,  QK_UNDERGLOW_MODE_NEXT,     _______,            _______
)
};

/* Define a couple of consts to label the appropriate led #s for easy reference.
*/
const int KB_CAPSLOCK_LED = 58;
const int KB_NUMLOCK_LED = 33;
const int KB_FUNCTION_LED = 96; 

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
/* This reads status of the caps lock and number lock, and changes LED under
the appropriate key for an indicator.
*/
  // lights up the caps lock key if caps lock is on
  if (host_keyboard_led_state().caps_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR(KB_CAPSLOCK_LED, 255, 0, 0);
  }
  // lights up the num lock key if num lock is on
  if (host_keyboard_led_state().num_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR(KB_NUMLOCK_LED,255,0,0);
  }

  //if (IS_LAYER_ON(0)) {
  //  for (int l = 104;l<=124;l++) {
  //    RGB_MATRIX_INDICATOR_SET_COLOR(l,0,0,255);
  //  }
  //}
  //if (IS_LAYER_ON(2)) {
  //  for (int l = 104;l<=124;l++) {
  //    RGB_MATRIX_INDICATOR_SET_COLOR(l,255,0,0);
  //  }
  //}
  if (IS_LAYER_ON(1)) {
    // Set the indicator on right shift
    RGB_MATRIX_INDICATOR_SET_COLOR(KB_FUNCTION_LED,255,0,0);
    // Highlight keys with macro things (keypad 4,5,1,2)
    RGB_MATRIX_INDICATOR_SET_COLOR(71,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(87,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(72,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(88,0,255,0);
    // highlight escape and grave/tic (set red for bootloader and reset)
    RGB_MATRIX_INDICATOR_SET_COLOR(0,255,0,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(16,255,0,0);
    // highlight media keys
    RGB_MATRIX_INDICATOR_SET_COLOR(5,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(6,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(7,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(8,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(9,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(10,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(11,0,255,0);
    // light up F1 to indicate layer 1 in use (pc/linux)
    RGB_MATRIX_INDICATOR_SET_COLOR(1,255,255,255);
  }
  if (IS_LAYER_ON(3)) {
    // Set the indicator on right shift
    RGB_MATRIX_INDICATOR_SET_COLOR(KB_FUNCTION_LED,255,0,0);
    // Highlight keys with macro things (keypad 4,5,1,2)
    RGB_MATRIX_INDICATOR_SET_COLOR(71,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(87,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(72,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(88,0,255,0);
    // highlight escape and grave/tic (set red for bootloader and reset)
    RGB_MATRIX_INDICATOR_SET_COLOR(0,255,0,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(16,255,0,0);
    // highlight media keys
    RGB_MATRIX_INDICATOR_SET_COLOR(5,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(6,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(7,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(8,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(9,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(10,0,255,0);
    RGB_MATRIX_INDICATOR_SET_COLOR(11,0,255,0);
    // light up F3 to indicate layer 3 in use (macos)
    RGB_MATRIX_INDICATOR_SET_COLOR(3,255,255,255);
  }
  return false;
}