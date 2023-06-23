/**
 * @file game.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief A header file definition of function for using the game
 * @version 0.1
 * @date 2023-06-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_H
#define UNKNOWNRORI_ADVENTURE_GAME_H

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

    void init_game();
    void game_loop();
    void clean_up_game();

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // UNKNOWNRORI_ADVENTURE_GAME_H