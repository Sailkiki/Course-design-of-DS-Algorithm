#ifndef CUSTOMSYM_H
#define CUSTOMSYM_H

#include <QDialog>

namespace Ui {
class CustomSym;
}

class CustomSym : public QDialog
{
    Q_OBJECT

public:
    explicit CustomSym(QWidget *parent = nullptr);
    ~CustomSym();

public:
    Ui::CustomSym *ui;
};

#endif // CUSTOMSYM_H
