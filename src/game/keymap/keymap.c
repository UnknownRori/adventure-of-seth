#include "./keymap.h"
#include "../../keymap_config.h"

bool get_key(const i32 __char_code, Keymap *__key_map)
{
    for (usize i = 0; i < KEY_MAP_LEN; i++)
    {
        if (KEY_MAP[i].m_char_code == __char_code)
        {
            // TODO : Maybe some optimization in here (?)
            *__key_map = KEY_MAP[i];
            return true;
        }
    }

    return false;
}

bool exec_key_action(const Keymap *__key)
{
    if (__key->m_action == nullptr)
        return false;

    (*(__key->m_action))();

    return true;
}