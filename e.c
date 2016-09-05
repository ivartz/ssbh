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
    
        pthread_mutex_lock(&fork1);     // take left fork
        pthread_mutex_lock(&fork2);     // take right fork
        printf("Sokrates is eating\n");
        usleep(50);                        // eat
        pthread_mutex_unlock(&fork2);   // put right fork down
        pthread_mutex_unlock(&fork1);   // put left fork down
    }
}
void* Aristoteles(){
    while(1){

        printf("Aristoteles is thinking\n");
        pthread_mutex_lock(&fork2);
        pthread_mutex_lock(&fork3);     // take left fork
        // take right fork
        printf("Aristoteles is eating\n");
        usleep(50);                        // eat
        pthread_mutex_unlock(&fork2);   // put right fork down
        pthread_mutex_unlock(&fork3);   // put left fork down
    }
}

void* Kant(){
    while(1){

        printf("Kant is thinking\n");
        pthread_mutex_lock(&fork3);
        pthread_mutex_lock(&fork4);     // take left fork
        // take right fork
        printf("Kant is eating\n");
        usleep(50);                        // eat
        pthread_mutex_unlock(&fork3);   // put right fork down
        pthread_mutex_unlock(&fork4);   // put left fork down
    }
}

void* Platon(){
    while(1){

        printf("Platon is thinking\n");
        pthread_mutex_lock(&fork4);
        pthread_mutex_lock(&fork5);     // take left fork
        // take right fork
        printf("Platon is eating\n");
        usleep(50);                        // eat
        pthread_mutex_unlock(&fork4);   // put right fork down
        pthread_mutex_unlock(&fork5);   // put left fork down
    }
}

void* Marx(){
    while(1){

        printf("Marx is thinking\n");
        pthread_mutex_lock(&fork5);
        pthread_mutex_lock(&fork1);     // take left fork
        // take right fork
        printf("Marx is eating\n");
        usleep(50);                        // eat
        pthread_mutex_unlock(&fork5);   // put right fork down
        pthread_mutex_unlock(&fork1);   // put left fork down
    }
}






int main (){
    pthread_t sokra, ari, ka, pla, ma;
    pthread_mutex_init(&fork1, NULL);
    pthread_mutex_init(&fork2, NULL);
    pthread_mutex_init(&fork3, NULL);
    pthread_mutex_init(&fork4, NULL);
    pthread_mutex_init(&fork5, NULL);

    pthread_create(&sokra, NULL, Sokrates, NULL);
    pthread_create(&ari, NULL, Aristoteles, NULL);
    pthread_create(&pla, NULL, Platon, NULL);
    pthread_create(&ka, NULL, Kant, NULL);
    pthread_create(&ma, NULL, Marx, NULL);


    pthread_join(sokra, NULL);
    pthread_join(ari, NULL);
    pthread_join(ka, NULL);
    pthread_join(pla, NULL);
    pthread_join(ma, NULL);

    pthread_mutex_destroy(&fork1);
    pthread_mutex_destroy(&fork2);
    pthread_mutex_destroy(&fork3);
    pthread_mutex_destroy(&fork4);
    pthread_mutex_destroy(&fork5);

    return 0;
}