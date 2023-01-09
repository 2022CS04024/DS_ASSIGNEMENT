#include "common.h"
#include <stdio.h>


double time_diff(struct timeval x , struct timeval y)
{
    double x_ms , y_ms , diff;

    x_ms = (double)x.tv_sec + (double)x.tv_usec;
    y_ms = (double)y.tv_sec + (double)y.tv_usec;

    diff = (double)y_ms - (double)x_ms;
    printf("Elapsed time: %f microsecons\n", diff);

    return diff;
}

