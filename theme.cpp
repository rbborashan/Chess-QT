#include "theme.h"

void Theme::setTheme(themes selection)
{
    switch (selection) {
        case slate:
            darkBackgroundRGB[0] = 75;
            darkBackgroundRGB[1] = 75;
            darkBackgroundRGB[2] = 75;
            lightBackgroundRGB[0] = 145;
            lightBackgroundRGB[1] = 145;
            lightBackgroundRGB[2] = 145;
            whitePieceRGB[0] = 195;
            whitePieceRGB[1] = 195;
            whitePieceRGB[2] = 195;
            blackPieceRGB[0] = 30;
            blackPieceRGB[1] = 30;
            blackPieceRGB[2] = 30;
            hoverBackgroundRGB[0] = 255;
            hoverBackgroundRGB[1] = 255;
            hoverBackgroundRGB[2] = 153;
            hoverWhitePieceRGB[0] = 160;
            hoverWhitePieceRGB[1] = 160;
            hoverWhitePieceRGB[2] = 160;
            hoverBlackPieceRGB[0] = 10;
            hoverBlackPieceRGB[1] = 10;
            hoverBlackPieceRGB[2] = 10;
            attackRGB[0] = 115;
            attackRGB[1] = 0;
            attackRGB[2] = 0;
            break;
        case classic:
            darkBackgroundRGB[0] = 87;
            darkBackgroundRGB[1] = 66;
            darkBackgroundRGB[2] = 0;
            lightBackgroundRGB[0] = 190;
            lightBackgroundRGB[1] = 184;
            lightBackgroundRGB[2] = 136;
            whitePieceRGB[0] = 255;
            whitePieceRGB[1] = 255;
            whitePieceRGB[2] = 255;
            blackPieceRGB[0] = 0;
            blackPieceRGB[1] = 0;
            blackPieceRGB[2] = 0;
            hoverBackgroundRGB[0] = 200;
            hoverBackgroundRGB[1] = 200;
            hoverBackgroundRGB[2] = 0;
            hoverWhitePieceRGB[0] = 255;
            hoverWhitePieceRGB[1] = 255;
            hoverWhitePieceRGB[2] = 255;
            hoverBlackPieceRGB[0] = 10;
            hoverBlackPieceRGB[1] = 10;
            hoverBlackPieceRGB[2] = 10;
            attackRGB[0] = 255;
            attackRGB[1] = 20;
            attackRGB[2] = 20;
            break;
        case light:
            darkBackgroundRGB[0] = 120;
            darkBackgroundRGB[1] = 120;
            darkBackgroundRGB[2] = 120;
            lightBackgroundRGB[0] = 160;
            lightBackgroundRGB[1] = 160;
            lightBackgroundRGB[2] = 160;
            whitePieceRGB[0] = 210;
            whitePieceRGB[1] = 210;
            whitePieceRGB[2] = 210;
            blackPieceRGB[0] = 40;
            blackPieceRGB[1] = 40;
            blackPieceRGB[2] = 40;
            hoverBackgroundRGB[0] = 255;
            hoverBackgroundRGB[1] = 255;
            hoverBackgroundRGB[2] = 153;
            hoverWhitePieceRGB[0] = 170;
            hoverWhitePieceRGB[1] = 170;
            hoverWhitePieceRGB[2] = 170;
            hoverBlackPieceRGB[0] = 10;
            hoverBlackPieceRGB[1] = 10;
            hoverBlackPieceRGB[2] = 10;
            attackRGB[0] = 200;
            attackRGB[1] = 90;
            attackRGB[2] = 75;
            break;
        case blue:
            darkBackgroundRGB[0] = 0;
            darkBackgroundRGB[1] = 51;
            darkBackgroundRGB[2] = 102;
            lightBackgroundRGB[0] = 170;
            lightBackgroundRGB[1] = 170;
            lightBackgroundRGB[2] = 160;
            whitePieceRGB[0] = 255;
            whitePieceRGB[1] = 255;
            whitePieceRGB[2] = 255;
            blackPieceRGB[0] = 0;
            blackPieceRGB[1] = 0;
            blackPieceRGB[2] = 0;
            hoverBackgroundRGB[0] = 0;
            hoverBackgroundRGB[1] = 210;
            hoverBackgroundRGB[2] = 234;
            hoverWhitePieceRGB[0] = 255;
            hoverWhitePieceRGB[1] = 255;
            hoverWhitePieceRGB[2] = 255;
            hoverBlackPieceRGB[0] = 10;
            hoverBlackPieceRGB[1] = 10;
            hoverBlackPieceRGB[2] = 10;
            attackRGB[0] = 255;
            attackRGB[1] = 55;
            attackRGB[2] = 50;
            break;
        default:
            break;
    }
}

QString Theme::buildString(int rgb[3])
{
    return QString("rgb(") + QString::number(rgb[0]) + QString(", ")
           + QString::number(rgb[1]) + QString(", ")
           + QString::number(rgb[2]) + QString(");");
}

void Theme::setCustomTheme(int colors[8][3])
{
    for (int i = 0; i < 3; i++)
    {
        darkBackgroundRGB[i] = colors[0][i];
        lightBackgroundRGB[i] = colors[1][i];
        whitePieceRGB[i] = colors[2][i];
        blackPieceRGB[i] = colors[3][i];
        hoverBackgroundRGB[i] = colors[4][i];
        hoverWhitePieceRGB[i] = colors[5][i];
        hoverBlackPieceRGB[i] = colors[6][i];
        attackRGB[i] = colors[7][i];
    }
}
