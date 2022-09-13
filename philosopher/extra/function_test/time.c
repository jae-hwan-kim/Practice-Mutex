#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_usec - start->tv_usec);
}

void loopFunc(size_t num)
{
    int tmp = 0;
    for (int i = 0; i < num; ++i) {
        tmp += 1;
    }
}

int main(void)
{
    struct timeval start;
    struct timeval end;

    int num2 = 10000;
    gettimeofday(&start, NULL);
    sleep(5);
    gettimeofday(&end, NULL);

    printf("loopFunc(%d)\ntime spent: %d usec\n", num2, time_diff(&start, &end));

    return (0);
}