#include <string.h>

#include <ncurses/ncurses.h>

#include "./tui.h"
#include "./types.h"
#include "./vec2.h"

// TODO : for future optimization, maybe?
typedef struct tui_window
{
    Vec2 m_size;
    WINDOW *m_win;
} TuiWindow;

/**
 * @brief Repeat a wchar_t on specific count on specific Window
 *
 */
#define REPEAT_CHAR(__WIN, __CHAR, __COUNT)    \
    {                                          \
        for (size_t i = 0; i < (__COUNT); i++) \
        {                                      \
            wprintw((__WIN), "%lc", (__CHAR)); \
        }                                      \
    }

i32 TERM_WIDTH, TERM_HEIGHT = 0;

inline static i32 half_len_from_width(const wchar_t *__str, i32 __width);

/**
 * @brief Initialize TUI using `ncurses` library
 *
 */
void tui_init()
{
    initscr();

    noecho();
    keypad(stdscr, true);

    tui_get_window_size(stdscr, &TERM_HEIGHT, &TERM_WIDTH);
    clear();

#if defined(DEBUG)
    mvprintw(TERM_HEIGHT - 2, 1, "(?) TERM SIZE : %d : %d", TERM_WIDTH, TERM_HEIGHT);
#endif
}

/**
 * @brief Draw a title on first line at center of the window
 *
 * @param __win
 * @param __title
 * @param __repeat
 */
void tui_draw_title(WINDOW *__win, const wchar_t *__title)
{
    i32 x, y;
    tui_get_window_size(__win, &y, &x);
    i32 len_half = half_len_from_width(__title, x);

    Vec2 coordinate = {
        .x = len_half,
        .y = 0,
    };

    tui_draw_text(__win, __title, coordinate, A_BOLD | A_UNDERLINE);

    wrefresh(__win);
}

/**
 * @brief Draw a title on first line at center of the window and repeat something
 *
 * @param __win
 * @param __title
 * @param __repeat
 */
void tui_draw_title_repeat(WINDOW *__win, const wchar_t *__title, const wchar_t __repeat)
{
    i32 x, y;
    tui_get_window_size(__win, &y, &x);
    i32 len_half = half_len_from_width(__title, x);

    wmove(__win, 0, 0);
    REPEAT_CHAR(__win, __repeat, len_half);

    wattron(__win, A_BOLD | A_UNDERLINE);
    wprintw(__win, "%ls", __title);
    wattroff(__win, A_BOLD | A_UNDERLINE);

    REPEAT_CHAR(__win, __repeat, len_half);

    wrefresh(__win);
}

void tui_draw_text(WINDOW *__win, const wchar_t *__title, Vec2 __coordinate, i32 __atr)
{
    wmove(__win, __coordinate.y, __coordinate.x);

    wattron(__win, __atr);
    wprintw(__win, "%ls", __title);
    wattroff(__win, __atr);
}

void tui_get_window_size(WINDOW *__win, i32 *y, i32 *x)
{
    getmaxyx(__win, *y, *x);
}

/**
 * @brief Create window with box around it
 *
 * @param __size
 * @param __coordinate
 * @return WINDOW*
 */
WINDOW *tui_create_window(Vec2 __size, Vec2 __coordinate)
{
    WINDOW *temp = newwin(__size.y, __size.x, __coordinate.y, __coordinate.x);

    box(temp, 0, 0);
    wrefresh(temp);

    return temp;
}

/**
 * @brief Destroy window
 *
 * @param __win
 */
void tui_end_window(WINDOW *__win)
{
    delwin(__win);
}

/**
 * @brief End TUI
 *
 */
void tui_deinit()
{
    clear();
    endwin();
}

inline static i32 half_len_from_width(const wchar_t *__str, i32 __width)
{
    i32 str_len = (i32)wcsnlen(__str, (usize)TERM_WIDTH);
    return (__width - str_len) / 2;
}
