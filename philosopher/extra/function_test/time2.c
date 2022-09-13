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
	struct timeval	current_time;
    int num = 10000;

    loopFunc(num);
	gettimeofday(&current_time, NULL);
    printf("%ld\n", (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	return (0);
}