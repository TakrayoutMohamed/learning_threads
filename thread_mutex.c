#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*
*   we tried to run the incrementation of global variable "glob"
*   so we expected to find that the value of the glob variable is 
*   double that number of incrementation twice
*   glob = 2 x number of incrementations 
*   but it gives as every time some other result rather than expected 
*   one
*   that is what calls data race 
*/
int glob = 0;

void *routine(void *args)
{
    int i;

    (void) args;
    i = 0;
    pthread_mutex_lock(args);
    while (i++ < 1000)
    {
        glob++;
        // i++;
    }
    pthread_mutex_unlock(args);
    return (NULL);
}

void *routine1(void *args)
{
    int i;

    (void) args;
    i = 0;
    pthread_mutex_lock(args);
    while (i++ < 1000)
    {
        glob++;
    }
    pthread_mutex_unlock(args);
    return (NULL);
}

int main(void)
{
    pthread_t   th[2];
    register int         i;
    pthread_mutex_t lock;

    i = 0;
    printf("the size of pthread_mutex_t = %lu\n", sizeof(pthread_mutex_t));
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("cant create the mutex");
    }

    if (pthread_create(&th[0], NULL, &routine, &lock) != 0)
    {
        perror("cant create the thread");
    }
    if (pthread_create(&th[1], NULL, &routine1, &lock) != 0)
    {
        perror("cant create the thread");
    }

    if (pthread_join(th[0], NULL) != 0)
    {
        perror("can not join the thread");
    }
    if (pthread_join(th[1], NULL) != 0)
    {
        perror("can not join the thread22");
    }
    pthread_detach(th[0]);
    pthread_detach(th[1]);
    if (pthread_mutex_destroy(&lock))
    {
        perror("cant destroy the mutex");
    }
    printf("the glob variable value is : %d\n",glob);

    return (0);
}