#include <stdarg.h>
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_GRV,     KC_1,    KC_2,     KC_3,     KC_4,   KC_5,  KC_ESC,
  KC_TAB,     KC_Q,    KC_W,     KC_E,     KC_R,   KC_T,  KC_ESC,
  KC_LCTL,    KC_A,    KC_S,     KC_D,     KC_F,   KC_G,
  KC_LSFT,    KC_Z,    KC_X,     KC_C,     KC_V,   KC_B,  KC_ESC,
   KC_ESC,    KC_GRV,  KC_QUOT,  KC_BSLS,  KC_APP,

                                               KC_HOME,   KC_END,
                                                          KC_ESC,
                                      KC_LALT, KC_ESC,    MO(2),

  // right hand
  KC_ESC,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_BSPC,
  KC_ESC,   KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
            KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
  KC_ESC,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_MINS,
                      KC_LCBR,  KC_RCBR,  KC_LBRC,  KC_RBRC,   MO(1),

  KC_ESC,  KC_INS,
  KC_ESC,
  KC_ESC,  KC_DEL,    KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   =  |    . |   0  |   -  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_EQL,KC_DOT,  KC_0,    KC_MINS,  KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  |Right |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |VolDwn|VolUp | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play | Prev | Next |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 |      |      |------|       |------|Back  | Fwd  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
LAYOUT_ergodox(
         RESET, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS, KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,     KC_TRNS,        KC_TRNS,

                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE,  KC_TRNS, KC_TRNS,
                          KC_MPLY, KC_MPRV, KC_MNXT,  KC_TRNS, KC_TRNS,

       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_WBAK, KC_WFWD
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    xprintf("XXXXXX\n");
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
