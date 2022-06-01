#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMBERS 1
#define _PROGRAMMING 2
#define _MOVEMENT 3
#define _EXTENDED 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

/*
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
 /*
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
   ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),
*/

/* 0: Qwerty (default)
* ,-----------------------------------------.     ,-----------------------------------------.
* | Esc  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |  [   |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |Tab/Sh|   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |  '   |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* | Ctrl |   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  |Shift |
* `-----------------------------------------´     `-----------------------------------------´
*               ,------+------+------+------.     ,------+------+------+------.
*               |  Alt | GUI  |Space |Layer2|     |Layer1| Enter| Bksp | CAPS |
*               `---------------------------´     `---------------------------´
*/
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_ESC,         KC_Q,  KC_W,    KC_E,    KC_R,            KC_T,        KC_Y,   KC_U,          KC_I,      KC_O,    KC_P,      KC_LBRACKET,
  LSFT_T(KC_TAB), KC_A,  KC_S,    KC_D,    KC_F,            KC_G,        KC_H,   KC_J,          KC_K,      KC_L,    KC_SCOLON, KC_QUOTE,
  KC_LCTL,        KC_Z,  KC_X,    KC_C,    KC_V,            KC_B,        KC_N,   KC_M,          KC_COMMA,  KC_DOT,  KC_SLASH,  KC_RSHIFT,
  KC_NO,          KC_NO, KC_LALT, KC_LGUI, LT(_NUMBERS, KC_SPACE), MO(_PROGRAMMING),       MO(_EXTENDED),  LT(_MOVEMENT, KC_ENT), KC_BSPACE, KC_CAPS, KC_NO,     KC_NO),

/* 1: Numbers and functions
* ,-----------------------------------------.     ,-----------------------------------------.
* | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |     |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |      |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |  +   |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |      |   !  |   "  |   #  |   €  |   %  |     |   &  |   /  |   (  |   )  |   =  |  ?   |
* `-----------------------------------------´     `-----------------------------------------´
*               ,------+------+------+------.     ,------+------+------+------.
*               |      |      |      |      |     |      |      |      |      |
*               `---------------------------´     `---------------------------´
*/
[_NUMBERS] = LAYOUT_ortho_4x12(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,     KC_F8,         KC_F9,   KC_F10,   KC_F11,
  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,      KC_8,          KC_9,    KC_0,     KC_MINUS,
  KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),     S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINUS),
  KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS,       KC_TRNS, KC_NO,    KC_NO),

/* 2: Programming
* ,-----------------------------------------.     ,-----------------------------------------.
* |      |      |      |   *  |   /  |      |     |   |  |   \  |   ~  |   ^  |   "  |  ¨   |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |      |      |   {  |   [  |   (  |   <  |     |   >  |   )  |   ]  |   }  |   ´  |  '   |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |RESET |      |      |      |      |      |     |      |      |      |      |      |      |
* `-----------------------------------------´     `-----------------------------------------´
*               ,------+------+------+------.     ,------+------+------+------.
*               |      |      |      |      |     |      |      |      |      |
*               `---------------------------´     `---------------------------´
*/
[_PROGRAMMING] = LAYOUT_ortho_4x12(
  KC_TRNS, KC_TRNS, KC_TRNS,             S(KC_NUHS), S(KC_7),       KC_TRNS,     A(KC_7),    LSA(KC_7), ALGR(KC_RBRC),    S(KC_RBRC),        S(KC_2),  KC_RBRC,
  KC_TRNS, KC_TRNS, LSA(KC_8),           ALGR(KC_8),  S(KC_8),       KC_NUBS,     S(KC_NUBS), S(KC_9),         ALGR(KC_9),  LSA(KC_9),            KC_EQL, KC_NUHS,
  RESET,   KC_TRNS, KC_TRNS,             KC_TRNS,     KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,         KC_TRNS,     KC_TRNS,              KC_TRNS,  KC_TRNS,
  KC_NO,   KC_NO,   KC_TRNS,             KC_TRNS,     KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,         KC_TRNS,     KC_TRNS,              KC_NO,    KC_NO),

/* 3: Movement
* ,-----------------------------------------.     ,-----------------------------------------.
* |      | PgUp |  Up  | PgDwn|      |      |     |      | PgDwn| PgUp |      |      |      |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |      | Left | Down | Right|      |      |     | Left | Down |  Up  | Right|      |      |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |      | Home | End  |      |      |      |     |      | End  | Home |      |      |      |
* `-----------------------------------------´     `-----------------------------------------´
*               ,------+------+------+------.     ,------+------+------+------.
*               |      |      |      |      |     |      |      |      |      |
*               `---------------------------´     `---------------------------´
*/
[_MOVEMENT] = LAYOUT_ortho_4x12(
  KC_TRNS, KC_PGUP, KC_UP,   KC_PGDOWN, KC_TRNS, KC_TRNS,     KC_TRNS, KC_PGDOWN, KC_PGUP, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_TRNS, KC_TRNS,     KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_HOME, KC_END,  KC_TRNS,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_END,    KC_HOME, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_NO,   KC_NO),

/* 4: Extended Keyboard (Numpad and media keys)
* ,-----------------------------------------.     ,-----------------------------------------.
* |      |      |      |      |      |      |     |      |   7  |   8  |   9  |   -  |   /  |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |      |PrvTrk|Pl/Ps |NxtTrk|      |      |     |      |   4  |   5  |   6  |   +  |   *  |
* |------+------+------+------+------+------|     |------+------+------+------+------+------|
* |      |      |      |      |      |      |     |   0  |   1  |   2  |   3  |   ,  | Enter|
* `-----------------------------------------´     `-----------------------------------------´
*               ,------+------+------+------.     ,------+------+------+------.
*               |      |      |      |      |     |      |      |      |      |
*               `---------------------------´     `---------------------------´
*/
[_EXTENDED] = LAYOUT_ortho_4x12(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_KP_SLASH,
  KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,     KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,  KC_KP_ASTERISK,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_COMMA, KC_KP_ENTER,
  KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,       KC_NO),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
 /*
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),
*/
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
 /*
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),
*/

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 /*
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
*/


};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_QWERTY);
//       }
//       return false;
//     case COLEMAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_COLEMAK);
//       }
//       return false;
//     case DVORAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_DVORAK);
//       }
//       return false;
//   }
//   return true;
// }
