#ifndef OPERATIONSQL_H
#define OPERATIONSQL_H

#include <QString>
#include <QSqlQuery>

class operationsql
{
public:
    operationsql();
    bool add(QString title, QString text, int diff);
    bool remove(QString title);
    QSqlQuery gettitle(int diff);
    QSqlQuery gettext(QString title);
    void settype(QString type);
private:
    QSqlQuery query;
    QString type="null";
};

#endif // OPERATIONSQL_H
