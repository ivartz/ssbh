#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <pthread.h>
#define   MAX_COUNT  200

// gcc -o 3dd 3dd.c -pthread -lrt

// gcc -o b b.c -pthread

int gloabVar;

static void  *ChildProcess(void *data)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++){
          usleep(10);
          printf("This line is from child, value = %d\n", i);
          printf("This line is from child, global value = %d\n", gloabVar);
          gloabVar++;
     }
     printf("   *** Child process is done ***\n");
     pthread_exit(NULL);
}

static void  *ParentProcess(void*data)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++){
          printf("                    This line is from parent, value = %d\n", i);
          printf("                    This line is from parent, global value = %d\n", gloabVar);
          gloabVar++;
     }
     printf("*** Parent is done ***\n");
     pthread_exit(NULL);
}



int main(){

    gloabVar = 1;
    pthread_t child_process;
    void *data;
    pthread_create(&child_process, NULL, ChildProcess, (void*) data);

    pthread_t parent_process;
    pthread_create(&parent_process, NULL, ParentProcess, (void*) data);



    pthread_join(child_process, NULL);
    pthread_join(parent_process, NULL);
}