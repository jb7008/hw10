#include <stdlib.h> /* Includes malloc */
#include <stdio.h> /* Includes printf */
#include "array_list.h" /* Holds prototypes for functions defined here */

#define MAX 100 /* Maximum number of elements in array */

/* Makes list */
array_list_t*
make_list(char letters[], int n)
{
  /* Allocate enough mem for array_list_t */
  array_list_t *array_list = (array_list_t *)malloc(sizeof(array_list_t));

  /* Assigns each element of letters into array_list's array */
  for(int i = 0; i < n; i++)
  {
    array_list->arr[i] = letters[i];
  }
  /* Sets size of array_list */
  array_list->size = n;

  return array_list;
}

/* Inserts char at first element of the list */
void
append(array_list_t *lst, char c)
{
  insert_at(lst, c, lst->size);
}

/* Inserts char at last element of list */
void
prepend(array_list_t *lst, char c)
{
  insert_at(lst, c, 0);
}

/* Inserts char in list at pos position */
void
insert_at(array_list_t *lst, char c, int pos)
{
  /* Item that keeps track of index of temp */
  int temp_pos = 0;
  /* Temp array to hold new array */
  char temp[MAX];
  /* + 1 to size to account for newly inserted element */
  for(int i = 0; i < lst->size + 1; i++)
  {
    if(i == pos)
    {
      /* Inserts new char into temp array */
      temp[temp_pos++] = c;
    }

    /* Copies arr into temp */
    temp[temp_pos++] = lst->arr[i];
  }
  /* Update size of lst; -1 removes last increment of for loop*/
  lst->size = temp_pos - 1;
  /* Copy temp into lst->arr */
  for(int i = 0; i < lst->size; i++)
  {
    lst->arr[i] = temp[i];
  }
}

/* Returns size of array in lst */
int
size(array_list_t *lst)
{
  return lst->size;
}

/* Removes ith element from list */
void
remove_ith(array_list_t *lst, int pos)
{
  /* Item that keeps track of index of temp */
  int temp_pos = 0;
  /* Temp array to hold new array */
  char temp[MAX];
  /* + 1 to size to account for skipped element */
  for(int i = 0; i < lst->size + 1; i++)
  {
    if(i == pos)
    {
      /* Skips over element in pos position */
      i++;
    }
    /* Copies arr into temp */
    temp[temp_pos++] = lst->arr[i];
  }
  /* Update size of lst */
  lst->size = temp_pos - 1;
  /* Copy temp into lst->arr */
  for(int i = 0; i < lst->size; i++)
  {
    lst->arr[i] = temp[i];
  }
}

/* Deletes memory allocated for structure */
void
delete_list(array_list_t *lst)
{
  free(lst);
}

/* Print out list */
void
print_list(array_list_t *lst)
{
  /* Incrementor */
  int i = 0;

  printf("[");
  /* While size hasn't been reached */
  while(i < lst->size - 1)
  {
    printf("%c|", lst->arr[i]);
    i++;
  }
  /* Prints last char seperately as to not print bar character after it */
  printf("%c]\n", lst->arr[i]);
}
