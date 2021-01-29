#ifndef DIALOGOFCPPSYM_H
#define DIALOGOFCPPSYM_H

#include <QDialog>

namespace Ui {
class DialogOfcppsym;
}

class DialogOfcppsym : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOfcppsym(QWidget *parent = nullptr);
    ~DialogOfcppsym();

public:
    Ui::DialogOfcppsym *ui;
};

#endif // DIALOGOFCPPSYM_H
