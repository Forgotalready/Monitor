#include "Monitor.h"

Monitor::Monitor()
{
    signal_sent = 0;
    pthread_mutex_init(&mutex, NULL);
    condvar = PTHREAD_COND_INITIALIZER;
}

void Monitor::send()
{
    pthread_mutex_lock(&mutex);

    puts("Sender send signal");
    signal_sent.store(1);
    pthread_cond_signal(&condvar);

    pthread_mutex_unlock(&mutex);
}

void Monitor::consume()
{
    pthread_mutex_lock(&mutex);
    
    while(!(signal_sent.load()))
    {
        pthread_cond_wait(&condvar, &mutex);
    }

    puts("Consumer recive signal");

    signal_sent.store(0);

    pthread_mutex_unlock(&mutex);
}
