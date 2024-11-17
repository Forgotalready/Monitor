#include <pthread.h>
#include <stdio.h>
#include <atomic>

struct Monitor
{
    std::atomic<int> signal_sent;
    pthread_mutex_t mutex;
    pthread_cond_t condvar;

    Monitor();

    void send();
    void consume();
};