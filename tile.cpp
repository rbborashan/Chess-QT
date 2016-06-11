#include <QMenu>
#include "tile.h"
#include "game.h"

Game* game = new Game();
Tile* selectedTile;
int numTilesClicked = 0;

extern Theme* currentTheme;
extern QMenu* edit;
extern bool isWhiteTurn;

Tile::Tile(int _row, int _col, int _tileNumber, bool _isDarkTile, QWidget* _parent)
    : row(_row), col(_col), tileNumber(_tileNumber), isDarkTile(_isDarkTile),
      hasPiece(false), QLabel(_parent) {}

void Tile::setPiece(char symbol, bool isWhite)
{
    hasPiece = true;
    isWhitePiece = isWhite;
    pieceSymbol = symbol;
    showTile(symbol);
}

void Tile::showTile(char symbol)
{
    QFont pieceFont = this->font();

    pieceFont.setPointSize(60);
    setFont(pieceFont);

    pieceSymbol = symbol;

    if (hasPiece)
    {
        switch (symbol)
        {
            case 'p':
                setText("♟"); break;
            case 'r':
                setText("♜"); break;
            case 'k':
                setText("♞"); break;
            case 'b':
                setText("♝"); break;
            case 'K':
                setText("♚"); break;
            case 'q':
                setText("♛"); break;
            default:
                break;
        }
    }

    else
        clear();

    setAlignment(Qt::AlignCenter);
    displayTileColor();
}

void Tile::displayTileColor()
{
    if (isDarkTile)
    {
        if (isWhitePiece)
        {
             setStyleSheet(QString("QLabel {background-color: ") + currentTheme->getDarkBackground() +
                           QString(" color: ") + currentTheme->getWhitePieceColor() +
                           QString("} :hover {background-color: ") + currentTheme->getHoverBackground() +
                           QString(" color: ") + currentTheme->getHoverColorWhite() + QString("}"));
        }
        else
        {
            setStyleSheet(QString("QLabel {background-color: ") + currentTheme->getDarkBackground() +
                          QString(" color: ") + currentTheme->getBlackPieceColor() +
                          QString("} :hover {background-color: ") + currentTheme->getHoverBackground() +
                          QString(" color: ") + currentTheme->getHoverColorBlack() + QString("}"));
        }
    }
    else
    {
        if (isWhitePiece)
        {
            setStyleSheet(QString("QLabel {background-color: ") + currentTheme->getLightBackground() +
                          QString(" color: ") + currentTheme->getWhitePieceColor() +
                          QString("} :hover {background-color: ") + currentTheme->getHoverBackground() +
                          QString(" color: ") + currentTheme->getHoverColorWhite() + QString("}"));
        }
        else
        {
            setStyleSheet(QString("QLabel {background-color: ") + currentTheme->getLightBackground() +
                          QString(" color: ") + currentTheme->getBlackPieceColor() +
                          QString("} :hover {background-color: ") + currentTheme->getHoverBackground() +
                          QString(" color: ") + currentTheme->getHoverColorBlack() + QString("}"));
        }
    }
}

void Tile::removePiece()
{
    hasPiece = false;
    setText("");
}

void Tile::mousePressEvent(QMouseEvent*)
{
    ++numTilesClicked;
    enforceRules(this);
}

void unhighlightTiles()
{
    for (int i = 0; i < listIndex; i++)
        board[validMoves[i]/8][validMoves[i]&7]->displayTileColor();

    edit->setEnabled(true);
}

void enforceRules(Tile* tile) {
    if (numTilesClicked == 1) {
        if (tile->isOccupied() && tile->getPieceColor() == isWhiteTurn) {
            if (game->canMove(tile)) {
                edit->setEnabled(false);
                selectedTile = tile;
                if (tile->getPieceColor()) {
                    selectedTile->setStyleSheet(QString("QLabel {background-color:") +
                                            currentTheme->getHoverBackground() + "color: "
                                            + currentTheme->getHoverColorWhite() + QString("}"));
                }
                else {
                    selectedTile->setStyleSheet(QString("QLabel {background-color:") +
                                            currentTheme->getHoverBackground() + "color: "
                                            + currentTheme->getHoverColorBlack() + QString("}"));
                }
            }
            else
                numTilesClicked = 0;
        }
        else
            numTilesClicked = 0;
    }
    else {
        if (tile->getTileNumber() == selectedTile->getTileNumber()) {
            selectedTile->displayTileColor();
            unhighlightTiles();
            listIndex = 0;
            numTilesClicked = 0;
        }
        for (int i = 0; i < listIndex; i++){
            if (tile->getTileNumber() == validMoves[i]){
                tile->setPiece(selectedTile->getPieceSymbol(),
                               selectedTile->getPieceColor());
                selectedTile->removePiece();
                selectedTile->showTile(selectedTile->getPieceSymbol());
                tile->showTile(selectedTile->getPieceSymbol());

                unhighlightTiles();
                listIndex = 0;
                isWhiteTurn = (isWhiteTurn+1) & 1;
                numTilesClicked = 0;
            }
            else
                numTilesClicked = 1;
        }
    }
}
