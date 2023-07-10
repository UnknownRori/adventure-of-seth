/**
 * @file keymap.h
 * @author UnknownRori (68576836+UnknownRori@users.noreply.github.com)
 * @brief Header file for defining a specific action that should be execute
 * @version 0.1
 * @date 2023-07-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef UNKNOWNRORI_ADVENTURE_GAME_KEYMAP_H
#define UNKNOWNRORI_ADVENTURE_GAME_KEYMAP_H

#include <stdbool.h>

#include "../../types.h"

#define KEYMAP_ZEROED(__VAR) (memset(__VAR, 0, sizeof(Keymap)));

typedef struct keymap
{
    i32 m_char_code;
    void (*m_action)();
} Keymap;

#if defined(__cplusplus)
extern "C"
{
#endif // __cplusplus

    bool get_key(const i32 __char_code, Keymap *__key_map);
    bool exec_key_action(const Keymap *__key);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // UNKNOWNRORI_ADVENTURE_GAME_KEYMAP_H