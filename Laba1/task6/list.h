#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
  int data;
  struct Element *next;
} Element;

typedef struct {
  Element *start;
  int size;
} CustomList;

Element *create_node(int data);
void init_list(CustomList *list);
void add_to_beginning(CustomList *list, int data);
void add_to_end(CustomList *list, int data);
void add_at_index(CustomList *list, int data, int index);
void delete_at_index(CustomList *list, int index);
Element *find_at_index(CustomList *list, int index);
int get_size(CustomList *list);