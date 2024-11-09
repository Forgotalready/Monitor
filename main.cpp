#include "Monitor/Monitor.h"
#include <unistd.h>

void* routine(void* arg)
{
	Monitor* monitor = (Monitor*) arg;
	while(true)
	{
		monitor->send();
		sleep(5);
	}
}

void* coroutine(void* arg)
{
	Monitor* monitor = (Monitor*) arg;
	while(true)
	{
		monitor->consume();
		sleep(5);
	}
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;

	Monitor* monitor = new Monitor();

    pthread_create(&thread1, NULL, routine, monitor);
	pthread_create(&thread2, NULL, coroutine, monitor);

	pthread_exit(NULL);
	delete monitor;
}