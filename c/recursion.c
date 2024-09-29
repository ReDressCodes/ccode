#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int count;
    char *variables;
    struct data *funcs;
}data_t;

void alloc_data(data_t *input)
{
     static int frame;
     frame++;

     if (frame >= 100) return;

     int count = rand() % 10;

     if (count == 0)
         return;

     input->count = count;
     input->variables = malloc(sizeof(char) * count);

     if (!input->variables) 
     { 
         printf("input->variables \n");
         input->count = 0;
         return; 
     }
     memset(input->variables, 0, sizeof(char) * count);

     input->funcs = malloc(sizeof(data_t) * count);

     if (!input->funcs) 
     {
         printf("input->funcs \n");
         input->count = 0;
         return; 
     }
     memset(input->funcs, 0, sizeof(data_t) * count);

     printf(" Count : %d \n", input->count);

     for (int i = 0; i < input->count; i++)
     {
             alloc_data(input->funcs + i);
     }
}

void free_data(data_t *input)
{
     if (!input->count) return;

     free(input->variables);
     
     for (int i = 0; i < input->count; i++)
     {
          data_t *current = input->funcs + i;
          free_data(current);
     }

     free(input->funcs);
}

int main(int argc, char *argv[])
{
    data_t root;

    memset(&root, 0, sizeof(root));
    printf("Sizeof data_t : %ld \n", sizeof(root));
    srand(time(NULL));
    alloc_data(&root);
    free_data(&root);

    return 0;
}
