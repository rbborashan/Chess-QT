#include "windialog.h"
#include "ui_windialog.h"

QLabel* winText;

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    winText = new QLabel(this);
}

void WinDialog::showBlack()
{
    winText->setText("Congratulations, black wins!");
    winText->show();
    show();
}

void WinDialog::showWhite()
{

}

WinDialog::~WinDialog()
{
    delete ui;
}
