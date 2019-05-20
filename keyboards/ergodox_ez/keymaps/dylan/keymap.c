#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  UC_SHRG,  // ¯\_(ツ)_/¯
  UC_DISA,  // ಠ_ಠ
  UC_CRY,   // ಥ_ಥ
  UC_STRT,  // ᕕ( ᐛ )ᕗ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* Keymap 0: Basic layer
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |   `    |   1  |   2  |   3  |   4  |   5  |   =  |           |   -  |   6  |   7  |   8  |   9  |   0  |  BkSp  |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
  * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |  Up  | Down | Ctrl |  Alt | LGui |                                       |   [  |   ]  | Left | Right| ~L1  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | Home | End  |       | Esc  | Del  |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      | PgUp |       | Pause|      |      |
  *                                 | Space| BkSp |------|       |------| Enter| Space|
  *                                 |      |      | PgDn |       | Print|      |      |
  *                                 `--------------------'       `--------------------'
  */
  [0] = LAYOUT_ergodox(
    // LEFT HAND
    KC_GRAVE,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQUAL,
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(1),
    KC_CAPSLOCK,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSHIFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),
      LT(2,KC_UP), KC_DOWN, KC_LCTL, KC_LALT, KC_LGUI, 
                                                  KC_HOME,   KC_END,
                                                             KC_PGUP,
                                        KC_SPACE, KC_BSPACE, KC_PGDOWN,
    // RIGHT HAND
    KC_MINUS,     KC_6,  KC_7,        KC_8,        KC_9,    KC_0,      KC_BSPACE,
    TG(1),        KC_Y,  KC_U,        KC_I,        KC_O,    KC_P,      KC_BSLASH,
                  KC_H,  KC_J,        KC_K,        KC_L,    KC_SCOLON, KC_QUOTE,
    MEH_T(KC_NO), KC_N,  KC_M,        KC_COMMA,    KC_DOT,  KC_SLASH,  KC_RSHIFT,
                         KC_LBRACKET, KC_RBRACKET, KC_LEFT, KC_RIGHT,  MO(1),
      KC_ESCAPE, KC_DELETE,
      KC_PAUSE,
      KC_PSCREEN,KC_ENTER, KC_SPACE
  ),
 /* Keymap 1: Symbols
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * | Version|  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |  !   |  @   |  {   |  }   |  |   |      |           |      |  /   |  N7  |  N8  |  N9  |  -   |  F11   |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |  #   |  $   |  (   |  )   |  `   |------|           |------|  *   |  N4  |  N5  |  N6  |  +   |  F12   |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |  &   |  N1  |  N2  |  N3  | Enter|  Enter |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   | SHRG | DISA | CRY  | STRT |      |                                       |  N0  |  N0  |  .   |  =   |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |  L2  |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       | App  |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [1] = LAYOUT_ergodox(
    // LEFT HAND
    VRSN,      KC_F1,    KC_F2,    KC_F3,       KC_F4,       KC_F5,    KC_TRNS,
    KC_TRNS,   KC_EXLM,  KC_AT,    KC_LCBR,     KC_RCBR,     KC_PIPE,  KC_TRNS,
    KC_TRNS,   KC_HASH,  KC_DLR,   KC_LPRN,     KC_RPRN,     KC_GRAVE, 
    KC_TRNS,   KC_PERC,  KC_CIRC,  KC_LBRACKET, KC_RBRACKET, KC_TILD,  KC_TRNS,
      UC_SHRG, UC_DISA, UC_CRY,  UC_STRT,    KC_TRNS,
                                                      KC_TRNS, TO(2),
                                                                KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
    // RIGHT HAND
    KC_TRNS, KC_F6,          KC_F7,   KC_F8,    KC_F9,     KC_F10,      KC_TRNS,
    KC_TRNS, KC_KP_SLASH,    KC_KP_7, KC_KP_8,  KC_KP_9,   KC_KP_MINUS, KC_F11,
             KC_KP_ASTERISK, KC_KP_4, KC_KP_5,  KC_KP_6,   KC_KP_PLUS,  KC_F12,
    KC_TRNS, KC_AMPR,        KC_KP_1, KC_KP_2,  KC_KP_3,   KC_KP_ENTER, KC_KP_ENTER,
                                    KC_KP_0, KC_KP_0,  KC_KP_DOT, KC_EQUAL,    KC_TRNS,
      KC_TRNS,       KC_TRNS,
      KC_TRNS,
      KC_APPLICATION, KC_TRNS, KC_TRNS
  ),
 /* Keymap 2: Media and mouse keys
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * |        | BrtDn| BrtUp|      |      |      |      |           | Prev | Play | Next | Mute | VolDn| VolUp|        |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |           |      |      |      |  Up  |      |      |        |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |      |      |      | Lclk | Rclk |                                       | Left | Down | Right|      |      |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        |      |  L0  |       |      |      |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |      |      |      |       |      |      |      |
  *                                 |      |      |------|       |------|      |      |
  *                                 |      |      |      |       |      |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [2] = LAYOUT_ergodox(
    // LEFT HAND
    KC_TRNS, KC_F14,  KC_F15,     KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,    KC_MS_UP,   KC_TRNS,     KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,    KC_MS_BTN1, KC_MS_BTN2, 
                                                       KC_TRNS, TO(0),
                                                                KC_TRNS,
                                              KC_TRNS, KC_TRNS, KC_TRNS,
    // RIGHT HAND
    KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
                       KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    case UC_SHRG: // ¯\_(ツ)_/¯
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
        send_unicode_hex_string("00af 005c 005f 0028 30c4 0029 005f 002f 00af");
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
      }
      return false;
      break;
    case UC_DISA: // ಠ_ಠ
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
        send_unicode_hex_string("0CA0 005F 0CA0");
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
      }
      return false;
      break;
    case UC_CRY: // ಥ_ಥ
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
        send_unicode_hex_string("0CA5 005F 0CA5");
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
      }
      return false;
      break;
    case UC_STRT: // ᕕ( ᐛ )ᕗ
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
        send_unicode_hex_string("1555 0028 0020 141B 0020 0029 1557");
        SEND_STRING(SS_LCTRL(SS_LALT(" ")));
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user (void) { 
  set_unicode_input_mode(UC_OSX);
  
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  switch (layer) {
    case 0:
      ergodox_right_led_1_off();
      ergodox_right_led_2_off();
      break;
    case 1:
        ergodox_right_led_1_on();
        break;
    case 2:
        ergodox_right_led_2_on();
        break;
    // case 3:
    //     ergodox_right_led_3_on();
    //     break;
    // case 4:
    //     ergodox_right_led_1_on();
    //     ergodox_right_led_2_on();
    //     break;
    // case 5:
    //     ergodox_right_led_1_on();
    //     ergodox_right_led_3_on();
    //     break;
    // case 6:
    //     ergodox_right_led_2_on();
    //     ergodox_right_led_3_on();
    //     break;
    // case 7:
    //     ergodox_right_led_1_on();
    //     ergodox_right_led_2_on();
    //     ergodox_right_led_3_on();
    //     break;
    // default:
    //     break;
  }
  return state;
}
