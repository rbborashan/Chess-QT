#include "chessboard.h"
#include "themedialog.h"
#include "aboutdialog.h"
#include "rulebook.h"
#include "ui_chessboard.h"

Tile* board[8][8];
Border* borders[4];
Theme* currentTheme;
QMenu* edit;

int validMoves[64];
int listIndex = 0;
bool isWhiteTurn = true;

extern ThemeDialog* themeEditor;
extern AboutDialog* about;
extern RuleBook* rules;

ChessBoard::ChessBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChessBoard)
{
    ui->setupUi(this);

    initialize(board, this);
    edit = ui->menuE_dit;
    ui->actionSlate->setText("Slate            ✓");
}

void ChessBoard::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QColor(165, 165, 165));
    painter.scale(1.75, 1.75);

    int ypos = 80;
    for (int i = 8; i >= 1; i--, ypos += 55 - (i))
        painter.drawText(25, ypos, QString::number(i));

    int xpos = 80;
    int i = 0;
    for (char ch = 'a'; ch < 'i'; ch++, xpos += 55 - (i++))
        painter.drawText(xpos, ypos, QString(ch));

}

void ChessBoard::closeEvent(QCloseEvent*)
{
    themeEditor->close();
    about->close();
    rules->close();
}

ChessBoard::~ChessBoard()
{
    delete ui;
}

void Border::setOutline(int xpos, int ypos, bool vertical)
{
    if (!vertical)
        setGeometry(xpos, ypos, 740, 10);
    else
        setGeometry(xpos, ypos, 10, 740);

    setStyleSheet(QString("QLabel {background-color: rgb(45, 45, 45); color: black;}"));
}

void initialize(Tile* tiles[8][8], QWidget* _parent)
{    
    currentTheme = new Theme();
    currentTheme->setTheme(Theme::slate);

    for (int i = 0; i < 4; i++)
        borders[i] = new Border(_parent);

    borders[0]->setOutline(100, 70, false);
    borders[1]->setOutline(100, 800, false);
    borders[2]->setOutline(100, 70, true);
    borders[3]->setOutline(830, 70, true);

    int tnum = 0;
    int ypos = 80;
    for (int row = 0; row < 8; row++)   // set up tiles
    {
        int xpos = 110;
        for (int col = 0; col < 8; col++)
        {
            tiles[row][col] = new Tile(row, col, tnum++,
                                ((row+col)&1), _parent);

            tiles[row][col]->setGeometry(xpos, ypos, 90, 90);
            tiles[row][col]->displayTileColor();
            xpos += 90;
        }
        ypos += 90;
    }

    initializePieces(tiles);
}

void initializePieces(Tile* tiles[8][8])
{
    // pawns
    for (int col = 0; col < 8; col++)
    {
        tiles[1][col]->setPiece('p', false);
        tiles[6][col]->setPiece('p', true);
    }

    // black pieces
    tiles[0][0]->setPiece('r', false);
    tiles[0][1]->setPiece('k', false);
    tiles[0][2]->setPiece('b', false);
    tiles[0][3]->setPiece('q', false);
    tiles[0][4]->setPiece('K', false);
    tiles[0][5]->setPiece('b', false);
    tiles[0][6]->setPiece('k', false);
    tiles[0][7]->setPiece('r', false);

    // white pieces
    tiles[7][0]->setPiece('r', true);
    tiles[7][1]->setPiece('k', true);
    tiles[7][2]->setPiece('b', true);
    tiles[7][3]->setPiece('q', true);
    tiles[7][4]->setPiece('K', true);
    tiles[7][5]->setPiece('b', true);
    tiles[7][6]->setPiece('k', true);
    tiles[7][7]->setPiece('r', true);
}

void ChessBoard::updateTheme(Theme::themes selection)
{
    ui->actionSlate->setText("Slate");
    ui->actionClassic->setText("Classic");
    ui->actionLight->setText("Light");
    ui->actionBlue->setText("Blue");
    ui->actionCustom->setText("Custom...");

    switch (selection) {
        case Theme::slate:
            ui->actionSlate->setText("Slate            ✓"); break;
        case Theme::classic:
            ui->actionClassic->setText("Classic          ✓"); break;
        case Theme::light:
            ui->actionLight->setText("Light            ✓"); break;
        case Theme::blue:
            ui->actionBlue->setText("Blue             ✓"); break;
        default:
            ui->actionCustom->setText("Custom...        ✓"); break;
    }

    currentTheme->setTheme(selection);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j]->showTile(board[i][j]->getPieceSymbol());
}

void ChessBoard::on_actionE_xit_triggered() {exit(0);}

void ChessBoard::on_action_New_Game_triggered() {
    isWhiteTurn = true;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j]->isOccupied())
            board[i][j]->removePiece();
        }

    initializePieces(board);
}

void ChessBoard::on_actionSlate_triggered()
{
    updateTheme(Theme::slate);
}

void ChessBoard::on_actionClassic_triggered()
{
    updateTheme(Theme::classic);
}

void ChessBoard::on_actionLight_triggered()
{
    updateTheme(Theme::light);
}

void ChessBoard::on_actionBlue_triggered()
{
    updateTheme(Theme::blue);
}

void ChessBoard::on_actionCustom_triggered()
{
    updateTheme(Theme::custom);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j]->setEnabled(false);

    themeEditor->saveTheme();
    themeEditor->show();
}

void ChessBoard::on_action_About_triggered() {about->show();}

void ChessBoard::on_action_Rules_triggered() {rules->show();}
