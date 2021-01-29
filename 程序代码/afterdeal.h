#ifndef AFTERDEAL_H
#define AFTERDEAL_H

#include <QDialog>
#include "pro1.h"
#include "ui_pro1.h"
#include "pro2.h"
#include "ui_pro2.h"
//#include "widget.h"
//#include "ui_widget.h"
namespace Ui {
class AfterDeal;
}

class AfterDeal : public QDialog
{

    Q_OBJECT

public:
    explicit AfterDeal(QWidget *parent = nullptr);
    ~AfterDeal();

public:
    Ui::AfterDeal *ui;
    Pro1 pro1;
    Pro2 pro2;
private slots:
    void on_Pro1Button_clicked(bool checked);
    void on_Pro2Button_clicked(bool checked);
};

#endif // AFTERDEAL_H
