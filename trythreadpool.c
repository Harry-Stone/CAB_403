#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>

#define NUM_THREADS 10
#define DATA_SIZE 100
#define BLOCK (DATA_SIZE/ NUM_THREADS)

//int parallel_sum = 0;

void* work(void* arg)
{
    printf("Hello world %d\n", arg);
}

int main(){
    pthread_t pool[NUM_THREADS];
    

    srand(50);

    int data[DATA_SIZE];

    for(int i = 0;i<DATA_SIZE;i++){
        data[i] = rand() % 100;
    }
    int arguments[NUM_THREADS];
    int sum = 0;
    for (int i  = 0; i < DATA_SIZE; i++){
        sum += data[i];
    }

    printf("sequential sum is %d\n",sum);

    for(int i = 0; i < NUM_THREADS ;i++){
        arguments[i] = i;
    }

    for(int i = 0; i< NUM_THREADS;i++){
        pthread_create(pool+i,NULL, work, arguments + i);
    }

    for(int i = 0; i< NUM_THREADS;i++){
        pthread_join(*(pool+i),NULL);
    }
}