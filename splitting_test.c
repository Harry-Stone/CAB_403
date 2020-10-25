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

// char* split_arg(char str[])
// {
//     char *ptr = strtok(str, " ");
//     char *out = malloc(strlen(str) * sizeof(char));
//     if(out == NULL)
// 		return NULL;
//     // char *out[100];
//     int i = 0;

//     while (ptr != NULL)
//     {
//         out[i++] = ptr;
//         ptr = strtok(NULL," ");
//     }

//     return out;
// }
// char str[] = "working perfectly because c is easy";
//     char *final = split_arg(str);

//     printf("%s\n",final);

//     free(final);

int main(int argc, char *argv[])
{
	// char str[] = "we are all very happy";
    // strcpy(str,*argv);
    string sstr;
    for (int i = 0; i < argc; i++)
    {
        
    }
    

	char delim[] = " ";
    printf("%s",argv[0]);
	char *ptr = strtok(argv, delim);
    // char *out[100];
	while (ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}

	return 0;
}