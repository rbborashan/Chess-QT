#ifndef GAME_H
#define GAME_H

#include "tile.h"

extern Tile* board[8][8];
extern int validMoves[64];
extern int listIndex;

class Game
{
    bool okToMove;

    bool enforcePawn(Tile*);
    bool enforceRook(Tile*);
    bool enforceKnight(Tile*);
    bool enforceBishop(Tile*);
    bool enforceQueen(Tile*);
    bool enforceKing(Tile*);

    void highlightTiles();

public:
    bool canMove(Tile*);
};

#endif // GAME_H
