#include "showcuston.h"
#include "ui_showcuston.h"

ShowCuston::ShowCuston(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowCuston)
{
    ui->setupUi(this);
}

ShowCuston::~ShowCuston()
{
    delete ui;
}
