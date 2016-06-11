#ifndef RULEBOOK_H
#define RULEBOOK_H

#include <QWidget>

namespace Ui {
class RuleBook;
}

class RuleBook : public QWidget
{
    Q_OBJECT

public:
    explicit RuleBook(QWidget *parent = 0);
    ~RuleBook();

private:
    Ui::RuleBook *ui;
};

#endif // RULEBOOK_H
