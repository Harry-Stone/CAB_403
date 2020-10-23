#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>


#define MAXDATASIZE 100 /* max number of bytes we can get at once */

void sendMessage(int fd, const char *msg)
{
    int len = htonl(strlen(msg));
    send(fd, &len, sizeof(len), 0);
    send(fd, msg, len, 0);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in serverAddr;
    int client_s, numbytes, new_fd;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr; /* connector's address information */
    socklen_t sin_size;

    printf("sss %s\n\n", argv[7]);

    int port = atoi(argv[2]);
    if ((he = gethostbyname(argv[1])) == NULL)
    { /* get the host info */
        printf("Could not connect to overseer at %s %s\n", argv[1], argv[2]);
        exit(1);
    }

    if ((client_s = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    /* clear address struct */
    memset(&their_addr, 0, sizeof(their_addr));

    their_addr.sin_family = AF_INET;   /* host byte order */
    their_addr.sin_port = htons(port); /* short, network byte order */
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(client_s, (struct sockaddr *)&their_addr,
                sizeof(struct sockaddr)) == -1)
    {
        printf("Could not connect to overseer at %s %s\n", argv[1], argv[2]);
        exit(1);
    }
    
    sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(client_s, (struct sockaddr *)&their_addr,
                             &sin_size)) == -1)
        {
            perror("accept");
        }
    if (!fork())
        { /* this is the child process */
        //for(int i=0; i < sizeof(*argv); i++){
            if (send(client_s, argv[3], 14, 0) == -1){
            perror("send");
            close(new_fd);
            exit(0);
            }
        }
        //close(new_fd); /* parent doesn't need this */

    //sendMessage(new_fd, "10221450");

    if ((numbytes = recv(client_s, buf, MAXDATASIZE, 0)) == -1)
        {
            perror("recv");
            exit(1);
        }

        buf[numbytes] = '\0';

        printf("Received: %s\n", buf);
    close(client_s);

    return 0;
}
