/*
*  Materials downloaded from the web.
*  Collected and modified for teaching purpose only.
*/

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
#include "find_file.h"
#include "log.h"

#define BACKLOG 10 /* how many pending connections queue will hold */

#define MAXDATASIZE 50 /* max number of bytes we can get at once */

void excFile(char *in, char arg[])
{
    if(access(in, F_OK) != -1)
    {
        printf("%s attempting to execute %s\n", getDate(), in);
        char* path = realpath(in, NULL);
        if(execl(path, path, arg, NULL) == -1){
            perror("exec: ");
            exit(1);
        }
    }   else 
    {
        printf("%s doesnt exist\n", in);
    }
}

int main(int argc, char *argv[])
{
    int sockfd, new_fd, numbytes, pid, ang, kid_pid;            /* listen on sock_fd, new connection on new_fd */
    struct sockaddr_in my_addr;    /* my address information */
    struct sockaddr_in their_addr; /* connector's address information */
    uint16_t statistics;
    char reply[MAXDATASIZE];
    char reply2[MAXDATASIZE+1];
    int number_of_bytes;
    socklen_t sin_size;

    char *split[10];
    /* generate the socket */
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    if(argc != 2){
        fprintf(stderr, "usage: <port number>\n");
        exit(1);
    }
    int myport = atoi(argv[1]);
    /* Enable address/port reuse, useful for server development */
    int opt_enable = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt_enable, sizeof(opt_enable));
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt_enable, sizeof(opt_enable));

    /* clear address struct */
    memset(&my_addr, 0, sizeof(my_addr));

    /* generate the end point */
    my_addr.sin_family = AF_INET;         /* host byte order */
    my_addr.sin_port = htons(myport);     /* short, network byte order */
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* auto-fill with my IP */

    /* bind the socket to the end point */
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("bind");
        exit(1);
    }

    /* start listnening */
    if (listen(sockfd, BACKLOG) == -1)
    {
        perror("listen");
        exit(1);
    }
    
    printf("%s server starts listening ...\n", getDate());

    /* repeat: accept, send, close the connection */
    /* for every accepted connection, use a sepetate process or thread to serve it */
    while (1)
    { /* main accept() loop */
        sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,
                             &sin_size)) == -1)
        {
            perror("accept");
            continue;
        }
        printf("%s server: got connection from %s\n", getDate(), inet_ntoa(their_addr.sin_addr));
        char *name = "num";
        int recieve = 1;
        
        for(int i = 3; i < 15; i++){
            char buf[MAXDATASIZE];
            if ((number_of_bytes = recv(new_fd, buf, MAXDATASIZE, 0)) == -1)
                {
                    perror("recv");
                    exit(1);
                }
                buf[number_of_bytes]='\0';
                printf("%s Received: %s\n", getDate(), buf);
                //strcat(reply, buf);
                //strcat(reply, " ");
        }

        char* c_reply = strdup(reply);

        /*int size_of = 0;
        /*for(int i = 0; i < strlen(c_reply); i++){
            if(c_reply[i] == ' '){
                size_of++;
            }
        }

        /*char** s_reply = calloc(size_of, sizeof(char*));

        /*char* token = strtok(c_reply, " ");

        int o = 0;
        while(token != NULL){
            s_reply[o] = calloc(strlen(token)+1, sizeof(char));
            strcpy(s_reply[o], token);
            o++;
            token = strtok(NULL, " ");
        }

        s_reply[size_of] = NULL;*/
        printf("%s Received: %s\n", getDate(), reply);
        pid_t process;
        process = fork();
        if(process==0){

            /*int i = 0;
            char* rest = reply;
            char delim[] = " ";
            char *ptr = strtok(rest, " ");
            char *split[100];
            while (ptr != NULL)
            {
                split[i++] = ptr;
                ptr = strtok(NULL, delim);
            }*/

            /*kid_pid = getpid();
            excFile(split[0], *split);*/
            
        }
        else{
            wait(NULL);
            printf("%s - %s %s has been excevuted with pid %d\n", getDate(), split[0], split[1], kid_pid);
        }
        close(new_fd); /* parent doesn't need this */

        while (waitpid(-1, NULL, WNOHANG) > 0)
            ; /* clean up child processes */
    }
}
