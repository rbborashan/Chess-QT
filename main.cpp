#include "chessboard.h"
#include "themedialog.h"
#include "aboutdialog.h"
#include "rulebook.h"
#include <QApplication>

ThemeDialog* themeEditor;
AboutDialog* about;
RuleBook* rules;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ChessBoard w;
    ThemeDialog td;
    AboutDialog ad;
    RuleBook rb;

    themeEditor = &td;
    about = &ad;
    rules = &rb;

    w.show();
    return a.exec();
}
