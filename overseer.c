#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv){

    #pragma omp parallel num_threads(5)
    {
        while(1){
            if(haswork){

            }
            
        }
        // for(int i = 1; i<= 10; ++i){
        //     printf("I is: %d\n", i);
        //     int a =  omp_get_thread_num();
        //     printf("thread is: %d\n", a);
        //     sleep(1);
        // }
    }
    return 1;
}