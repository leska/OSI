#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define SIZE 100
#define ITER_NUM 100000000

volatile long long array[SIZE];

void quit(int exitCode, char* message) {
	printf("%s", message);
	exit(exitCode);
}

static void *thread_counter(void *args) {
	int id;
	id = (int)args;
	for(array[id]=0; array[id]<ITER_NUM; array[id]++);
	pthread_exit(NULL);
}
int main()
{
	cpu_set_t cpu0, cpu1;
	int dist;
	dist = strtol(argv[1], NULL, 10);
	CPU_ZERO(&cpu0);
	CPU_ZERO(&cpu1);
	CPU_SET(0, &cpu0);
	CPU_SET(1, &cpu1);

	{
		pthread_t thread1, thread2;
		if (pthread_create(&thread1, NULL, thread_counter, (void*)0)) 
			quit(12, "could not create thread");

		if (pthread_create(&thread2, NULL, thread_counter, (void*)dist)) 
			quit(22,"could not create thread");

		if (pthread_setaffinity_np(thread1, sizeof(cpu_set_t), &cpu0))		
			quit(13,"could not set affinity");

		if (pthread_setaffinity_np(thread2, sizeof(cpu_set_t), &cpu1))
			quit(23,"could not set affinity");

		if (pthread_join(thread1, NULL))
			quit(31,"could not join thread");

		if (pthread_join(thread2, NULL))
			quit(32,"could not join thread");
	}
	return 0;
}
