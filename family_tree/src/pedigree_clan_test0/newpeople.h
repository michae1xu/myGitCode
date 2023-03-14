#ifndef NEWPEOPLE_H
#define NEWPEOPLE_H

#include <QDialog>

namespace Ui {
class NewPeople;
}

class NewPeople : public QDialog
{
    Q_OBJECT

public:
    explicit NewPeople(QWidget *parent = nullptr);
    ~NewPeople();

private:
    Ui::NewPeople *ui;
};

#endif // NEWPEOPLE_H
