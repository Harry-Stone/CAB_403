#include <stdio.h>
#include <string.h>
#include "log.h"

/*
this file holds the functions that validate the input arguments and print the help function if requested. it applys mainly to client
*/

void printHelp(){ //prints help
    printf("\nCorrect usage of the function is as follows:");
    printf("\ncontroller <address>  <port> {[-o out_file] [-log log_file] [-t seconds] <file> [args....] | mem [pid] | memkill <percent>}\n\n");
    printf("<> indicate required arguments\n[] indicate optional arguments\n... indicates as many args as your heart desires\n");
    printf("{A|B|C|D}indicate that you need to choose one and only one of them\n\n");
    exit(1);
}

void agressivelyPrintHelp(){ //like help but to stderr
    fprintf(stderr,"\nCorrect usage of the function is as follows:");
    fprintf(stderr,"\ncontroller <address>  <port> {[-o out_file] [-log log_file] [-t seconds] <file> [args....] | mem [pid] | memkill <percent>}\n\n");
    fprintf(stderr,"<> indicate required arguments\n[] indicate optional arguments\n... indicates as many args as your heart desires\n");
    fprintf(stderr,"{A|B|C|D}indicate that you need to choose one and only one of them\n\n");
    exit(0);
}

int validateInputs(int argc, char *argv[]){
    int mode = 0; //mode is set to 1,2 or 3 on output and indicates weather to send an execute, mem or memkill command to set percentages

    
    if(argc >= 2){
        if(strcmp(argv[1], "--help")==0){
            printHelp();
        }
    }
    if (argc < 4){
        printf("not enough arguments provided. type: \"--help\" for information on correct use of the function\n");
        agressivelyPrintHelp();
    }

    //impossible to validate args for the file options because the first arg can be file(called anyhting)
    // with any and unlimited args, which could then themselves have the form -log or simmilar, thus invalidating order validation

    if(strcmp(argv[3],"mem")==0||strcmp(argv[3],"memkill")==0){ //check if mem or memkill mode is being used
        if(argc!=5){ //checks the number of arguments with 5 being the correct number for memkill or mem
            printf("Wrong number of arguments for mem or memkill\n");
            agressivelyPrintHelp();
        }
        if(strcmp(argv[3],"mem")==0){ //set to mem mode if mem is the argument
            mode = 2;
        }
        if(strcmp(argv[3],"memkill")==0){ //if memkill validate that the int following is a valid percentage
            //validate that percent is between 0 and 100
            if(atoi(argv[4]) <= 100 && atoi(argv[4]) >= 0){
                mode = 3;
            }else{
                printf("number entered for memkill percent is outside of 1 to 100 range\n\n");
                agressivelyPrintHelp();
            }
            
        }
    } else {
        mode = 1; //default is to run the file
        //loop through to see if -log is wanted
        for(int i=0; i<argc; i++){
            if(strcmp(argv[i],"-log")==0 && i<argc-1){ //this was not implimented, but this is where it would be if it were
                // logEnabled=1;
                // logFileAddress = argv[i+1];
                writeLog("You chose to include logs, here is proof that we can get your log arguments with a date", argv[i+1]);
            }
        }
    }

    return mode;
}