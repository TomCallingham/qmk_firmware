// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
// #include "keymap_steno.h"
#include "process_steno.h"
// #include "process_steno.c"
#include "my_steno.h"


enum custom_keycodes {
    SwitchEager = SAFE_RANGE,
     my_STN_TKL,  my_STN_PWL,  my_STN_HRL, my_STN_FRR,   my_STN_PBR,  my_STN_LGR,  my_STN_TSR,  my_STN_DZR, my_STN_AO, my_STN_EU,
     EscToLet, Act_STEN, Sym_STEN, Undo_STEN
};



enum layer_names {
    Let,
    Sym,
    Act,
    Func,
    Ctl_Sym,
    Aoe2,
  s_PLOVER,
  LetSten,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [Let] = LAYOUT( /* MTGAP3 */
    KC_Y,    KC_P,    KC_O,    KC_U,    KC_SLSH,                                                           KC_M,    KC_D,    KC_L,    KC_C,    KC_W,
    KC_I,    KC_N,    KC_E,    KC_A,    KC_J,                                                              KC_K,    KC_H,    KC_T,    KC_S,    KC_R,
    KC_Z,    KC_Q,    KC_DOT,  KC_COMM, KC_SCLN,  KC_ESC,                                         KC_NO,   KC_B,    KC_F,    KC_G,    KC_V,    KC_X,
    TO(Sym), KC_LALT, MO(Ctl_Sym),   KC_LGUI,  LT(Sym,KC_TAB), LCTL_T(KC_ESC),  LALT_T(KC_ENT), LSFT_T(KC_SPC),  MO(Act), LSFT(KC_LALT), KC_LCTL, OSL(Func)),

  [LetSten] = LAYOUT( /* MTGAP3 */
    KC_Y,       KC_P,    KC_O,    KC_U,    Undo_STEN,                                                           KC_M,    KC_D,    KC_L,    KC_C,    KC_W,
    KC_I,       KC_N,    KC_E,    KC_A,    KC_J,                                                              KC_K,    KC_H,    KC_T,    KC_S,    KC_R,
    KC_Z,       KC_Q,    KC_DOT,  KC_COMM, KC_SCLN,  KC_ESC,                                      EscToLet,   KC_B,    KC_F,    KC_G,    KC_V,    KC_X,
    SwitchEager, KC_LALT, MO(Ctl_Sym),   KC_LGUI,  Sym_STEN, LCTL_T(KC_ESC),  LALT_T(KC_ENT), LSFT_T(KC_SPC),  Act_STEN, LSFT(KC_LALT), KC_LCTL, OSL(Func)),

  [Sym] = LAYOUT( /* [> RAISE <] */
    KC_9,    KC_5,    KC_1,    KC_3,    KC_7,                                          KC_6,    KC_2,    KC_0,    KC_4,   KC_8,
    KC_LBRC, KC_AT,   KC_MINS, KC_LPRN, KC_CIRC,                                       KC_DLR,  KC_RPRN, KC_UNDS, KC_EQL, KC_RBRC,
    KC_PIPE, KC_DQUO, KC_PLUS, KC_NUHS, KC_GRV, KC_ESC,                      TO(Let),  KC_NUBS, KC_QUOT, KC_ASTR,KC_AMPR,  RALT(KC_NONUS_BACKSLASH),
    TG(Let), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL,              LALT_T(KC_DEL), LSFT_T(KC_BSPC), TO(Act), LSFT(KC_LALT), KC_LCTL, OSL(Func)),

  [Act] = LAYOUT( /* [> LOWER <] */
    KC_NO,     KC_WH_D, KC_MS_U,   KC_WH_U,  KC_PGUP,                   KC_MPLY,   KC_VOLD,   KC_MUTE,   KC_VOLU,   KC_NO,
    RALT(KC_3),KC_MS_L, KC_MS_D,   KC_MS_R,  KC_PGDN,                   KC_PSCR,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_LEFT,
    KC_NO,     KC_PGDN, KC_BTN3,   KC_PGUP,  KC_INS,  KC_NO,     TO(Let), KC_BRID,   KC_BRIU,   KC_MPRV,   KC_MNXT,   KC_NO,
    KC_LGUI,   KC_RALT, KC_LSFT,   KC_LCTL,  KC_BTN1, KC_BTN2,   KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,     QK_MAGIC_NKRO_ON ),

