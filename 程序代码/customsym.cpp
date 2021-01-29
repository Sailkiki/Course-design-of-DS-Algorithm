#include "customsym.h"
#include "ui_customsym.h"

CustomSym::CustomSym(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomSym)
{
    ui->setupUi(this);
}

CustomSym::~CustomSym()
{
    delete ui;
}
