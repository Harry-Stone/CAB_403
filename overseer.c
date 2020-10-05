#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv){
    //#pragma omp parallel num_threads(5)
    {
        #pragma omp parallel 
        printf("112");
        //int a =  omp_get_thread_num();
        //#pragma omp parallel for
        for( int i = 0; i < 5; i++){
            i = i*i;
            printf("Hello world 1 = %d\n", i);
        }

        //#pragma omp parallel for
        for(int j = 0; j <10; j++){
            j = j*2*j;
            printf("Hello world 2 = %d\n", j);
        }
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
    }
    return 1;
}