#ifndef GETTIME_H
#define GETTIME_H

#include<time.h>

//创建对象时开始计时，执行gettimes()计时结束
class gettime
{
public:
    gettime();
    double gettimes();

private:
    time_t start;
    time_t end;
    void timestart();
    void timeend();
};

#endif // GETTIME_H
