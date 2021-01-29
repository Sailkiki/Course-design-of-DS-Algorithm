#include "dialogofcppsym.h"
#include "ui_dialogofcppsym.h"

DialogOfcppsym::DialogOfcppsym(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOfcppsym)
{
    ui->setupUi(this);
}

DialogOfcppsym::~DialogOfcppsym()
{
    delete ui;
}
