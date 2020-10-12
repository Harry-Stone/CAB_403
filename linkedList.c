//linked list class blocks for project
#include<stdio.h>
#include <stddef.h> // for NULL
#include <stdlib.h> // for EXIT_SUCCESS
#include <string.h> // for strcmp()


#define MAX_FILE_NAME_LENGTH 256

typedef struct job job_t;

struct job
{
    char* filename;
    char* args;
}

typedef struct node node_t;

struct node
{
    job_t *job;
    node_t *next;
}

void print_job(job_t, *in)
{
    printf("File name: %s, Args: %s\n", in->filename, in->args);
}

void print_whole_list(node_t *head)
{
    for(; head!= NULL; head = head->next)
    {
        print_job(head->job);
    }
}

node_t *add_job_via_details(node_t *head, char* name, char* args)
{
    
}

node_t *add_job(node_t *head, job_t *newJob)
{

}