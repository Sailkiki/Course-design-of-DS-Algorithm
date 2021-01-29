#ifndef PRO2_H
#define PRO2_H

#include <QDialog>

namespace Ui {
class Pro2;
}

class Pro2 : public QDialog
{
    Q_OBJECT

public:
    explicit Pro2(QWidget *parent = nullptr);
    ~Pro2();

public:
    Ui::Pro2 *ui;
};

#endif // PRO2_H
