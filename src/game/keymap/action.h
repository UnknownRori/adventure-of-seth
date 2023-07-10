/**
 * @file action.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Header file for all special action of each keymap
 * @version 0.1
 * @date 2023-07-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_ACTION_KEYMAP_H
#define UNKNOWNRORI_ADVENTURE_GAME_ACTION_KEYMAP_H

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

    void action_exit_game();
    void action_move_up();
    void action_move_down();
    void action_move_left();
    void action_move_right();

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // UNKNOWNRORI_ADVENTURE_GAME_ACTION_KEYMAP_H