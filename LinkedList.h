#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct link {
  void *value;
  struct link *next;
};

struct list {
  struct link *first;
  struct link *last;
};

typedef struct list *List;
/**
* Creates list, returns pointer to a list
*/
List list_create();

struct link *link_create(void *value, struct link *next);

/**
 * Returns the length of list.
 */
unsigned int list_length(List list);

int list_empty(List list);

void list_inject(struct link *link, void *value);


void list_insert(List list, void *value, int index);
/**
* Inserts value at the start of the list
*/
void list_prepend(List list, void *value);  
/**
* Inserts value at the end of the list
*/
void list_append(List list, void *value);
/**
* Returns a pointer to the first element of the list.
*/
void *list_first(List list);

/**
* Returns a pointer to the last element of the list.
*/
void *list_last(List list);

/**
* Returns a pointer to the value at the specified index in the list.
*/
void *list_get(List list, int index);
#endif // __LINKEDLIST_H__