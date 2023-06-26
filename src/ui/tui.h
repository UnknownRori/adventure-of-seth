/**
 * @file tui.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief A definition for wrapper of ncurses so it's not pain in ars
 * @version 0.1
 * @date 2023-06-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_TUI_H
#define UNKNOWNRORI_ADVENTURE_GAME_TUI_H

#include <ncurses/ncurses.h>

#include "../types.h"
#include "../types/vec2.h"

#define MAIN_WINDOW stdscr

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

    /**
     * @brief Initialize TUI using `ncurses` library
     *
     */
    void tui_init();

    /**
     * @brief Draw a title on first line at center of the window
     *
     * @param __win
     * @param __title
     * @param __repeat
     */
    void tui_draw_title(WINDOW *__win, const wchar_t *__title);

    /**
     * @brief Draw a title on first line at center of the window and repeat something
     *
     * @param __win
     * @param __title
     * @param __repeat
     */
    void tui_draw_title_repeat(WINDOW *__win, const wchar_t *__title, const wchar_t repeat);

    /**
     * @brief Draw a text on specific coordinate with attribute
     *
     * @param __win
     * @param __title
     * @param __coordinate
     * @param __attribute
     */
    void tui_draw_text(WINDOW *__win, const wchar_t *__title, Vec2 __coordinate, i32 __atr);

    /**
     * @brief Get the window size object
     *
     * @param __win
     * @param y
     * @param x
     */
    void tui_get_window_size(WINDOW *__win, i32 *y, i32 *x);

    /**
     * @brief Create window with box around it
     *
     * @param __size
     * @param __coordinate
     * @return WINDOW*
     */
    WINDOW *tui_create_window(i32 __height, i32 __width, i32 __y, i32 __x);

    /**
     * @brief Destroy window
     *
     * @param __win
     */
    void tui_end_window(WINDOW *__win);

    /**
     * @brief End TUI
     *
     */
    void tui_deinit();

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // UNKNOWNRORI_ADVENTURE_GAME_TUI_H