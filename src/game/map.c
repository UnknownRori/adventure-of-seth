#include <stdlib.h>
#include <string.h>

#include "./map.h"

#define TILE_AT(__TILES, X__, Y__, __WIDTH) (__TILES[__WIDTH * Y__ + X__])

void generate_default_tile(Tile *m_tiles, i32 __x, i32 __y);

void map_init(Map *__map, i32 __x, i32 __y)
{
    __map->m_size.x = __x;
    __map->m_size.y = __y;
    __map->m_tiles = calloc((usize)__x * (usize)__y, sizeof(Tile));

    generate_default_tile(__map->m_tiles, __x, __y);
}

void map_deinit(Map *__map)
{
    free(__map->m_tiles);
}

void generate_default_tile(Tile *__tiles, i32 __width, i32 __height)
{
    for (i32 y = 0; y < __height; y++)
    {
        for (i32 x = 0; x < __width; x++)
        {
            // Make a wall on edges
            if (y == 0 || y == __height - 1 || x == 0 || x == __width - 1)
            {
                TILE_AT(__tiles, x, y, __width).m_type = 1;
            }
            else
            {
                TILE_AT(__tiles, x, y, __width).m_type = 0;
            }
        }
    }
}

void map_clear_all_entity(Map *__map)
{
    for (i32 y = 0; y < __map->m_size.y; y++)
    {
        for (i32 x = 0; x < __map->m_size.x; x++)
        {
            TILE_AT(__map->m_tiles, x, y, __map->m_size.x).m_entity = nullptr;
        }
    }
}

// TODO : Implement this
void map_put_entity(Map *__map, Entity *__entity, i32 __x, i32 __y)
{
    TILE_AT(__map->m_tiles, __x, __y, __map->m_size.x).m_entity = __entity;
}