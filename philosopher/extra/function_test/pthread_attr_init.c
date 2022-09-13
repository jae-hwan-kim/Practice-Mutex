#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_SUCCESS 0

static void *threadFunc(void *arg)
{
    char    *s = (char *) arg;
    
    printf("%s", s);
    return (void *) strlen(s);
}

int main(int ac, char **av)
{
    pthread_t       thr;
    pthread_attr_t  attr;
    int             s;

    s = pthread_attr_init(&attr);
    if (s != 0)
        exit(1);
    s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (s != 0)
        exit(1);
    s = pthread_create(&thr, &attr, threadFunc, "Hello world");
    if (s != 0)
        exit(1);
    s = pthread_attr_destroy(&attr);
    if (s != 0)
        exit(1);
   exit(EXIT_SUCCESS);
}