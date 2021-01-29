#include "pro1.h"
#include "ui_pro1.h"

Pro1::Pro1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pro1)
{
    ui->setupUi(this);
}

Pro1::~Pro1()
{
    delete ui;
}
