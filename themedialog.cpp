#include "themedialog.h"
#include "ui_themedialog.h"
#include "tile.h"

extern Tile* board [8][8];
extern Theme* currentTheme;

ThemeDialog::ThemeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThemeDialog)
{
    ui->setupUi(this);

    redValue = 0;
    greenValue = 0;
    blueValue = 0;

    preview.setParent(this);
    preview.setStyleSheet("QLabel {background-color: rgb(0, 0, 0);}");
    preview.move(361, 20);
    preview.resize(75, 70);

    connect(ui->redBox, SIGNAL(valueChanged(int)), ui->redSlider, SLOT(setValue(int)));
    connect(ui->redSlider, SIGNAL(valueChanged(int)), ui->redBox, SLOT(setValue(int)));
    connect(ui->redBox, SIGNAL(valueChanged(int)), SLOT(updateRed(int)));
    connect(ui->greenBox, SIGNAL(valueChanged(int)), ui->greenSlider, SLOT(setValue(int)));
    connect(ui->greenSlider, SIGNAL(valueChanged(int)), ui->greenBox, SLOT(setValue(int)));
    connect(ui->greenBox, SIGNAL(valueChanged(int)), SLOT(updateGreen(int)));
    connect(ui->blueBox, SIGNAL(valueChanged(int)), ui->blueSlider, SLOT(setValue(int)));
    connect(ui->blueSlider, SIGNAL(valueChanged(int)), ui->blueBox, SLOT(setValue(int)));
    connect(ui->blueBox, SIGNAL(valueChanged(int)), SLOT(updateBlue(int)));

    ui->darkPiecesButton->setChecked(true);
    preview.setStyleSheet(QString("QLabel {background-color: ")
                          + currentTheme->getBlackPieceColor()
                          + QString("}"));
}

void ThemeDialog::enableBoard()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j]->setEnabled(true);
}

void ThemeDialog::updateRed(int value)
{
    redValue = value;
    updateColors();
}

void ThemeDialog::updateGreen(int value)
{
    greenValue = value;
    updateColors();
}

void ThemeDialog::updateBlue(int value)
{
    blueValue = value;
    updateColors();
}

void ThemeDialog::updateColors()
{
    preview.setStyleSheet(QString("QLabel {background-color: ")
                          + getRGBString() + QString("}"));

    if (ui->darkPiecesButton->isChecked()) {
        RGBArgs[3][0] = redValue;
        RGBArgs[3][1] = greenValue;
        RGBArgs[3][2] = blueValue;
    }
    else if (ui->lightPiecesButton->isChecked()) {
        RGBArgs[2][0] = redValue;
        RGBArgs[2][1] = greenValue;
        RGBArgs[2][2] = blueValue;
    }
    else if (ui->darkTilesButton->isChecked()) {
        RGBArgs[0][0] = redValue;
        RGBArgs[0][1] = greenValue;
        RGBArgs[0][2] = blueValue;
    }
    else if (ui->lightTilesButton->isChecked()) {
        RGBArgs[1][0] = redValue;
        RGBArgs[1][1] = greenValue;
        RGBArgs[1][2] = blueValue;
    }
    else if (ui->attackingButton->isChecked()) {
        RGBArgs[7][0] = redValue;
        RGBArgs[7][1] = greenValue;
        RGBArgs[7][2] = blueValue;
    }
    else if (ui->darkPiecesHoverButton->isChecked()) {
        RGBArgs[6][0] = redValue;
        RGBArgs[6][1] = greenValue;
        RGBArgs[6][2] = blueValue;
        }
    else if (ui->lightPiecesHoverButton->isChecked()) {
        RGBArgs[5][0] = redValue;
        RGBArgs[5][1] = greenValue;
        RGBArgs[5][2] = blueValue;
    }
    else if (ui->tileHighlightButton->isChecked()) {
        RGBArgs[4][0] = redValue;
        RGBArgs[4][1] = greenValue;
        RGBArgs[4][2] = blueValue;
    }
}

QString ThemeDialog::getRGBString()
{
    return QString("rgb(") + QString::number(redValue) + QString(", ")
            + QString::number(greenValue) + QString(", ")
            + QString::number(blueValue) + QString(");");
}

void ThemeDialog::saveTheme()
{
    for (int i = 0; i < 3; i++)
    {
        RGBArgs[0][i] = currentTheme->darkBackgroundRGB[i];
        RGBArgs[1][i] = currentTheme->lightBackgroundRGB[i];
        RGBArgs[2][i] = currentTheme->whitePieceRGB[i];
        RGBArgs[3][i] = currentTheme->blackPieceRGB[i];
        RGBArgs[4][i] = currentTheme->hoverBackgroundRGB[i];
        RGBArgs[5][i] = currentTheme->hoverWhitePieceRGB[i];
        RGBArgs[6][i] = currentTheme->hoverBlackPieceRGB[i];
        RGBArgs[7][i] = currentTheme->attackRGB[i];
    }
}

void ThemeDialog::on_applyButton_clicked()
{
    enableBoard();

    currentTheme->setCustomTheme(RGBArgs);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j]->showTile(board[i][j]->getPieceSymbol());

    close();
}

ThemeDialog::~ThemeDialog()
{
    delete ui;
}

void ThemeDialog::on_cancelButton_clicked()
{
    enableBoard();
    close();
}
