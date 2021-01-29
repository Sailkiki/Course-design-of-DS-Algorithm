#ifndef PRO1_H
#define PRO1_H

#include <QDialog>

namespace Ui {
class Pro1;
}

class Pro1 : public QDialog
{
    Q_OBJECT

public:
    explicit Pro1(QWidget *parent = nullptr);
    ~Pro1();

public:
    Ui::Pro1 *ui;
};

#endif // PRO1_H
