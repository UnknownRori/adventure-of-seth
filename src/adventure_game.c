#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "../include/adventure_game.h"
#include "./types.h"

#include "./config.h"
#include "./adventure_game_intern.h"

#include "./ui/tui.h"
#include "./ui/ui.h"

#include "./game/keymap/keymap.h"

GameGlobal *GAME_GLOBAL = nullptr;
WINDOW *MAP_WINDOW = nullptr;
Keymap CURRENT_KEY = {0};

static inline void game_init();
static inline void game_deinit();
static inline void get_exec_user_input();

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

    GAME_GLOBAL->player = player_init(100, 2, 2);
    map_put_entity(&(GAME_GLOBAL->m_map), GAME_GLOBAL->player, 2, 2);
}

void game_loop()
{
    while (true)
    {
        map_draw(MAP_WINDOW, &(GAME_GLOBAL->m_map), 1, 1);
        get_exec_user_input();
    }
}

void clean_up_game()
{
    game_deinit();
    tui_deinit();
}

static inline void game_init()
{
    GAME_GLOBAL = calloc(1, sizeof(GameGlobal));
    map_init(&(GAME_GLOBAL->m_map), DEFAULT_MAP_SIZE.x, DEFAULT_MAP_SIZE.y);

    MAP_WINDOW = tui_create_window(DEFAULT_MAP_SIZE.y + 2, DEFAULT_MAP_SIZE.x + 2, 4, 4);

    assert(MAP_WINDOW != nullptr);

    KEYMAP_ZEROED(&CURRENT_KEY);
}

static inline void game_deinit()
{
    map_deinit(&(GAME_GLOBAL->m_map));
    free(GAME_GLOBAL);
}

static inline void get_exec_user_input()
{
    int in = getch();
    if (get_key(in, &CURRENT_KEY))
    {
        exec_key_action(&CURRENT_KEY);
    }
}