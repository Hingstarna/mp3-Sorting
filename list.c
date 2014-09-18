struct link {
    int *value;
    struct link *next; 
};

struct list {
    struct link *first;
    struct link *last;
};

typedef struct list *List;

List create_list() {
    List l = malloc(sizeof(List));
    if (l != NULL) {
        l->first = NULL;
        l->last = NULL;
        return l;
    }
    return NULL;
}
int list_empty(List l) {
    if (l->first == NULL)
        return 1;
    else
        return 0;
}

void list_add(List l, int item) {
    if (l->first == NULL)
    {
        l->first = malloc(sizeof(int));
        l->last  = l->first;
       *(l->first) = item;
    }
}

int main(void) {
    return 0;
}
