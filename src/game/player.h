/**
 * @file player.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Define player behaviors
 * @version 0.1
 * @date 2023-06-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_PLAYER_H
#define UNKNOWNRORI_ADVENTURE_GAME_PLAYER_H

#include "../types/vec2.h"
#include "./entity.h"

// TODO : Make it more efficient and easy to maintain

/// @brief Derive from entity
typedef struct player
{
    i32 m_hp, m_maxhp;
    Vec2 m_pos;
} Player;

typedef struct entity EntityPlayer;

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

    EntityPlayer *player_init(i32 __default_max_hp, i32 __y, i32 __x);
    void player_deinit(EntityPlayer *__entity);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // UNKNOWNRORI_ADVENTURE_GAME_PLAYER_H