#include <stdlib.h>

#include "./config.h"
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

void map_draw(WINDOW *__win, Map *__map, i32 __x, i32 __y)
{
    i32 __width = __map->m_size.x;
    i32 __height = __map->m_size.y;

    wmove(__win, __x, __y);
    for (i32 yindex = 0; yindex < __height; yindex++)
    {
        for (i32 xindex = 0; xindex < __width; xindex++)
        {
            Tile temp = TILE_AT(__map->m_tiles, xindex, yindex, __map->m_size.x);
            wprintw(__win, "%lc", TILE_META[temp.m_type].m_symbol);
        }

        const i32 new_y_pos = __y + yindex + 1;
        wmove(__win, new_y_pos, __x);
    }
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