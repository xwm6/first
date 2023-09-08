#include "gettime.h"

//返回时间差（秒）
double gettime::gettimes(){
    timeend();
    return difftime(end,start);
}

void gettime::timeend(){
    time(&end);
}

void gettime::timestart(){
    time(&start);
}

gettime::gettime()
{
    timestart();
}
