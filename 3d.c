#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

// gcc -o 3d 3d.c -lpthread

static void *thread_one(void *data)
{
	printf("Thread one started \n");

	sleep(5);

	printf("Thread one still alive \n");

	pthread_exit(NULL);
}

static void *thread_two(void *data)
{
	printf("Thread two started \n");

	sleep(5);
	
	printf("Thread two still alive \n");

	pthread_exit(NULL);
}

int main(){

	pthread_t first_thread;
	void *data;
	pthread_create(&first_thread, NULL, thread_one, (void*) data);

	pthread_t second_thread;
	pthread_create(&second_thread, NULL, thread_two, (void*) data);



	pthread_join(first_thread, NULL);
	pthread_join(second_thread, NULL);
}

