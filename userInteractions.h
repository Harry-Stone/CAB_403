#include <stdio.h>
#include <string.h>
#include "log.h"

void printHelp(){
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
    printf("%d ARGS\n\n\n", argc);
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
    // with any and unlimited args, which could then themselves have the form -log or simmilar invalidationg order validation

    if(strcmp(argv[3],"mem")==0||strcmp(argv[3],"memkill")==0){
        if(argc!=5){
            printf("Wrong number of arguments for mem or memkill\n");
            agressivelyPrintHelp();
        }
        if(strcmp(argv[3],"mem")==0){
            mode = 2;
        }
        if(strcmp(argv[3],"memkill")==0){
            //validate that percent is between 0 and 100
            if(atoi(argv[4]) <= 100 && atoi(argv[4]) >= 0){
                mode = 3;
            }else{
                printf("number entered for memkill percent is outside of 1 to 100 range\n\n");
                agressivelyPrintHelp();
            }
            
        }
    } else {
        mode = 1;
        //loop through to see if -log is wanted
        for(int i=0; i<argc; i++){
            if(strcmp(argv[i],"-log")==0 && i<argc-1){
                logEnabled=1;
                logFileAddress = argv[i+1];
            }
        }
    }

    return mode;
}