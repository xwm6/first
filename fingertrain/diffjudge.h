#ifndef DIFFJUDGE_H
#define DIFFJUDGE_H

#include <QString>
#include <QStringList>

//英文文本word表示单词，中文表示以，。分割的句子

class diffjudge
{
public:
    diffjudge(QString a,bool b);
    int getdiff();
private:
    QString text;
    QStringList textlist;
    bool type;//中文为true，英文为false
    int wordssum=0;
    int wordmv=0;
    int longword=0;
    void sum();
    void takewordmv();
    void longwordsum();
};

#endif // DIFFJUDGE_H
