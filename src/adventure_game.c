#include <stdlib.h>
#include <time.h>

#include "../include/adventure_game.h"
#include "./types.h"

#include "./config.h"
#include "./tui.h"

void init_game()
{
    srand((u32)time(nullptr));

    tui_init();
}

void game_loop()
{
    while (true)
    {
        box(MAIN_WINDOW, 0, 0);
        tui_draw_title(MAIN_WINDOW, GAME_TITLE);
    }
}

void clean_up_game()
{
    tui_deinit();
}