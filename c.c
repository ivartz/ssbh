#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <pthread.h>
#include <semaphore.h>
#define   MAX_COUNT  200



// gcc -o c c.c -pthread

sem_t sem;


void *thread_i(void *data){
  sem_wait(&sem);
  int num = (int) data;
  printf("Thread number: %d\n", num);
  usleep(5000000);
  sem_post(&sem);

  return 0;
}



int main(){

    sem_init(&sem, 0, 3);
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;


      pthread_t thread_1;
      pthread_t thread_2;
      pthread_t thread_3;
      pthread_t thread_4;
      pthread_t thread_5;

      pthread_create(&thread_1, NULL, thread_i, (void*) a);
      pthread_create(&thread_2, NULL, thread_i, (void*) b);
      pthread_create(&thread_3, NULL, thread_i, (void*) c);
      pthread_create(&thread_4, NULL, thread_i, (void*) d);
      pthread_create(&thread_5, NULL, thread_i, (void*) e);
   
      pthread_join(thread_1, NULL);
      pthread_join(thread_2, NULL);
      pthread_join(thread_3, NULL);
      pthread_join(thread_4, NULL);
      pthread_join(thread_5, NULL);
    
     
      return 0;
}