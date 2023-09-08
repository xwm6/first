#include "mainwindow.h"
#include <windows.h>
#include <QString>
#include <QApplication>
#include "takespeed.h"
#include <QTextCodec>
#include <iostream>
#include "diffjudge.h"
#include <qDebug>
#include "operationsql.h"
#include "userchoose.h"
#include <QList>
#include "trans.h"

using namespace std;

//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

int main(int argc, char *argv[])
{
//    operationsql* a = new operationsql("中文");
//    QSqlQuery query;
//    query=a->gettitle();
//    while(query.next()){
//        qDebug()<<query.value(0).toString();
//    }

//    a->remove("长江");
//    int i;
//    QList<char> letters;
//    for(i = 0;i < 26 ;i++)
//    {
//        letters << 'a' + i;
//    }
//    for(i = 0;i < 26 ;i++)
//    {
//        letters << 'A' + i;
//    }
//    for(i = 0;i < 10 ;i++)
//    {
//        letters << '0' + i;
//    }
//    for(int i=0;i<10;i++){
//    char dispLetters = letters[(qrand()%letters.count())];
//    qDebug()<<dispLetters;
//    }
//blog.csdn.net/k54387/article/details/77984650

//    for(int i=0;i<first.size();i++){
//         qDebug()<<first.at(i);
//    }

//    time_t start;
//    time_t end;
//    printf("%d\n",time(&start));
//    Sleep(1000);
//    printf("%d\n",time(&end));
//    printf("%lf\n",difftime(end,start));

    QApplication a(argc, argv);
    userchoose w;
//    QString e = "J";
//            int len=w.children().length();
//            //访问每一个按钮
//            for (int i = 0; i<len; i++)
//            {
//                QLabel *bt = (QLabel *)(w.children().at(i));
//                if(bt->text()==e)
//                    bt->setStyleSheet("background-color:red");
//            }
    w.show();
    return a.exec();
}
