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

char* split_arg(char str[])
{
    char *ptr = strtok(str, " ");
    char *out = malloc(strlen(str) * sizeof(char));
    if(out == NULL)
		return NULL;
    // char *out[100];
    int i = 0;

    while (ptr != NULL)
    {
        out[i++] = ptr;
        ptr = strtok(NULL," ");
    }

    return out;
}

int main(void){
    char str[] = "working perfectly because c is easy";
    char *final = split_arg(str);

    printf("%s\n",final);

    free(final);

}