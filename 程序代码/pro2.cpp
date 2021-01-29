#include "pro2.h"
#include "ui_pro2.h"

Pro2::Pro2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pro2)
{
    ui->setupUi(this);
}

Pro2::~Pro2()
{
    delete ui;
}
