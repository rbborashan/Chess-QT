#include "game.h"

extern bool isWhiteTurn;
extern Theme* currentTheme;

bool Game::canMove(Tile* tile)
{
    switch(tile->getPieceSymbol())
    {
        case 'p':
            okToMove = enforcePawn(tile); break;
        case 'r':
            okToMove = enforceRook(tile); break;
        case 'k':
            okToMove = enforceKnight(tile); break;
        case 'b':
            okToMove = enforceBishop(tile); break;
        case 'q':
            okToMove = enforceQueen(tile); break;
        case 'K':
            okToMove = enforceKing(tile); break;
        default:
            break;
    }

    highlightTiles();
    return okToMove;
}

bool Game::enforcePawn(Tile* tile) {
    bool ok = false;
    int row = tile->getRow();
    int col = tile->getCol();

    if (tile->getPieceColor()) {
        if (row-1 >= 0 && !board[row-1][col]->isOccupied()) {
            validMoves[listIndex++] = board[row-1][col]->getTileNumber();
            ok = true;
        }
        if (row == 6 && !board[5][col]->isOccupied() && !board[4][col]->isOccupied()) {
            validMoves[listIndex++] = board[row-2][col]->getTileNumber();
            ok = true;
        }
        if (row-1 >= 0 && col-1 >= 0) {
            if (board[row-1][col-1]->getPieceColor() != tile->getPieceColor() &&
                board[row-1][col-1]->isOccupied()) {
                validMoves[listIndex++] = board[row-1][col-1]->getTileNumber();
                ok = true;
            }
        }
        if (row-1 >= 0 && col+1 <= 7) {
            if (board[row-1][col+1]->getPieceColor() != tile->getPieceColor() &&
                board[row-1][col+1]->isOccupied()) {
                validMoves[listIndex++] = board[row-1][col+1]->getTileNumber();
                ok = true;
            }
        }
    }
    else {
        if (row+1 <= 7 && !board[row+1][col]->isOccupied()) {
            validMoves[listIndex++] = board[row+1][col]->getTileNumber();
            ok = true;
        }
        if (row == 1 && !board[2][col]->isOccupied() && !board[3][col]->isOccupied()) {
            validMoves[listIndex++] = board[row+2][col]->getTileNumber();
            ok = true;
        }
        if (row+1 <= 7 && col-1 >= 0) {
            if (board[row+1][col-1]->getPieceColor() != tile->getPieceColor() &&
                board[row+1][col-1]->isOccupied()) {
                validMoves[listIndex++] = board[row+1][col-1]->getTileNumber();
                ok = true;
            }
        }
        if (row+1 <= 7 && col+1 <= 7) {
            if (board[row+1][col+1]->getPieceColor() != tile->getPieceColor() &&
                board[row+1][col+1]->isOccupied()) {
                validMoves[listIndex++] = board[row+1][col+1]->getTileNumber();
                ok = true;
            }
        }
    }
    return ok;
}

bool Game::enforceRook(Tile* tile) {
    bool ok = false;
    int row = tile->getRow();
    int col = tile->getCol();

    while (row-- > 0) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;
        else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    row = tile->getRow();
    col = tile->getCol();

    while (row++ < 7) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;
        else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    row = tile->getRow();
    col = tile->getCol();

    while (col++ < 7) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;
        else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    row = tile->getRow();
    col = tile->getCol();

    while (col-- > 0) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;

        else if (board[row][col]->getPieceColor() != tile->getPieceColor())
        {
            validMoves[listIndex++]=board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    return ok;
}

bool Game::enforceKnight(Tile* tile) {
    bool ok = false;
    int row = tile->getRow();
    int col = tile->getCol();

    if (row-2 >= 0 && col-1 >= 0) {
        if (board[row-2][col-1]->getPieceColor() != tile->getPieceColor() ||
            !board[row-2][col-1]->isOccupied()) {
            validMoves[listIndex++] = board[row-2][col-1]->getTileNumber();
            ok = true;
        }
    }
    if (row-2 >= 0 && col+1 <= 7) {
        if (board[row-2][col+1]->getPieceColor() != tile->getPieceColor() ||
            !board[row-2][col+1]->isOccupied()) {
            validMoves[listIndex++] = board[row-2][col+1]->getTileNumber();
            ok = true;
        }
    }
    if (row-1 >= 0 && col-2 >= 0) {
        if (board[row-1][col-2]->getPieceColor() != tile->getPieceColor() ||
            !board[row-1][col-2]->isOccupied()) {
            validMoves[listIndex++] = board[row-1][col-2]->getTileNumber();
            ok = true;
        }
    }
    if (row-1 >= 0 && col+2 <= 7) {
        if (board[row-1][col+2]->getPieceColor() != tile->getPieceColor() ||
            !board[row-1][col+2]->isOccupied()) {
            validMoves[listIndex++] = board[row-1][col+2]->getTileNumber();
            ok = true;
        }
    }
    if (row+2 <= 7 && col+1 <= 7) {
        if (board[row+2][col+1]->getPieceColor() != tile->getPieceColor() ||
            !board[row+2][col+1]->isOccupied()) {
            validMoves[listIndex++] = board[row+2][col+1]->getTileNumber();
            ok = true;
        }
    }
    if (row+2 <= 7 && col-1 >= 0) {
        if (board[row+2][col-1]->getPieceColor() != tile->getPieceColor() ||
            !board[row+2][col-1]->isOccupied()) {
            validMoves[listIndex++] = board[row+2][col-1]->getTileNumber();
            ok = true;
        }
    }
    if (row+1 <= 7 && col-2 >= 0) {
        if (board[row+1][col-2]->getPieceColor() != tile->getPieceColor() ||
            !board[row+1][col-2]->isOccupied()) {
            validMoves[listIndex++]=board[row+1][col-2]->getTileNumber();
            ok = true;
        }
    }
    if (row+1 <= 7 && col+2 <= 7) {
        if (board[row+1][col+2]->getPieceColor() != tile->getPieceColor()
            || !board[row+1][col+2]->isOccupied()) {
            validMoves[listIndex++] = board[row+1][col+2]->getTileNumber();
            ok = true;
        }
    }
    return ok;
}

bool Game::enforceBishop(Tile* tile) {
    bool ok = false;
    int row = tile->getRow();
    int col = tile->getCol();

    while (row-- > 0 && col++ < 7) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;
        else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    row = tile->getRow();
    col = tile->getCol();

    while (row-- > 0 && col-- > 0) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;
        else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    row = tile->getRow();
    col = tile->getCol();

    while (row++ < 7 && col++ < 7) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;
        else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    row = tile->getRow();
    col = tile->getCol();

    while (row++ < 7 && col-- > 0) {
        if (!board[row][col]->isOccupied()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
        }
        else if (board[row][col]->getPieceColor() == tile->getPieceColor())
            break;
        else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col]->getTileNumber();
            ok = true;
            break;
        }
    }
    return ok;
}

bool Game::enforceQueen(Tile* tile) {
    bool ok = false;
    int row = tile->getRow();
    int col = tile->getCol();

    while (row-- > 0) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     row = tile->getRow();
     col = tile->getCol();

     while (row++ < 7) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     row = tile->getRow();
     col = tile->getCol();

     while (col++ < 7) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     row = tile->getRow();
     col = tile->getCol();

     while (col-- > 0) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     row = tile->getRow();
     col = tile->getCol();

     while (row-- > 0 && col++ < 7) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     row = tile->getRow();
     col = tile->getCol();

     while (row-- > 0 && col-- > 0) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     row = tile->getRow();
     col = tile->getCol();
     while (row++ < 7 && col++ < 7) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     row = tile->getRow();
     col = tile->getCol();

     while (row++ < 7 && col-- > 0) {
         if (!board[row][col]->isOccupied()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
         }
         else if (board[row][col]->getPieceColor() == tile->getPieceColor())
             break;
         else if (board[row][col]->getPieceColor() != tile->getPieceColor()) {
             validMoves[listIndex++] = board[row][col]->getTileNumber();
             ok = true;
             break;
         }
     }
     return ok;
}

bool Game::enforceKing(Tile* tile) {
    bool ok = false;
    int row = tile->getRow();
    int col = tile->getCol();

    if (row-1 >= 0) {
        if (!board[row-1][col]->isOccupied() ||
            board[row-1][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row-1][col]->getTileNumber();
            ok = true;
        }
    }
    if (row+1 <= 7) {
        if (!board[row+1][col]->isOccupied() ||
            board[row+1][col]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row+1][col]->getTileNumber();
            ok = true;
        }
    }
    if (col-1 >= 0) {
        if (!board[row][col-1]->isOccupied() ||
            board[row][col-1]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row][col-1]->getTileNumber();
            ok = true;
        }
    }
    if (col+1 <= 7) {
        if (!board[row][col+1]->isOccupied() ||
            board[row][col+1]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++]=board[row][col+1]->getTileNumber();
            ok = true;
        }
    }
    if (row-1 >= 0 && col-1 >= 0) {
        if (!board[row-1][col-1]->isOccupied() ||
            board[row-1][col-1]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row-1][col-1]->getTileNumber();
            ok = true;
        }
    }
    if (row-1 >= 0 && col+1 <= 7) {
        if (!board[row-1][col+1]->isOccupied() ||
            board[row-1][col+1]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row-1][col+1]->getTileNumber();
            ok = true;
        }
    }
    if (row+1 <= 7 && col-1 >= 0) {
        if (!board[row+1][col-1]->isOccupied() ||
            board[row+1][col-1]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row+1][col-1]->getTileNumber();
            ok = true;
        }
    }
    if (row+1 <= 7 && col+1 <= 7) {
        if (!board[row+1][col+1]->isOccupied() ||
            board[row+1][col+1]->getPieceColor() != tile->getPieceColor()) {
            validMoves[listIndex++] = board[row+1][col+1]->getTileNumber();
            ok = true;
        }
    }
    return ok;
}

void Game::highlightTiles() {
    Tile* tile;
    for (int i = 0; i < listIndex; i++) {
        tile = board[validMoves[i]/8][validMoves[i]&7];

        if (tile->isOccupied()) {
            if (tile->getPieceColor()) {
                tile->setStyleSheet(QString("QLabel {background-color: ")
                                    + currentTheme->getAttackBackground()
                                    + QString(" color: ") +
                                    currentTheme->getHoverColorWhite() + QString("}"));
            }
            else {
                tile->setStyleSheet(QString("QLabel {background-color: ")
                                    + currentTheme->getAttackBackground()
                                    + QString(" color: ") +
                                    currentTheme->getHoverColorBlack() + QString("}"));
            }
        }
        else
            tile->setStyleSheet(QString("QLabel {background-color: ")
                                + currentTheme->getHoverBackground()
                                + QString("}"));
    }
}
