#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int find_file(char *in[]){
    int i = 0;
    if(strcmp(in[i], "-o") == 0||strcmp(in[i], "-log")==0||strcmp(in[i], "-t")==0){
        i = 2;
        printf("%1s\n", in[i]);
        if(strcmp(in[i], "-o") == 0||strcmp(in[i], "-log")==0||strcmp(in[i], "-t")==0){
            i = 4;
            printf("2%s\n", in[i]);
            if(strcmp(in[i], "-o") == 0||strcmp(in[i], "-log")==0||strcmp(in[i], "-t")==0){
            i = 6;
            printf("3%s\n", in[i]);
        }
        }

    }
    return i;
}