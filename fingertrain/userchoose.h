#ifndef USERCHOOSE_H
#define USERCHOOSE_H

#include <QWidget>

namespace Ui {
class userchoose;
}

class userchoose : public QWidget
{
    Q_OBJECT

public:
    explicit userchoose(QWidget *parent = nullptr);
    ~userchoose();

private:
    Ui::userchoose *ui;
};

#endif // USERCHOOSE_H
