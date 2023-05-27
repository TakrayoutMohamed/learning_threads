#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/syscall.h>

void *routine(void* args)
{
    (void )args;
    pthread_t th = pthread_self();
    printf("%lu\n",(unsigned long)th);
    return (NULL);
}

int main(void)
{
    pthread_t   th[2];
    register int         i;

    i = 0;
    while (i < 2)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
        {
            perror("failed to create thread\n");
        }
        printf("the thread's %d  id = %lu \n", i,(unsigned long)th[i]);
        i++;
    }
    i = 0;
    while (i < 2)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("failed to join the thread");
        }
        i++;
    }


    return (0);
}
