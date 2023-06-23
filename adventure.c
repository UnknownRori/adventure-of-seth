#include <stdlib.h>
#include <signal.h>

#include "./src/types.h"
#include "./include/adventure_game.h"

void sigint_handler(i32 signal)
{
    clean_up_game();
    exit(signal);
}

i32 main()
{
    signal(SIGINT, sigint_handler);

    init_game();

    game_loop();

    clean_up_game();

    return 0;
}