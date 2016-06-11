#ifndef THEME_H
#define THEME_H

#include <QString>

class Theme
{
    int blackPieceRGB[3];
    int whitePieceRGB[3];
    int darkBackgroundRGB[3];
    int lightBackgroundRGB[3];
    int hoverWhitePieceRGB[3];
    int hoverBlackPieceRGB[3];
    int hoverBackgroundRGB[3];
    int attackRGB[3];

    static QString buildString(int [3]);

public:

    enum themes {slate, classic, light, blue, custom};

    void setTheme(themes);
    void setCustomTheme(int [8][3]);

    QString getBlackPieceColor() {return buildString(blackPieceRGB);}
    QString getWhitePieceColor() {return buildString(whitePieceRGB);}
    QString getDarkBackground() {return buildString(darkBackgroundRGB);}
    QString getLightBackground() {return buildString(lightBackgroundRGB);}
    QString getHoverColorWhite() {return buildString(hoverWhitePieceRGB);}
    QString getHoverColorBlack() {return buildString(hoverBlackPieceRGB);}
    QString getHoverBackground() {return buildString(hoverBackgroundRGB);}
    QString getAttackBackground() {return buildString(attackRGB);}

    friend class ThemeDialog;
};

#endif // THEME_H
