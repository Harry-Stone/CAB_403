//linked list class blocks for project
#include <stdio.h>
#include <stddef.h> // for NULL
#include <stdlib.h> // for EXIT_SUCCESS
#include <string.h> // for strcmp()

#define MAX_FILE_NAME_LENGTH 256

typedef struct job job_t;

struct job
{
    char* filename;
    char *args[];
};

typedef struct node node_t;

struct node
{
    job_t *job;
    node_t *next;
};


job_t* New_Job(char* name, char* args) { 
  job_t* p = malloc(sizeof(job_t));
  p->filename = name;
  p->args = args;
  return p;
}

void print_job(job_t *in)
{
    printf("File name: %s, Args: %s\n", in->filename, in->args);
}



job_t test = New_Job(&"filename here!", &"a bbbb dsofijh");
print_job(&test);
free(test);


/*
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
*/