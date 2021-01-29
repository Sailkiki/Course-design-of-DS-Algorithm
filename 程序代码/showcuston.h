#ifndef SHOWCUSTON_H
#define SHOWCUSTON_H

#include <QDialog>

namespace Ui {
class ShowCuston;
}

class ShowCuston : public QDialog
{
    Q_OBJECT

public:
    explicit ShowCuston(QWidget *parent = nullptr);
    ~ShowCuston();

public:
    Ui::ShowCuston *ui;
};

#endif // SHOWCUSTON_H
