#ifndef TRANS1_H
#define TRANS1_H

#include <QWidget>

namespace Ui {
class trans1;
}

class trans1 : public QWidget
{
    Q_OBJECT

public:
    explicit trans1(QWidget *parent = nullptr);
    ~trans1();

private:
    Ui::trans1 *ui;
};

#endif // TRANS1_H
