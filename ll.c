#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/* Make a single node with c as payload */
node_t
*make_node(char c)
{
  /* Allocate enough space for node_t */
  node_t *n = (node_t *) malloc(sizeof(node_t));
  n->letter = c; /* Assigns char to letter element */
  n->next = NULL; /* Points next element to nothing */
  return n;
}

/* Make a list of characters with a string input and size */
node_t
*make_list(char letters[], int size)
{
  /* Implements the first element of the linked list */
  node_t *head = make_node(letters[0]);
  /* Points the end of the list to the beginning since there is
     only 1 element */
  node_t *last = head;
  /* Adds elements to linked list while there are letters to add */
  for (int i = 1; i < size; i++){
    node_t *temp = make_node(letters[i]);
    /* Moves the end along */
    last->next = temp;
    last = temp;
  }

  return head;
}

/* Print the list. See an example output in the test sheet. */
void
print_list(node_t *head)
{
  if(head == NULL) /* If the end of the list */
  {
    printf("NULL\n"); /* Print the line ending */
  }
  else
  {
    printf("%c -> ", head->letter); /* Print the letter */
    print_list(head->next); /* Progresses through the linked list */
  }
}

/* Return number of nodes */
int
size(node_t *head)
{
  /* Variable to hold size of linked list. Starts at 1 to account for
     inital element*/
  int size = 1;
  /* Assign head to temp variable */
  node_t *temp = head;
  /* While the end of the list hasn't been reached */
  while(temp->next != NULL)
  {
    /* Count elements & progress list*/
    size++;
    temp = temp->next;
  }

  return size;
}

/* Add a node with c as payload before the current head. Return the new head. */
node_t
*prepend(node_t *head, char c)
{
    /* Creates node to insert */
    node_t *to_insert = make_node(c);
    /* Puts new node at beginning */
    to_insert->next = head;

    /* Returns new node */
    return(to_insert);
}

/* Add a node at the end of list with payload c. */
node_t
*append(node_t *head, char c)
{
  /* Gets length of linked list */
  int length = size(head);
  /* Inserts element at end */
  return insert_at(head, c, length);
}

/* Make and insert a node after the ith node (0-indexed) */
node_t
*insert_at(node_t *head, char c, int pos)
{
  /* Use prepend function if first element */
  if(pos == 0)
  {
    return(prepend(head, c));
  }
  else{
    /* Keeps track of the current list index */
    int list_index = 0;
    /* Keeps track of the current indexed element */
    node_t *last = head;
    /* Progresses thoguth list until it is at the right element */
    while(list_index < pos - 1)
    {
      last = last->next;
      list_index++;
    }
    /* Creates node to insert */
    node_t *to_insert = make_node(c);
    /* Assigns next element of new node to old next element */
    to_insert->next = last->next;
    /* Inserts new node by assigning old next element to new insert */
    last->next = to_insert;

    return head;
  }
}

/* Remove a node at the ith position (0-indexed) and free the space of the node */
node_t
*remove_ith(node_t *head, int i)
{
  /* If first element */
  if(i == 0)
  {
    /* Makes head equal to the second element */
    node_t *skip = head->next;
    /* Frees old head */
    free(head);
    /* Makes skip new head */
    return skip;
  }
  else
  {
    /* Keeps track of the current list index */
    int list_index = 0;
    /* Keeps track of the current indexed element */
    node_t *last = head;
    /* Progresses thoguth list until it is at the right element */
    while(list_index < i - 1)
    {
      last = last->next;
      list_index++;
    }
    /* Assigns the next element in the linked list to skip over the element
       after it */
    node_t *skip = last->next;
    last->next = skip->next;
    /* Frees node removed */
    free(skip);
    return head;
  }
}

/* Free the space of the nodes and set the head to NULL. */
void
delete_list(node_t **head)
{
  /* Node for progressing through list */
  node_t *current = *head;
  /* Marks next element */
  node_t *next;

  /* While end hasn't been reached */
  while(current != NULL)
  {
    /* Gets next element */
    next = current->next;
    /* Frees last element */
    free(current);
    /* Assigns progression element to next element */
    current = next;
  }
  /* Removes head pointer */
  *head = NULL;
}

/* Prints out the payload of a node in a single line */
void
print_node(node_t n)
{

}

/* Return a pointer to the ith element (0-indexed) */
node_t
*get_ith(node_t *head, int pos)
{

}

/* Make and insert a node after a node */
void
insert_after(node_t *node, char c)
{

}