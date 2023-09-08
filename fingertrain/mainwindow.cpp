#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "diffjudge.h"
#include <qDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString text=ui->textEdit_1->toPlainText();
    qDebug()<<text;
    diffjudge* q;
    q = new diffjudge(text,true);
    q->getdiff();
}
