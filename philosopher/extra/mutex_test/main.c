#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1

typedef enum condition
{
    HUNGRY,
    EATING,
    THINKING,
}   condition;

void    pickup(int i)
{
    phtread_mutex_lock(&mutex_lock);

    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING)
    {
        // pthread_cond_wait(&cond_vars[i], &mutex_lock);
    }
    pthread_mutex_unlock(&mutex_lock);
}

void putdown(int i)
{
    pthread_mutex_lock(&mutex_lock);

    state[i] = THINKING;
    test(leftOf(i));
    test(rightOf(i));

    pthread_mutex_unlock(&mutex_lock);
}

void test(int i, char *state, char **av)
{
    if (state[i] == HUNGRY && state[leftOf(i, av)] != EATING
    && state[rightOf(i, av)] != EATING)
    {
        state[i] = EATING;
        //pthread_cond_signal(&cond_vars[i]); 먹고 있는거 알림
    }
}

// monitor DiningPhilosophers
// {
//     void    pickup(int i)
//     {
//         state[i] = HUNGRY;
//         test(i);
//         if (state[i] != EATING)
//             self[i].wait();
//     }
//     void    putdown(int i)
//     {
//         state[i] = THINKING;
//         test((i + 4) % 5);
//         test((i + 1) % 5);
//     }
//     void    test(int i)
//     {
//         if ((state[(i + 4) % 5] != EATING)
//         && (state[i] == HUNGRY) && (state[(i + 1) % 5] != EATING))
//         {
//             state[i] = EATING;
//             // self[i].signal();
//         }
//     }
//     initialization_code() {
//         for (int i = 0; i < 5; i++)
//             state[i] = THINKING;
//     }
// }

void    think(int id)
{
    printf("%d: Now, I'm thinking...\n", id);
    usleep((1 + rand() % 50) * 10000); //자는 시간
}

void    eat(int id)
{
    printf("%d: Now, I'm eating...\n", id);
    usleep((1 + rand() % 50) * 10000); //먹는 시간
}

void    *philosopher(void *param)
{
    int id = *((int *)param);
    while (TRUE) {
        think(id);
        pickup(id);
        eat(id);
        putdown(id);
    }
}

int leftOf(int i, char **av)
{
    return ((i + atoi(av[1] - 1) % atoi(av[1])));
}

int rightOf(int i, char **av)
{
    return ((i + 1) % atoi(av[1]));
}

void    init(char **av, char *state, char **mutex_lock)
{
    int i;
    for (i = 0; i < atoi(av[1]); i++)
    {
        state[i] = THINKING;
    }
    pthread_mutex_init(mutex_lock, NULL);
    // srand(time(0)); 랜덤함수에 대한...!
}

int main(int ac, char **av)
{
    int i;
    pthread_t tid;
    pthread_mutex_t *mutex_lock;   
    condition *state;

    //필로소퍼 숫자만큼 malloc 하고 state 초기화
    init(av, state, &mutex_lock);
    for (i = 0; i < atoi(av[1]); i++)
        pthread_create(&tid, NULL, philosopher, (void *)&i);
    for (i = 0; i < atoi(av[1]); i++)
        pthread_join(tid, NULL);
    return (0);
}