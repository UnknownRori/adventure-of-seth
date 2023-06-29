#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "../include/adventure_game.h"
#include "./types.h"

#include "./config.h"
#include "./adventure_game_intern.h"
#include "./ui/tui.h"
#include "./ui/ui.h"

GameGlobal *GAME_GLOBAL = nullptr;
WINDOW *MAP_WINDOW = nullptr;

void game_init();
void game_deinit();

void init_game()
{
    srand((u32)time(nullptr));

    tui_init();

    game_init();

    box(MAIN_WINDOW, 0, 0);
    tui_draw_title(MAIN_WINDOW, GAME_TITLE);

    box(MAP_WINDOW, 0, 0);
    tui_draw_title(MAP_WINDOW, L"MAP");
    map_draw(MAP_WINDOW, &(GAME_GLOBAL->m_map), 1, 1);
}

void game_loop()
{
    while (true)
    {
        // TODO : Implement something here
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

    MAP_WINDOW = tui_create_window(DEFAULT_MAP_SIZE.y + 2, DEFAULT_MAP_SIZE.x + 2, 4, 4);

    assert(MAP_WINDOW != nullptr);
}

void game_deinit()
{
    map_deinit(&(GAME_GLOBAL->m_map));
    free(GAME_GLOBAL);
}