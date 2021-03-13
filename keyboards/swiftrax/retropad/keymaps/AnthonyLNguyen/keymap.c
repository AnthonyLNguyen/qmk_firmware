  /* Copyright 2020 swiftrax
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
  // COMMAND: qmk compile -kb swiftrax/retropad -km AnthonyLNguyen && qmk flash -kb swiftrax/retropad -km AnthonyLNguyen
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT( //media
  TO(1),
  KC_MSTP, KC_MPLY,
  KC_MPRV, KC_MNXT),

[1] = LAYOUT( //Spotify
  TO(2),
  KC_F17, _______,
  KC_F18, KC_F19),

[2] = LAYOUT( //LCA
  TO(0),
  KC_F21, KC_F22,
  KC_F23, KC_F24)

};

void encoder_update_user(uint8_t index, bool clockwise) {
  if(IS_LAYER_ON(2)){
    if (!clockwise)
      tap_code(KC_LEFT);
    else
      tap_code(KC_RGHT);
  }
  else{
    if(!clockwise)
      tap_code(KC_F13);
    else
      tap_code(KC_F14);
  }
}

void matrix_init_user(void) {
  // set top LED to output and off (active low)
  setPinOutput(D5);
  writePinHigh(D5);
  // set middle LED to output and off (active low)
  setPinOutput(D4);
  writePinHigh(D4);
  // set bottom LED to output and off (active low)
  setPinOutput(D3);
  writePinHigh(D3);
}

// write to above indicators in a binary fashion based on current layer
layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(D5, get_highest_layer(state));
    writePin(D4, !layer_state_cmp(state, 1));
    writePin(D3, !layer_state_cmp(state, 2));
    return state;
}
