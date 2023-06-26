/**
 * @file ui.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief A collection of function to handle of drawing using tui.h wrapper
 * @version 0.1
 * @date 2023-06-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_UI_H
#define UNKNOWNRORI_ADVENTURE_GAME_UI_H

#include "./tui.h"
#include "../game/map.h"

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

    void map_draw(WINDOW *__win, Map *__map, i32 __x, i32 __y);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // UNKNOWNRORI_ADVENTURE_GAME_UI_H