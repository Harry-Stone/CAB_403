#include <stdio.h>
#include <pthread.h>
#include <omp.h>

#define NUM_THREADS 5

void* work(void* arg){
    printf("Hello world: %d\n", * (int*) arg);
}

int main(){
    pthread_t pool[NUM_THREADS];

    int arguments[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS;i++){
        arguments[i] = i;
    }

    for(int i = 0; i< NUM_THREADS;i++){
        pthread_create(pool+i,NULL,work,arguments + i);
    }

    for(int i = 0; i< NUM_THREADS;i++){
        pthread_join(*(pool+i),NULL);
    }
}