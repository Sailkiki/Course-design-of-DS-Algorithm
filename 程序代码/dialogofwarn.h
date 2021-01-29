#ifndef DIALOGOFWARN_H
#define DIALOGOFWARN_H

#include <QDialog>

namespace Ui {
class DialogOfWarn;
}

class DialogOfWarn : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOfWarn(QWidget *parent = nullptr);
    ~DialogOfWarn();

public:
    Ui::DialogOfWarn *ui;
};

#endif // DIALOGOFWARN_H
