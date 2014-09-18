#include <stdlib.h>

struct link {
  int value;
  struct link *next;
};

struct list {
  struct link *first;
  struct link *last;
};

typedef struct list *List;

List mkList() {
  List result = malloc(sizeof(struct list));
  if (result != NULL) {
    result->first = NULL;
    result->last = NULL;
    return result;
  }
  return NULL;
}

struct link *mkLink(int value, struct link *next) {
  struct link *result = malloc(sizeof(struct link));
  if (result != NULL) {
    result->value = value;
    result->next = next;
    return result;
  }
  return NULL;
}

unsigned int length(List list) {
  unsigned int size = 0;
  struct link *cursor = list->first;
  while (cursor != NULL) {
    ++size;
    cursor = cursor->next;
  }
  return size;
}

int empty(List list) {
  return list->first == NULL;

}

void inject(struct link *link, int value) {
  link->next = mkLink(value, link->next);
}


void insert(List list, int value, int index) {
  if (index == 0) {
    prepend(list, value);
    return;
  }
  struct link *cursor = list->first;
  while (cursor) {
    if (index-- == 1) inject(cursor, value);
    cursor = cursor->next;
  }
}

void prepend(List list, int value) {
  list->first = mkList(value, list->first);
    if (list->last == NULL) {
      list->last = list->first;
    }
}  

void append(List list, int value){ 
  if (list->last == NULL) {
    list->last = list->first = mkLink(value, NULL);
  }else{
    list->last = list->last->next = mkLink(value, NULL);
  }
}

int *first(List list) {
  if(empty(list)) {
    return NULL;
  }else{
    return &(list->first->value);
  }
}

int *last(List list) {
  if(empty(list)) {
    return NULL;
  }else{
    return &(list->last->value);
  }
}

int *get(List list, int index) {
  struct link *cursor = list->first;
  for (int i = 0;i <= index;i++) {
      if (i == index)
          return &(cursor->value);
      else
          cursor = cursor->next;
  }
}

/*
int main(void) {
    List l = mkList();
    append(l,1);
    append(l,2);
    append(l,3);
    for (int i = 0;i < length(l);i++) {
        printf("Element %d has a value of %d\n",i,get(l,i));
    }
    printf("First element is %d\n Last element is %d\n",*first(l),*last(l));
}
*/
