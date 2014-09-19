#include <stdlib.h>

struct link {
  void *value;
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

struct link *mkLink(void *value, struct link *next) {
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

void inject(struct link *link, void *value) {
  link->next = mkLink(value, link->next);
}


void insert(List list, void *value, int index) {
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

void prepend(List list, void *value) {
  list->first = mkList(value, list->first);
    if (list->last == NULL) {
      list->last = list->first;
    }
}  

void append(List list, void *value){ 
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
    return list->first->value;
  }
}

int *last(List list) {
  if(empty(list)) {
    return NULL;
  }else{
    return list->last->value;
  }
}

int *get(List list, int index) {
  struct link *cursor = list->first;
  for (int i = 0;i <= index;i++) {
      if (i == index)
          return cursor->value;
      else
          cursor = cursor->next;
  }
}


int main(void) {
    List l = mkList();
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
        printf("Element %d has a value of %d\n",i,*get(l,i));
    }
    free(x);
    free(y);
    free(z);
    //printf("First element is %d\n Last element is %d\n",*first(l),*last(l));
    
    
    List l2 = mkList();
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
        printf("Element %d has a value of %c\n", i, *get(l2,i));
    }
    free(x2);
    free(y2);
    free(z2);
    return 0;
}

