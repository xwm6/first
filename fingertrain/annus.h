#ifndef ANNUS_H
#define ANNUS_H

#include <QWidget>

namespace Ui {
class annus;
}

class annus : public QWidget
{
    Q_OBJECT

public:
    explicit annus(QWidget *parent = nullptr);
    ~annus();

private:
    Ui::annus *ui;
};

#endif // ANNUS_H
