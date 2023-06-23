# Design

Simple Dungeon Crawling RPG Design docs

## Game Design

Room will be level in the game, and each room may or may not have loot and enemy, every room has a door atleast 1 door can be used increase the level, or decrease it. Level will correspond how enemy is. Maximum map size is 25x15.

## Enviroment

* 1 Room with only enemy, door, and loot
* Everytime room is entered, new message pop out to describe the room

## Item

List of item :

* Sword
* Katana
* Stick
* Club
* Health Potion
* Increase HP Potion

List of item type :

* Attack Item
* Defense Item
* Special

```c
// Pseudo Code
typedef struct item {
    enum ItemType m_type;

    union {
        f32 attack;
        f32 defense;

        void (*special_action)() // Maybe for potion to increase hp or something ?
    } m_value;
} Item;
```

Item that has defense value can help shave off attack.

## Display

Map Symbol :

* \# : Wall
* X  : Closed Door
* O  : Open Door
* E  : Enemy / Mob
* @  : Player
* I  : Item
* ?  : Invalid Tile (So it visible)

Inventory Symbol :

* \* : List of item
* \- : Empty slot
* \> : Selected Item

```
                        Adventure of Seth


    ##X###########                  === Inventory ===
    #............#                  > * Club
    #..........E.#                    * Health Potion
    #............#                    * -
    #............#                    * -
    #....@.....I.#                    * -
    #............#                    * -
    ##O###########                    * -

    HP : 80/100

    Lorem ipsum message

    Press ? for help
```

```c
// Pseudo code for Tile
typedef struct tile {
    TileType m_type;

    Item *m_items;

    EntityType m_entity_type;
    union {
        Player *player;
        Mob *mob;
    } m_entity;
} Tile;
```
