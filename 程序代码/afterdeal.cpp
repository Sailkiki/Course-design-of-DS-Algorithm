#include "afterdeal.h"
#include "ui_afterdeal.h"
#include <QDebug>
#include "pro1.h"
#include "ui_pro1.h"
#include "widget.h"
#include "ui_widget.h"
#include "pro2.h"
#include "ui_pro2.h"
AfterDeal::AfterDeal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfterDeal)
{
    ui->setupUi(this);
}

AfterDeal::~AfterDeal()
{
    delete ui;
}


void AfterDeal::on_Pro1Button_clicked(bool checked)
{
    pro1.exec();
}

void AfterDeal::on_Pro2Button_clicked(bool checked)
{
    pro2.exec();
}
