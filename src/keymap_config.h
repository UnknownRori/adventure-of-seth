#include <ncurses/ncurses.h>

#include "./utility.h"
#include "./game/keymap/keymap.h"
#include "./game/keymap/action.h"

// TODO : For future customizable keymap
const static Keymap KEY_MAP[] = {
    {'q', &action_exit_game},        // Quit
    {'i', nullptr},                  // Open Inventory
    {'d', nullptr},                  // Drop selected item
    {'g', nullptr},                  // Pickup item
    {'o', nullptr},                  // Open door
    {'a', nullptr},                  // Activate item (Attack?)
    {KEY_ENTER, nullptr},            // Select item on inventory
    {KEY_UP, &action_move_up},       // Move up    || Move selection of inventory
    {KEY_DOWN, &action_move_down},   // Move down  || Move selection of inventory
    {KEY_LEFT, &action_move_left},   // Move left
    {KEY_RIGHT, &action_move_right}, // Move right
};
const static usize KEY_MAP_LEN = ARRAY_LEN(KEY_MAP);