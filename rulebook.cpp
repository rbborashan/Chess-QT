#include "rulebook.h"
#include "ui_rulebook.h"

RuleBook::RuleBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RuleBook)
{
    ui->setupUi(this);
}

RuleBook::~RuleBook()
{
    delete ui;
}
