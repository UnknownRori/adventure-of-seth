CC = gcc
FLAGS = -Wall -Werror -Wconversion -Wundef -Wshadow -Wdouble-promotion -Wformat-signedness -fno-common -Wformat=2 -std=c17
DEBUG = -g -DDEBUG -DCOLORED -fstack-usage -fbounds-check -fno-omit-frame-pointer -ggdb

LIBS_FLAGS = -DNCURSES_STATIC -lncurses -static

TEMP = temp
DIST = dist

MAIN_SRC = adventure.c
MAIN_ELF = ./$(TEMP)/adventure

GAME_SRC = ./src/adventure_game.c \
           ./src/ui/tui.c \
           ./src/game/map.c \
           ./src/ui/ui.c \
           ./src/game/player.c \
           ./src/game/keymap/action.c \
           ./src/game/keymap/keymap.c \

all: build
	# $(MAIN_ELF)

build: setup
	$(CC) $(MAIN_SRC) $(GAME_SRC) -o $(MAIN_ELF) $(FLAGS) $(DEBUG) $(LIBS_FLAGS)

setup:
	([ ! -e ./$(DIST) ] && mkdir $(DIST)) || [ -e ./$(DIST) ]
	([ ! -e ./$(TEMP) ] && mkdir $(TEMP)) || [ -e ./$(TEMP) ]
	([ ! -e ./src/config.h ] && cp ./config.h.in ./src/config.h) || [ -e ./src/config.h ]

clean: setup
	rm -r ./$(TEMP) & rm -r ./$(DIST)
	
