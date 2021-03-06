#include <stdlib.h>
#include "LinkedList.h"

/**
*Returns a pointer to a new, empty list.
*/
List list_create() {
  List result = malloc(sizeof(struct list));
  if (result != NULL) {
    result->first = NULL;
    result->last = NULL;
    return result;
  }
  return NULL;
}

struct link *link_create(void *value, struct link *next) {
  struct link *result = malloc(sizeof(struct link));
  if (result != NULL) {
    result->value = value;
    result->next = next;
    return result;
  }
  return NULL;
}

/**
* Returns the length of a list represented as an unsigned integer.
*/
unsigned int list_length(List list) {
  unsigned int size = 0;
  struct link *cursor = list->first;
  while (cursor != NULL) {
    ++size;
    cursor = cursor->next;
  }
  return size;
}

/**
* Returns true if list is empty else false
*/
int list_empty(List list) {
  return list->first == NULL;

}

void list_inject(struct link *link, void *value) {
  link->next = link_create(value, link->next);
}

/**
* Inserts value in list at the specified index.
*/
void list_insert(List list, void *value, int index) {
  if (index == 0) {
    list_prepend(list, value);
    return;
  }
  struct link *cursor = list->first;
  while (cursor) {
    if (index-- == 1) list_inject(cursor, value);
    cursor = cursor->next;
  }
}

/**
* Inserts value at the start of the list
*/
void list_prepend(List list, void *value) {
  list->first = link_create(value, list->first);
    if (list->last == NULL) {
      list->last = list->first;
    }
}  
/**
* Inserts value at the end of the list
*/
void list_append(List list, void *value){ 
  if (list->last == NULL) {
    list->last = list->first = link_create(value, NULL);
  }else{
    list->last = list->last->next = link_create(value, NULL);
  }
}
/**
* Returns a pointer to the first element of the list.
*/
void *list_first(List list) {
  if(list_empty(list)) {
    return NULL;
  }else{
    return list->first->value;
  }
}

/**
* Returns a pointer to the last element of the list.
*/
void *list_last(List list) {
  if(list_empty(list)) {
    return NULL;
  }else{
    return list->last->value;
  }
}

/**
* Returns a pointer to the value at the specified index in the list.
*/
void *list_get(List list, int index) {
  struct link *cursor = list->first;
  for (int i = 0;i <= index;i++) {
      if (i == index)
          return cursor->value;
      else
          cursor = cursor->next;
  }
  return NULL;
}

/*
int main(void) {
    List l = list_create();
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    int *z = malloc(sizeof(int));

    *x = 1;
    *y = 2;
    *z = 3;
    append(l,x);
    append(l,y);
    append(l,z);
    for (int i = 0;i < length(l);i++) {
        //printf("Element %d has a value of %d\n",i,*get(l,i));
    }
    free(x);
    free(y);
    free(z);
    //printf("First element is %d\n Last element is %d\n",*first(l),*last(l));
    
    
    List l2 = list_create();
    char *x2 = malloc(sizeof(char));
    char *y2 = malloc(sizeof(char));
    char *z2 = malloc(sizeof(char));
    *x2 = 'a';
    *y2 = 'b';
    *z2 = 'c';
    append(l2,x2);
    append(l2,y2);
    append(l2,z2);
    for (int i = 0; i < length(l2);i++)
    {
        int *test = get(l2,i);
        printf("Element %i has a value of %c\n", i, *test);
    }
    free(x2);
    free(y2);
    free(z2);
    return 0;
}*/

