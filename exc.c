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

char* getDate(){
    char *buf = malloc(sizeof(int) * 20);
    time_t curtime;
    struct tm *loc_time;
    curtime = time (NULL);
    loc_time = localtime (&curtime); //convert time to local
    sprintf(buf,"%d-%02d-%02d %02d:%02d:%02d",loc_time->tm_year+1900,
        loc_time->tm_mon,loc_time->tm_mday,loc_time->tm_hour,loc_time->tm_min,
        loc_time->tm_sec);

    printf("%d\n",buf);
    //return loc_time;

    return buf;
}

int main(){
    char *godate = getDate();
    printf("%s\n", godate);
}