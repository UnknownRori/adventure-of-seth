/**
 * @file adventure_game_intern.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Internal header for adventure game
 * @version 0.1
 * @date 2023-06-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_INTERN_H
#define UNKNOWNRORI_ADVENTURE_GAME_INTERN_H

#include "./game/map.h"
#include "./game/player.h"

typedef struct game_global
{
    Map m_map;
    Player *player;
} GameGlobal;

extern GameGlobal *GAME_GLOBAL;

#endif // UNKNOWNRORI_ADVENTURE_GAME_INTERN_H