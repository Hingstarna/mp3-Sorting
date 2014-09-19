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

unsigned int length(List list);

int empty(List list);

void inject(struct link *link, void *value);


void insert(List list, void *value, int index);

void prepend(List list, void *value);  

void append(List list, void *value);

void *first(List list);

void *last(List list);

void *get(List list, int index);
#endif // __LINKEDLIST_H__