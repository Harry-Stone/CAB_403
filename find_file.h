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
    printf("%s\n", in[0]);
    int i = 0;
    while(strcmp(in[i], "-o") == 0||strcmp(in[i], "-log")==0||strcmp(in[i], "-t")==0){
        i +=2;
        printf("%s inside the boi\n",in[i]);
    }
    return i;
}