#include<stdio.h>
#include<time.h>
#include<string.h>

char* getDate(){
    // char buf[150]; //number is just enough data to hold the date
    char *buf = malloc(20);
    time_t curtime;
    struct tm *loc_time;
    curtime = time (NULL);
    loc_time = localtime (&curtime); //convert time to local
    sprintf(buf,"%d-%02d-%02d %02d:%02d:%02d",loc_time->tm_year+1900,
        loc_time->tm_mon,loc_time->tm_mday,loc_time->tm_hour,loc_time->tm_min,
        loc_time->tm_sec);
        
    printf("%s\n",buf);
    // return asctime(loc_time);

    return buf;
}


int writeLog(char* message){
    FILE *logFile;
    char* logFileAddress = "/home/cab403/Desktop/CAB_403/log.txt"; //set log file here
    char* date = getDate();
    date[strlen(date) - 1] = 0;//kill the automatic new line on the end of the date
    logFile = fopen(logFileAddress, "a");
    fprintf(logFile, "%s:%s\n", date, message);
    fclose(logFile);
    free(date);
    return 1;
}



int main(){
    writeLog("This is working");
    return 1;
}