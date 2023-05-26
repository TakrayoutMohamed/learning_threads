#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>

int a;

void *roll_dice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    printf("hello from thread function\n");
    printf("the address of res is : %p\n",result);
    return (void *) result;
}

int main(void)
{
    int thread_return;
    int *res;
    pthread_t thread1;
    srand(time(NULL));
    thread_return = pthread_create(&thread1, NULL, &roll_dice, NULL);
    if (thread_return != 0)
        return (EXIT_FAILURE);
    thread_return = pthread_join(thread1, (void **) &res);
    if (thread_return != 0)
        return (EXIT_FAILURE);
    printf("Result: %d\n",*res);
    printf("the address of res is : %p\n",res);
    return (EXIT_SUCCESS);
}
