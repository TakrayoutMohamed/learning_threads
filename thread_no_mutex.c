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
    while (i++ < 10000)
    {
        glob++;
        // i++;
    }
    return (NULL);
}

void *routine1(void *args)
{
    int i;

    (void) args;
    i = 0;
    while (i++ < 10000)
    {
        glob++;
        // i++;
    }
    return (NULL);
}

int main(void)
{
    pthread_t   th[2];
    register int         i;

    i = 0;
    // while (i < 2)
    {
        if (pthread_create(&th[0], NULL, &routine, NULL) != 0)
        {
            perror("cant create the thread");
        }
        i++;
        if (pthread_create(&th[1], NULL, &routine1, NULL) != 0)
        {
            perror("cant create the thread");
        }
        i = 0;
        // while (i < 100)
        {
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
            i++;
        }
    }
    printf("the glob variable value is : %d\n",glob);

    return (0);
}