/**
 * @file entity.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Entity related stuff is here
 * @version 0.1
 * @date 2023-06-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_ENTITY_H
#define UNKNOWNRORI_ADVENTURE_GAME_ENTITY_H

#include "../types.h"
#include "./player.h"

typedef struct entity_metadata
{
    wchar_t *m_name;
    wchar_t m_symbol;
} EntityMetaData;

// TODO : Make it more efficient and easy to maintain
typedef struct entity
{
    u32 m_type;

    union
    {
        Player *player;
    } m_ptr;
} Entity;

#endif // UNKNOWNRORI_ADVENTURE_GAME_ENTITY_H