  [Func] = LAYOUT( /* [> LOWER <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  TO(Aoe2),  TO(Let),   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
    TO(LetSten),   TO(LetSten), SwitchEager, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(Let), KC_PSCR, KC_SLCT, KC_PAUS ),

  [Ctl_Sym] = LAYOUT( /* [> RAISE <] */
    LCTL(KC_9),    LCTL(KC_5),    LCTL(KC_1),    LCTL(KC_3),    LCTL(KC_7),                                  LCTL(KC_6),     LCTL(KC_2),    LCTL(KC_0),    LCTL(KC_4),   LCTL(KC_8),
    LCTL(KC_LBRC), LCTL(KC_AT),   LCTL(KC_MINS), LCTL(KC_LPRN), LCTL(KC_CIRC),                               LCTL(KC_DLR),   LCTL(KC_RPRN), LCTL(KC_UNDS), LCTL(KC_EQL), LCTL(KC_RBRC),
    LCTL(KC_PIPE), LCTL(KC_DQUO), LCTL(KC_PLUS), LCTL(KC_NUHS), LCTL(KC_GRV), LCTL(KC_ESC),       TO(Let),   LCTL(KC_NUBS),  LCTL(KC_QUOT), LCTL(KC_ASTR), LCTL(KC_AMPR),LCTL(KC_TILD),
    KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,         KC_NO,        LALT_T(KC_DEL), LSFT_T(KC_BSPC),TO(Act),       LSFT(KC_LALT), KC_LCTL,      OSL(Func)),

  [Aoe2] = LAYOUT( /* MTGAP3 + AOE2*/
    KC_Y,            KC_P,    KC_O,          KC_U,          KC_SLSH,                                                          KC_M,            KC_D,          KC_L,    KC_C,       KC_W,
    LSFT_T(KC_I),    KC_N,    KC_E,          KC_DOT,          KC_J,                                                             KC_K,            KC_H,          KC_T,    KC_S,       KC_R,
    KC_Z,            KC_Q,    KC_A,        KC_COMM,       KC_SCLN,                     KC_ESC,              TO(Let),        KC_B,            KC_F,          KC_G,    KC_V,       KC_X,
    KC_ESC,          KC_DEL,  MO(Ctl_Sym),   LALT_T(KC_0),  MT(MOD_LALT|MOD_LCTL,KC_TAB), LCTL_T(KC_BSPC),     LALT_T(KC_ENT), LSFT_T(KC_SPC),  MO(Act), LSFT(KC_LALT), KC_LCTL, OSL(Func)),

[s_PLOVER] = LAYOUT(
    KC_NO,  my_STN_TKL,  my_STN_PWL,  my_STN_HRL, STN_ST1,                  my_STN_DZR,   my_STN_TSR,  my_STN_LGR,  my_STN_PBR, my_STN_FRR,
   STN_S1,  STN_TL,      STN_PL,      STN_HL,    STN_ST1,                   STN_DR,      STN_TR,       STN_LR,      STN_PR,     STN_FR ,
   KC_NO,  STN_KL,       STN_WL,      STN_RL,    STN_ST2,   KC_NO,  TO(Let),STN_ZR,      STN_SR,       STN_GR,      STN_BR,     STN_RR ,
   KC_NO, KC_NO,         KC_NO,       my_STN_AO, STN_A,   STN_O,   STN_U,   STN_E,       my_STN_EU,    KC_NO,       KC_NO,      KC_NO
),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    static keypos_t key_pos;
    static int n_held = 0;

    static keypos_t x_key_pos;
    static keypos_t y_key_pos;

    static uint16_t x_keycode =0;
    static uint16_t y_keycode =0;


    static int x_timer;
    static int y_timer;

    static bool x_held = false;
    static bool y_held = false;

    static bool eager = true;
    static bool steno_mode = false;

    static uint16_t static_steno_time = 400;

    static bool steno_init = false;

