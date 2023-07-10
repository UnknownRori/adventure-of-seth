#include <stdlib.h>

#include "./action.h"
#include "../../ui/tui.h"

#include "../../adventure_game_intern.h"

void action_exit_game()
{
    // TODO : Maybe do more clean up
    tui_deinit();
    exit(0);
}
void action_move_up()
{
    if (GAME_GLOBAL->player->m_ptr.player->m_pos.y = 1)
        GAME_GLOBAL->player->m_ptr.player->m_pos.y -= 1;
}

void action_move_down()
{
    if (GAME_GLOBAL->player->m_ptr.player->m_pos.y < GAME_GLOBAL->m_map.m_size.y)
        GAME_GLOBAL->player->m_ptr.player->m_pos.y += 1;
}

void action_move_left()
{
    if (GAME_GLOBAL->player->m_ptr.player->m_pos.x > 1)
        GAME_GLOBAL->player->m_ptr.player->m_pos.x -= 1;
}

void action_move_right()
{
    if (GAME_GLOBAL->player->m_ptr.player->m_pos.x < GAME_GLOBAL->m_map.m_size.x)
        GAME_GLOBAL->player->m_ptr.player->m_pos.x += 1;
}