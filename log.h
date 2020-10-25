#include<stdio.h>
#include<time.h>
#include<string.h>


/*
returns a pointer to a char holding the date in the specified string format
needs to be freed after use with free()
*/
char* getDate(){ 

    char *buf = malloc(20); //create a buffer
    time_t curtime; //init a time struct
    struct tm *loc_time; //set time as a struct
    curtime = time (NULL); //get time
    loc_time = localtime (&curtime); //convert time to local
    sprintf(buf,"%d-%02d-%02d %02d:%02d:%02d",loc_time->tm_year+1900,
        loc_time->tm_mon+1,loc_time->tm_mday,loc_time->tm_hour,loc_time->tm_min,
        loc_time->tm_sec); //format time into string

    return buf; //return it
}


int writeLog(char* message,char* logFileAddress){ //write to the log file specified at the lod address

    char* date = getDate();
    printf("%s:%s\n", date, message); //prepend date to the printf message

    //if(logEnabled != 0){
        FILE *logFile;
        date[strlen(date) - 1] = 0;//kill the automatic new line on the end of the date
        logFile = fopen(logFileAddress, "a");
        fprintf(logFile, "%s:%s\n", date, message); 
        fclose(logFile);
    //}
    //write to the log file

    free(date); //free the earlier malloc from getdate()
    return 1;
}
