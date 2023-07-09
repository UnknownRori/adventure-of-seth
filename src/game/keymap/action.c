#include <stdlib.h>

#include "./action.h"
#include "../../ui/tui.h"

void action_exit_game()
{
    // TODO : Maybe do more clean up
    tui_deinit();
    exit(0);
}