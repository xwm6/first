#ifndef TRANS_H
#define TRANS_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include "trans1.h"
#include "ui_trans1.h"

namespace Ui {
class trans;
}

class trans : public QWidget
{
    Q_OBJECT

public:
    explicit trans(QWidget *parent = nullptr);
    QString e="J";
    ~trans();
private slots:
//    void on_pushButton_clicked();

void on_pushButton_clicked();

private:
    QLabel* getla(QString e);
    void bewrite(QLabel *bt);
    void bered(QLabel *bt);
    Ui::trans *ui;
    QLineEdit *LineEdit[3];
    void getRandomChar();
};

#endif // TRANS_H
