#include <stdlib.h>
#include <time.h>

#include "../include/adventure_game.h"
#include "./types.h"

#include "./config.h"
#include "./adventure_game_intern.h"
#include "./tui.h"

GameGlobal *GAME_GLOBAL = nullptr;

void game_init();
void game_deinit();

void init_game()
{
    srand((u32)time(nullptr));

    game_init();

    tui_init();
}

void game_loop()
{
    while (true)
    {
        box(MAIN_WINDOW, 0, 0);
        tui_draw_title(MAIN_WINDOW, GAME_TITLE);
        map_draw(MAIN_WINDOW, &(GAME_GLOBAL->m_map), 4, 4);
    }
}

void clean_up_game()
{
    game_deinit();
    tui_deinit();
}

void game_init()
{
    GAME_GLOBAL = calloc(0, sizeof(GameGlobal));
    map_init(&(GAME_GLOBAL->m_map), DEFAULT_MAP_SIZE.x, DEFAULT_MAP_SIZE.y);
}

void game_deinit()
{
    map_deinit(&(GAME_GLOBAL->m_map));
    free(GAME_GLOBAL);
}