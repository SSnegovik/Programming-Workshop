#include "list.h"

Element *create_element(int data) {
  Element *new_element = (Element *)malloc(sizeof(Element));
  if (!new_element) {
    return NULL;
  }
  new_element->data = data;
  new_element->next = NULL;
  return new_element;
}

void init_list(CustomList *list) {
  list->start = NULL;
  list->size = 0;
}

void add_to_beginning(CustomList *list, int data) {
  Element *new_element = create_element(data);
  new_element->next = list->start;
  list->start = new_element;
  list->size++;
}

void add_to_end(CustomList *list, int data) {
  Element *new_element = create_element(data);
  if (list->start == NULL) {
    list->start = new_element;
  } else {
    Element *current = list->start;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_element;
  }
  list->size++;
}

void add_at_index(CustomList *list, int data, int index) {
  if (index < 0 || index > list->size) {
    return;
  }
  if (index == 0) {
    add_to_beginning(list, data);
  } else if (index == list->size) {
    add_to_end(list, data);
  } else {
    Element *new_element = create_element(data);
    Element *current = list->start;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    new_element->next = current->next;
    current->next = new_element;
    list->size++;
  }
}

void delete_at_index(CustomList *list, int index) {
  if (index < 0 || index >= list->size) {
    return NULL;
  }
  Element *temp;
  if (index == 0) {
    temp = list->start;
    list->start = list->start->next;
  } else {
    Element *current = list->start;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
  }
  free(temp);
  list->size--;
}

Element *find_at_index(CustomList *list, int index) {
  if (index < 0 || index >= list->size) {
    return NULL;
  }
  Element *current = list->start;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current;
}

int get_size(CustomList *list) { return list->size; }
