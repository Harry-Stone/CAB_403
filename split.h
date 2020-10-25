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


char *splits(char* buff[]){
    int i = 0;
    char delim[] = " ";
    char *ptr = strtok(buff, delim);
    char *split = malloc(20);
    while (ptr != NULL)
    {
        split[i++] = ptr;
        ptr = strtok(NULL, delim);
    }
    return split;
}