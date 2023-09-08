#include "trans.h"
#include "ui_trans.h"
#include<QTime>
#include <qDebug>
#include <QTimer>
#include "windows.h"

trans::trans(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trans)
{
    ui->setupUi(this);
}

trans::~trans()
{
    delete ui;
}

void trans::on_pushButton_clicked()
{
    bewrite(getla(e));
    trans::getRandomChar();
    bered(getla(e));
}

void trans::bewrite(QLabel *bt)
{
    bt->setStyleSheet("background-color:white");
}

void trans::bered(QLabel *bt)
{
    bt->setStyleSheet("background-color:red");
}

QLabel* trans::getla(QString e)
{
    int len=findChildren<QLabel *>().length();
    for (int i = 0; i<len; i++)
    {
        QLabel *bt = (QLabel *)(this->children().at(i));
        if(bt->text()==e)
            return bt;
    }
}

void trans::getRandomChar(){
    LARGE_INTEGER seed;
    QueryPerformanceFrequency(&seed);
    QueryPerformanceCounter(&seed);
    srand(seed.QuadPart);
    char CHAR='A'+rand()%26;
    e=(QString) CHAR;
}

//void trans::InitCountMessage()
//{
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(slotCountMessage())); // slotCountMessage是我们需要执行的响应函数
//    timer->start(1000); // 每隔1s
//}

//void trans::slotCountMessage()
//{
//        //获得控件的个数
//        int len=this->children().length();
//        //访问每一个按钮
//        for (int i = 0; i<len; i++)
//        {
//            QLabel *bt = (QLabel *)(this->children().at(i));
//            if(bt->text()=="J")
//                bt->setStyleSheet("background-color:red");
//        }
//}
