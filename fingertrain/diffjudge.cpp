#include "diffjudge.h"
//#include <qDebug>

diffjudge::diffjudge(QString a, bool b)
{
    text=a;type=b;
    textlist = text.split(QRegExp("\\W"));
}

void diffjudge::sum(){
    wordssum=textlist.size();
}

void diffjudge::takewordmv(){
    wordmv=text.size()/wordssum;
}

void diffjudge::longwordsum(){
    for(int i=0;i<textlist.size();i++){
        if(textlist.at(i).length()>7)
            longword++;
     }
     longword++;
}

//返回难度指标；1.文章总长度；2.长单词（句子）占比；3.单词（句子）平均长度
int diffjudge::getdiff(){
    if(!wordssum&&!wordmv&&!longword){
        sum();longwordsum();takewordmv();
    }
//    qDebug()<<wordssum;
//    qDebug()<<1.0*longword/wordssum;
//    qDebug()<<wordmv;
    if(type==true){//中文文本难度判定
        if(text.size()>70&&(longword/wordssum>0.5||wordmv>8))
            return 3;
        else if(text.size()<40&&longword/wordssum<0.3&&wordmv<6)
            return 1;
        else
            return 2;
    }
    else{//英文文本难度判定
        if(text.size()>300&&(longword/textlist.size()>0.1||wordmv>5))
            return 3;
        else if(text.size()<100&&(longword/textlist.size()<0.06||wordmv<4))
            return 1;
        else
            return 2;
    }
}
