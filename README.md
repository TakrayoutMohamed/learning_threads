# threads
as learn journey
to compile the threads we use : cc (or gcc) -pthread

## pthread_create
#     protetype : 
        int     pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
#     attributes:
        thread                   : a pointer to name of the threade going be created
        attr                     :
        (*start_routine)(void *) : poiter to return of function with the prototype "void *start_routine(void *);"
        arg                      :
## pthread_join
#     prototype :
        int     pthread_join(pthread_t thread, void **value_ptr);
#     attributes:
        thread                   : the name of the thread that was created by pthread_create()
        value_ptr                : it assigned the return value from the pthread_create function pointer (*start_routine)(void *)
      NOTE : 
        in the value pointer you will find it double pointer so we need to handle that casting to work from (*start_routine)(void *)'s return
## pthread_detach
#     protetype :
#     attributes:
## pthread_mutex_init
#     protetype :
#     attributes:
## pthread_mutex_destroy
#     protetype :
#     attributes:
## pthread_mutex_lock
#     protetype :
#     attributes:
## pthread_mutex_unlock
#     protetype :
#     attributes: