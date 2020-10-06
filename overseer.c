#include <stdio.h>
//#include <omp.h>
#include <pthread.h>

#define NUM_THREADS 20

void* work(void* arg)
{
    printf("hello world\n");
}


int main(){
    //#pragma omp parallel num_threads(NUM_THREADS)
    //{
        pthread_t pool[NUM_THREADS];

        for(int i = 0;i  < NUM_THREADS;i++){
            pthread_create(pool + i, NULL, work, NULL);
        }
        
        //int a =  omp_get_thread_num();
        /*#pragma omp parallel for
        printf("Hello world 2\n");
        #pragma omp parallel for
        printf("Hello world 3\n");
        #pragma omp parallel for
        printf("Hello world 4\n");
        #pragma omp parallel for
        printf("Hello world 5\n");*/
        
        /*printf("thread is: %d\n", a);
        for(int i = 1; i<= 10; ++i){
            printf("I is: %d\n", i);
            
        }*/
    //}
    return 1;
}