    static bool act_held = false;
    static bool undo_held = false;
    static bool sym_held = false;
    static int sym_timer;
    static bool sym_layer_pressed = false;

    if (!layer_state_is(LetSten)){
        return true;
    }

    if (!steno_init){
        steno_clear_chord();
        steno_mode = false;
        x_held = false;
        y_held = false;
        n_held = 0;
        steno_init=true;
        steno_mode=false;
    }

    if (n_held<1){
    switch(keycode) {
        case EscToLet:
        if (record->event.pressed){
                steno_clear_chord();
                steno_mode = false;
                x_held = false;
                y_held = false;
                n_held = 0;
                steno_init=false;
                steno_mode=false;
                act_held=false;
                sym_held=false;
                sym_layer_pressed=false;
                layer_off(LetSten);
                layer_on(Let);
        }
        return false;
        case SwitchEager:
            if (record->event.pressed) {
            if (eager){
            eager=false;
            }else{
            eager=true;}
            }
        return false;

        case Sym_STEN:
            if (record->event.pressed) {
                sym_timer = timer_read();
                sym_held = true;
                sym_layer_pressed = false;
            } else {
                sym_held=false;
                if (!sym_layer_pressed && (timer_elapsed(sym_timer)<static_steno_time)){
                    tap_code16(KC_TAB);
                }

            }
        return false;
        case Act_STEN:
            if (record->event.pressed) {
                act_held = true;
            } else {act_held=false;}
        return false;
        case Undo_STEN:
            if (record->event.pressed) {
                sym_timer = timer_read();
                undo_held = true;
                sym_layer_pressed = false;
            } else {undo_held=false;
                if (!sym_layer_pressed && (timer_elapsed(sym_timer)<static_steno_time)){
                    tap_code16(KC_SLSH);
                }
                }
        return false;
        default: break;
    }}

    key_pos = record->event.key;

    if (act_held){
        if (record->event.pressed) {
            x_keycode = keymap_key_to_keycode(Act, key_pos);
            tap_code16(x_keycode);
                    }
            return false;
    }

    if (sym_held){
        if (record->event.pressed) {
            x_keycode = keymap_key_to_keycode(Sym, key_pos);
            tap_code16(x_keycode);
            sym_layer_pressed = true;
        }
            return false;
    }
    if (undo_held){
        if (record->event.pressed) {
            sym_layer_pressed = true;
            steno_clear_chord();
            add_gemini_key_to_chord(STN_ST1 - QK_STENO);
            send_steno_chord_gemini();
            steno_clear_chord();
        }
            return false;
    }


    if (x_held && (x_keycode==keycode)){
        if (!(record->event.pressed)) {
        n_held--;
        x_held = false;
        if (!steno_mode && timer_elapsed(x_timer)>static_steno_time){
            steno_mode = true;
            if (eager) { tap_code16(KC_BSPC);}
            my_steno_from_pos(x_key_pos);
        if (y_held) {
            if (eager) {tap_code16(KC_BSPC);}
        my_steno_from_pos(y_key_pos); }
        } else if (!steno_mode && !eager) {
            tap_code16(x_keycode);
        }
            if (steno_mode && n_held <1) {
        send_steno_chord_gemini();
        steno_clear_chord();
        steno_mode = false;}
        }
    return false;}

    if (y_held && (y_keycode==keycode)){
        if (!(record->event.pressed)) {
        n_held--;
        y_held = false;
        if (!steno_mode && timer_elapsed(y_timer)>static_steno_time){
            steno_mode = true;
            if (eager) { tap_code16(KC_BSPC);}
            my_steno_from_pos(y_key_pos);
        if (x_held) {
            if (eager) {tap_code16(KC_BSPC);}
        my_steno_from_pos(x_key_pos); }
        }else if (!steno_mode && !eager) {
            tap_code16(y_keycode);
        }

        if (steno_mode && n_held <1) {
        send_steno_chord_gemini();
        steno_clear_chord();
        steno_mode = false;}
        }
    return false;}

    if (n_held <1 && key_pos.row==3){
        return true;  // Skip all further processing of this key
    }

