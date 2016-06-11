#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include "theme.h"

class Tile : public QLabel
{
    int row, col;
    int tileNumber;
    bool isDarkTile;
    bool hasPiece;
    bool isWhitePiece;
    char pieceSymbol;

public:
    Tile(int, int, int, bool, QWidget*);

    void showTile(char);
    void setPiece(char, bool);
    void mousePressEvent(QMouseEvent*);
    void displayTileColor();
    void removePiece();

    char getPieceSymbol() {return pieceSymbol;}
    int getRow() {return row;}
    int getCol() {return col;}
    int getTileNumber() {return tileNumber;}
    bool getPieceColor() {return isWhitePiece;}
    bool isOccupied() {return hasPiece;}
};

void unhighlightTiles();
void enforceRules(Tile*);

#endif // TILE_H
