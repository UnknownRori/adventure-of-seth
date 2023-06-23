#include "./include/adventure_game.h"

int main()
{
    init_game();

    game_loop();

    clean_up_game();

    return 0;
}