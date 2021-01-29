#include "dialogofwarn.h"
#include "ui_dialogofwarn.h"

DialogOfWarn::DialogOfWarn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOfWarn)
{
    ui->setupUi(this);
}

DialogOfWarn::~DialogOfWarn()
{
    delete ui;
}
