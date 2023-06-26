#include <stdlib.h>

#include "./entity.h"
#include "./player.h"

// TODO : Make it more efficient and easy to maintain

EntityPlayer *player_init(i32 __default_max_hp, i32 __x, i32 __y)
{
    Entity *temp = calloc(1, sizeof(Entity));
    temp->m_type = 0;

    temp->m_ptr.player = calloc(1, sizeof(Player));
    temp->m_ptr.player->m_hp = __default_max_hp;
    temp->m_ptr.player->m_maxhp = __default_max_hp;
    temp->m_ptr.player->m_pos.y = __y;
    temp->m_ptr.player->m_pos.x = __x;

    return temp;
}

void player_deinit(EntityPlayer *__player)
{
    free(__player->m_ptr.player);
    free(__player);
}
