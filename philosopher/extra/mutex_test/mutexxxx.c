#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t *mutex_lock;

void *add_test()
{
    long    *a;

    a = (long *)malloc(sizeof(long));    
    *a = 0;
    mutex_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex_lock, NULL);
    for (int i = 0; i < 10000; i++)
    {
        pthread_mutex_lock(mutex_lock);
        *a = *a + 1;
        pthread_mutex_unlock(mutex_lock);
    }
    printf("a = %ld\n", *a);
    return ((void *)*a);
}

int main(void)
{
    pthread_t   t1;
    pthread_t   t2;
    long        ret1 = 0;
    long        ret2 = 0;

    pthread_create(&t1, NULL, add_test, NULL);
    pthread_create(&t2, NULL, add_test, NULL);
    pthread_join(t1, (void *)&ret1);
    pthread_join(t2, (void *)&ret2);
    printf("ret1 = %ld\n", ret1);
    printf("ret2 = %ld\n", ret2);
    return (0);
}