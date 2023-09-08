#include "operationsql.h"

operationsql::operationsql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("fingering template");
    db.setUserName("root");
    db.setPassword("123456");
    db.open();//连接数据库
    db.exec("SET NAMES 'GBK'");
    query=QSqlQuery(db);
}

void operationsql::settype(QString type1)
{
    if(type1=="中文")
        type="chinesetext";
    else if(type1=="英文")
        type="englishtext";
}

bool operationsql::add(QString title, QString text, int diff)
{
    QString strCmd = QString("insert into %1 values(null,'%2','%3',%4)")
            .arg(type)
            .arg(title)
            .arg(text)
            .arg(diff);
    if(query.exec(strCmd))
        return true;
    else
        return false;
}

bool operationsql::remove(QString title)
{
    QString str = QString("DELETE FROM chinesetext WHERE title='%1'").arg(title);
    if(query.exec(str))
        return true;
    else
        return false;
}

QSqlQuery operationsql::gettitle(int diff)
{
    QString str = QString("select title from %1 where diff=%2").arg(type).arg(diff);
    query.exec(str);
    return query;
}

QSqlQuery operationsql::gettext(QString title)
{
    QString str = QString("select text from %1 where title='%2'").arg(type).arg(title);
    query.exec(str);
    return query;
}
