#include <stdio.h>
#include <string.h>

void printHelp(){
    printf("\nCoorect usage of the function is as follows:");
    printf("\ncontroller <address>  <port> {[-o out_file] [-log log_file] [-t seconds] <file> [args....] | mem [pid] | memkill <percent>}\n\n");
    printf("<> indicate required arguments\n[]indicate optional arguments\n... indicates as many args as your heart desires\n");
    printf("{A|B|C|D}indicate that you need to choose one and only one of them\n\n");
}