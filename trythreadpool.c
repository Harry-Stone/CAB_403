#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10

void* work(void* arg){
    printf("Hello world\n");
}

int main(){
    pthread_t pool[NUM_THREADS];
    for(int i = 0; i< NUM_THREADS;i++){
        pthread_create(pool+i,NULL,work,NULL);
    }
}