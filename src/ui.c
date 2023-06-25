#include "./config.h"

#include "./ui.h"

#define TILE_AT(__TILES, X__, Y__, __WIDTH) (__TILES[__WIDTH * Y__ + X__])

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
