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

List list_create();

struct link *link_create(void *value, struct link *next);

unsigned int list_length(List list);

int list_empty(List list);

void list_inject(struct link *link, void *value);


void list_insert(List list, void *value, int index);

void list_prepend(List list, void *value);  

void list_append(List list, void *value);

void *list_first(List list);

void *list_last(List list);

void *list_get(List list, int index);
#endif // __LINKEDLIST_H__