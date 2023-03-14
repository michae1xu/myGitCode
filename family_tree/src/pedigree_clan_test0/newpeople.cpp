#include "newpeople.h"
#include "ui_newpeople.h"

NewPeople::NewPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPeople)
{
    ui->setupUi(this);
}

NewPeople::~NewPeople()
{
    delete ui;
}
