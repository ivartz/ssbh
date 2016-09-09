#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int gloabVar;

void  main(void)
{

     gloabVar = 1;

     pid_t  pid;

     pid = vfork();
    
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++){
          printf("This line is from child, value = %d\n", i);
          printf("This line is from child, global value = %d\n", gloabVar);
          gloabVar++;
     }
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++){
          printf("                    This line is from parent, value = %d\n", i);
          printf("                    This line is from parent, global value = %d\n", gloabVar);
          gloabVar++;
     }
     printf("*** Parent is done ***\n");
}