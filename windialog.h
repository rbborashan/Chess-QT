#ifndef WINDIALOG_H
#define WINDIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class WinDialog;
}

class WinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinDialog(QWidget *parent = 0);
    void showBlack();
    void showWhite();
    ~WinDialog();

private:
    Ui::WinDialog *ui;
};

#endif // WINDIALOG_H
