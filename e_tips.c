#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t fork1;
pthread_mutex_t fork2;
pthread_mutex_t fork3;
pthread_mutex_t fork4;
pthread_mutex_t fork5;


pthread_mutex_t waiter;




void* Sokrates(){
    while(1){

        printf("Sokrates is thinking\n");
        //usleep(5);                        // think
        
        
        pthread_mutex_lock(&waiter);
        pthread_mutex_lock(&fork1);
        pthread_mutex_lock(&fork2);
        pthread_mutex_unlock(&waiter);


        printf("Sokrates is eating\n");
        sleep(5);                        // eat
        pthread_mutex_unlock(&fork1);
        pthread_mutex_unlock(&fork2);
        
    }
}
void* Aristoteles(){
    while(1){

        printf("Aristoteles is thinking\n");
        //usleep(5);                        // think

        pthread_mutex_lock(&waiter);
        pthread_mutex_lock(&fork2);
        pthread_mutex_lock(&fork3);
        pthread_mutex_unlock(&waiter);   


        printf("Aristoteles is eating\n");
        sleep(5);                        // eat
        pthread_mutex_unlock(&fork2);
        pthread_mutex_unlock(&fork3);
        
        
    }
}

void* Kant(){
    while(1){

        printf("Kant is thinking\n");
        //usleep(5);                        // think
        
        pthread_mutex_lock(&waiter);
        pthread_mutex_lock(&fork3);
        pthread_mutex_lock(&fork4);
        pthread_mutex_unlock(&waiter);  

        printf("Kant is eating\n");
        sleep(5);                        // eat
        pthread_mutex_unlock(&fork3);  
        pthread_mutex_unlock(&fork4);  
        
        
    }
}

void* Platon(){
    while(1){

        printf("Platon is thinking\n");
        //usleep(5);                        // think
        

        pthread_mutex_lock(&waiter);
        pthread_mutex_lock(&fork4);
        pthread_mutex_lock(&fork5);
        pthread_mutex_unlock(&waiter);   

        
        printf("Platon is eating\n");
        sleep(5);                        // eat
        pthread_mutex_unlock(&fork4);   
        pthread_mutex_unlock(&fork5);   
        
        
    }
}

void* Marx(){
    while(1){

        printf("Marx is thinking\n");
        //usleep(5);                        // think
        
        pthread_mutex_lock(&waiter);
        pthread_mutex_lock(&fork5);
        pthread_mutex_lock(&fork1);
        pthread_mutex_unlock(&waiter);

    
        printf("Marx is eating\n");
        //usleep(5);                        // eat
        pthread_mutex_unlock(&fork5);
        pthread_mutex_unlock(&fork1);
        
        
    }
}


int main (){
    pthread_t sokra[5]
    

    pthread_mutex_init(&fork1, NULL);
    pthread_mutex_init(&fork2, NULL);
    pthread_mutex_init(&fork3, NULL);
    pthread_mutex_init(&fork4, NULL);
    pthread_mutex_init(&fork5, NULL);
    pthread_mutex_init(&waiter, NULL);

    for int i = 0;i<5;i++{
        pthread_create(sokra+i, NULL, Sokrates, NULL);  

    }
    pthread_create(&sokra, NULL, Sokrates, NULL);
    pthread_create(&ari, NULL, Aristoteles, NULL);
    pthread_create(&pla, NULL, Platon, NULL);
    pthread_create(&ka, NULL, Kant, NULL);
    pthread_create(&ma, NULL, Marx, NULL);


    pthread_join(ari, NULL);
    pthread_join(ka, NULL);
    pthread_join(pla, NULL);
    pthread_join(ma, NULL);

    pthread_mutex_destroy(&fork1);
    pthread_mutex_destroy(&fork2);
    pthread_mutex_destroy(&fork3);
    pthread_mutex_destroy(&fork4);
    pthread_mutex_destroy(&fork5);
    pthread_mutex_destroy(&waiter);


    return 0;
}