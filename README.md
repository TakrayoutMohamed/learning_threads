# threads
as learn journey
to compile the threads we use : cc (or gcc) -pthread

#  pthread_create       :
##    prototype : 
        int     pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
##    arguments:
        thread                   : a pointer to a pthread_t variable, which will be used to store <h4>the identifier of the new thread</h4>
        attr                     :
        (*start_routine)(void *) : a pointer to the function that will be executed by the new thread
        arg                      : a pointer to the argument that will be passed to the function.
##    return    :
        this function returns 0 on success and a non zero positive value depends on the error 
#  pthread_join         :
##    prototype :
        int     pthread_join(pthread_t thread, void **value_ptr);
##    arguments:
        thread                   : the identifier of the thread to wait for
        value_ptr                : it assigned the return value from the pthread_create function pointer (*start_routine)(void *)
        NOTE : 
        in the value pointer you will find it double pointer so we need to handle that casting to work from (*start_routine)(void *)'s return
##    return    :
        this function returns 0 on success and a non zero positive value depends on the error 
#  pthread_detach       :
##    prototype :
        int     pthread_detach(pthread_t thread);
##    arguments:
        thread                   : the identifier of the thread to detach
        NOTE :
        function is used to indicate to the implementation that storage for the thread thread can be reclaimed when the thread terminates.  If thread has not terminated,
     pthread_detach() will not cause it to terminate.  The effect of multiple pthread_detach() calls on the same target thread is unspecified.
##    return    :
        this function returns 0 on success and a non zero positive value depends on the error 
#  pthread_mutex_init   :
##    prototype :
        int     pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
##    arguments:
        mutex                    : identifies the mutex to be initialized
        attr                     : is a pointer to a pthread_mutexattr_t object that has previously been initialized to define the arguments for the mutex .If attr is specified as NULL, then the mutex is assigned various default attributes.
#  pthread_mutex_destroy:
##    prototype :
        int     pthread_mutex_destroy(pthread_mutex_t *mutex);
##    arguments:
#  pthread_mutex_lock   :
##    prototype :
        int     pthread_mutex_lock(pthread_mutex_t *mutex);
##    arguments:
#  pthread_mutex_unlock :
##    prototype :
        int     pthread_mutex_unlock(pthread_mutex_t *mutex);
##    arguments:
#  pthread_mutex_unlock :
##    prototype :
        pthread_t       pthread_self(void);
##    arguments:
