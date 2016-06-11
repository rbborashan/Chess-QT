#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QMainWindow>
#include <QtWidgets>

#include "tile.h"

namespace Ui {
class ChessBoard;
}

class ChessBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChessBoard(QWidget* parent = 0);
    void paintEvent(QPaintEvent*);
    void closeEvent(QCloseEvent*);
    ~ChessBoard();

private slots:
    void on_actionE_xit_triggered();
    void on_action_New_Game_triggered();
    void on_actionSlate_triggered();
    void on_actionClassic_triggered();
    void on_actionLight_triggered();
    void on_actionCustom_triggered();
    void on_action_About_triggered();
    void on_action_Rules_triggered();
    void on_actionBlue_triggered();

private:
    Ui::ChessBoard* ui;
    void updateTheme(Theme::themes);
};

class Border : public QLabel
{
public:
    Border(QWidget* parent) : QLabel(parent) {}
    void setOutline(int, int, bool);
};

void initialize(Tile* [8][8], QWidget*);
void initializePieces(Tile* [8][8]);

#endif // CHESSBOARD_H
