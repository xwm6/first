#ifndef TAKESPEED_H
#define TAKESPEED_H

#include "gettime.h"

//获得打字速度，按分钟计时
class takespeed
{
public:
    void start();
    void end();
    double getspeed();
    void chadd();
private:
    double speed;
    double timesum;
    int chsum=0;
    gettime* time;
};

#endif // TAKESPEED_H
