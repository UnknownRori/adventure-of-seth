/**
 * @file map.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Header file for defining how map should be structured and work
 * @version 0.1
 * @date 2023-06-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_MAP_H
#define UNKNOWNRORI_ADVENTURE_GAME_MAP_H

#include "../ui/tui.h"
#include "../types.h"
#include "../types/vec2.h"
#include "./entity.h"

typedef struct tile_metadata
{
    wchar_t *m_name;
    wchar_t m_symbol;
} TileMetaData;

typedef struct tile
{
    // ? INFO : Customized by config.h.in
    u32 m_type;

    // Item *m_item;

    // Not Dynamically allocated it was a referenced
    // TODO : Maybe put this as ReferenceCounter struct for safety
    Entity *m_entity;
} Tile;

typedef struct map
{
    // The size of tiles
    Vec2 m_size;

    // Dynamic allocated 1D tiles
    Tile *m_tiles;
} Map;

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

    void map_init(Map *__map, i32 __x, i32 __y);
    void map_deinit(Map *__map);
    void map_clear_all_entity(Map *__map);
    void map_put_entity(Map *__map, Entity *__entity, i32 __x, i32 __y);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // UNKNOWNRORI_ADVENTURE_GAME_MAP_H