#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ,-----------------------,
 * | F13 | F13 | F13 | F13 |
 * |-----+-----+-----+-----|
 * | F13 | F13 | F13 | F13 |
 * |-----+-----+-----+-----|
 * | F13 | F13 | F13 | F13 |
 * |-----+-----+-----+-----|
 * | F13 | F13 | F13 | F13 |
 * `-----------------------'
 */
LAYOUT_ortho_4x4(
		KC_MPLY,        KC_BRID,       KC_BRIU,     KC_MUTE,
	    KC_F21,         KC_F22,        KC_F23,      KC_F24,
		KC_F17,         KC_F18,        KC_F19,      KC_F20,
		KC_F13,         KC_F14,        KC_F15,      KC_F16
)

};

// Set led state during powerup
void keyboard_post_init_user(void) {
    writePinHigh(LED_RED);
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {         // First encoder - top left
    if (clockwise) {
      tap_code(KC_MNXT);
    } else {
      tap_code(KC_MPRV);
    }
  } else if (index == 1) {  // Second encoder - top right
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