    if ((!steno_mode)&&((n_held==2) || (x_held &&(timer_elapsed(x_timer)>static_steno_time))|| (y_held && (timer_elapsed(y_timer)>static_steno_time)))){
    steno_mode = true;
        if (x_held) {
            if (eager) { tap_code16(KC_BSPC);}
            my_steno_from_pos(x_key_pos);
        }
        if (y_held) {
            if (eager) {tap_code16(KC_BSPC);}
            my_steno_from_pos(y_key_pos);
    }}

    if (steno_mode) {
        //if (record->event.pressed) {
            //return my_steno_from_pos(key_pos);
        //}
        if (record->event.pressed) {
            n_held++;
            return my_steno_from_pos(key_pos);
        }else{
            n_held--;
            if (n_held<1){
                send_steno_chord_gemini();
                steno_clear_chord();
                steno_mode = false;}
        }
        return false;
    } else if (n_held <1 && key_pos.row<3){
        if (record->event.pressed) {
            x_held = true;
            n_held=1;
            x_timer = timer_read();
            x_key_pos = key_pos;
            x_keycode = keycode;
            if (eager) { tap_code16(keycode);}
        return false;}
    } else if (n_held ==1){
        if (record->event.pressed) {
            n_held++;
            if (!x_held){
                x_held = true;
                x_timer = timer_read();
                x_key_pos = key_pos;
                x_keycode = keycode;
                } else{
                y_held = true;
                y_timer = timer_read();
                y_key_pos = key_pos;
                y_keycode = keycode;
                }
            if (eager) { tap_code16(keycode);}
        return false;  // Skip all further processing of this key
    }}

return true;  // Process all other keycodes normally
}


bool my_steno_from_pos(keypos_t key_pos) {
        uint16_t my_keycode = keymap_key_to_keycode(s_PLOVER, key_pos);
        return my_key_to_cord(my_keycode);
}

bool my_key_to_cord(uint16_t my_keycode ) {
    switch(my_keycode) {
        case my_STN_TKL:
        add_gemini_key_to_chord(STN_TL - QK_STENO);
        add_gemini_key_to_chord(STN_KL - QK_STENO);
        return false;
        case my_STN_PWL:
        add_gemini_key_to_chord(STN_PL - QK_STENO);
        add_gemini_key_to_chord(STN_WL - QK_STENO);
        return false;
        case my_STN_HRL:
        add_gemini_key_to_chord(STN_HL - QK_STENO);
        add_gemini_key_to_chord(STN_RL - QK_STENO);
        return false;
        case my_STN_FRR:
        add_gemini_key_to_chord(STN_FR - QK_STENO);
        add_gemini_key_to_chord(STN_RR - QK_STENO);
        return false;
        case my_STN_PBR:
        add_gemini_key_to_chord(STN_PR - QK_STENO);
        add_gemini_key_to_chord(STN_BR - QK_STENO);
        return false;
        case my_STN_LGR:
        add_gemini_key_to_chord(STN_LR - QK_STENO);
        add_gemini_key_to_chord(STN_GR - QK_STENO);
        return false;
        case my_STN_TSR:
        add_gemini_key_to_chord(STN_TR - QK_STENO);
        add_gemini_key_to_chord(STN_SR - QK_STENO);
        return false;
        case my_STN_DZR:
        add_gemini_key_to_chord(STN_DR - QK_STENO);
        add_gemini_key_to_chord(STN_ZR - QK_STENO);
        return false;
        case my_STN_AO:
        add_gemini_key_to_chord(STN_A - QK_STENO);
        add_gemini_key_to_chord(STN_O - QK_STENO);
        return false;
        case my_STN_EU:
        add_gemini_key_to_chord(STN_E - QK_STENO);
        add_gemini_key_to_chord(STN_U - QK_STENO);
        return false;
    }
    if (my_keycode < QK_STENO || my_keycode > QK_STENO_MAX) {
        return true; // Not a steno key, pass it further along the chain
        /*
         * Clearing or sending the chord state is not necessary as we intentionally ignore whatever
         * normal keyboard keys the user may have tapped while chording steno keys.
         */
    }
    add_gemini_key_to_chord(my_keycode - QK_STENO);
    return false;
}

