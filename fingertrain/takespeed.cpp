#include "takespeed.h"

void takespeed::chadd()
{
    chsum++;
}

void takespeed::start()
{
    time=new gettime();
}

void takespeed::end()
{
    timesum=time->gettimes();
}

double takespeed::getspeed()
{
    return chsum/(1.0*timesum/60);
}
