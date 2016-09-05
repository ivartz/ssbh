#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <pthread.h>
#define   MAX_COUNT  200



// gcc -o d d.c -pthread

int var1,var2,running;
pthread_mutex_t lock;


static void  *thread_1()
{
     while(running){
      pthread_mutex_lock(&lock);
      var1++;
      var2=var1;
      pthread_mutex_unlock(&lock);
     }
     pthread_exit(NULL);
}

static void  *thread_2()
{
  int i;
     for (i = 1; i <= 20; i++){
          pthread_mutex_lock(&lock);
          printf("Number 1 is %i", var1);
          printf(", number 2 is %i \n", var2);
          usleep(100000);
          pthread_mutex_unlock(&lock);
          usleep(1000000);
     }
     running=0;
     pthread_exit(NULL);
}



int main(){
  var1=0;
  var2=0;
  running=1;

    pthread_mutex_init(&lock, NULL);

    pthread_t first_thread;
    pthread_t second_thread;

    pthread_create(&first_thread, NULL, thread_1, NULL);
    pthread_create(&second_thread, NULL, thread_2, NULL);

    pthread_join(first_thread, NULL);
    pthread_join(second_thread, NULL);

    pthread_mutex_destroy(&lock);
}