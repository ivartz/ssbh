#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <pthread.h>

// gcc -o 3dd 3dd.c -lpthread -lrt

void busy_wait_delay(int seconds){
	int i, dummy;
	int tps = sysconf(_SC_CLK_TCK);
	clock_t start;
	struct tms exec_time;
	times(&exec_time);
	start = exec_time.tms_utime;
	while( (exec_time.tms_utime - start) < (seconds * tps))
	{
		for(i=0; i<1000; i++){
			dummy = i;
		}
		times(&exec_time);
	}
}

// gcc -o 3d 3d.c -lpthread

static void *thread_one(void *data)
{
	printf("Thread one started \n");

	busy_wait_delay(5);

	printf("Thread one still alive \n");

	pthread_exit(NULL);
}

static void *thread_two(void *data)
{
	printf("Thread two started \n");

	busy_wait_delay(5);
	
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

