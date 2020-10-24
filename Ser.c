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

#define BACKLOG 10 /* how many pending connections queue will hold */

#define MAXDATASIZE 10 /* max number of bytes we can get at once */


void Receive_Array_Int_Data(int socket_identifier, int size)
{
    int number_of_bytes, i = 0;
    char statistics;

    char *results = malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        if ((number_of_bytes = recv(socket_identifier, &statistics, sizeof(uint16_t), 0)) == -1)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        results[i] = ntohs(statistics);
    }
    for (i = 0; i < size; i++)
    {
        printf("Array[%d] = %d\n", i, results[i]);
    }
}

int main(int argc, char *argv[])
{
    int sockfd, new_fd, numbytes;            /* listen on sock_fd, new connection on new_fd */
    struct sockaddr_in my_addr;    /* my address information */
    struct sockaddr_in their_addr; /* connector's address information */
    uint16_t statistics;
    char buf[MAXDATASIZE];
    char buff[MAXDATASIZE];
    socklen_t sin_size;
    time_t t = time(NULL);
    struct tm tim = *localtime(&t);
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
    my_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */

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
    
    printf("%d-%02d-%02d %02d:%02d:%02d server starts listening ...\n", tim.tm_year + 1900, tim.tm_mon +1,tim.tm_mday, tim.tm_hour, tim.tm_min, tim.tm_sec);

    /* repeat: accept, send, close the connection */
    /* for every accepted connection, use a sepetate process or thread to serve it */
    while (1)
    { /* main accept() loop */
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,
                             &sin_size)) == -1)
        {
            perror("accept");
            continue;
        }
        printf("%d-%02d-%02d %02d:%02d:%02d server: got connection from %s\n",
               tm.tm_year + 1900, tm.tm_mon +1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, inet_ntoa(their_addr.sin_addr));
        if (!fork())
        { /* this is the child process */
            /*if (send(new_fd, "Hello, world!\n", 14, 0) == -1){
                perror("send");
            close(new_fd);
            exit(0);
            }*/
            //char *results = Receive_Array_Int_Data(new_fd, MAXDATASIZE);
            //printf("Yes\n");
            //for (int i = 0; i < sizeof(results); i++)
            //{
               // printf("Value of index = %s\n", results[1]);
            //}
            //free(results);
            if ((numbytes = recv(new_fd, &buf, MAXDATASIZE, 0)) == -1)
            {
                perror("recv");
                exit(1);
            }

            buf[numbytes] = '\0';
            printf("Received: %s\n", buf);
        }
        close(new_fd); /* parent doesn't need this */

        while (waitpid(-1, NULL, WNOHANG) > 0)
            ; /* clean up child processes */
    }
}
