#ifndef THEMEDIALOG_H
#define THEMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QString>
#include "theme.h"

namespace Ui {
class ThemeDialog;
}

class ThemeDialog : public QDialog
{
    Q_OBJECT

    int redValue;
    int greenValue;
    int blueValue;
    int RGBArgs[8][3];
    QLabel preview;

public:

    explicit ThemeDialog(QWidget* parent = 0);
    static void enableBoard();
    void saveTheme();
    ~ThemeDialog();

private slots:
    void on_applyButton_clicked();
    void updateRed(int);
    void updateGreen(int);
    void updateBlue(int);
    void updateColors();
    void on_cancelButton_clicked();

private:
    Ui::ThemeDialog *ui;
    QString getRGBString();
};

#endif // THEMEDIALOG_H
