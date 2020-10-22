#include<stdio.h>
#include<time.h>
#include<string.h>

char* getDate(){
    char buf[150]; //number is just enough data to hold the date
    time_t curtime;
    struct tm *loc_time;
    curtime = time (NULL);
    loc_time = localtime (&curtime); //convert time to loacal
    return asctime(loc_time);
}

int writeLog(char* message){
    FILE *logFile;
    char* logFileAddress = "/home/cab403/Desktop/CAB_403/log.txt"; //set log file here
    char* date = getDate();
    date[strlen(date) - 1] = 0;//kill the automatic new line on the end of the date
    logFile = fopen(logFileAddress, "a");
    fprintf(logFile, "%s:%s\n", date, message);
    fclose(logFile);
    return 1;
}



int main(){
    writeLog("This is working");
    return 1;
}