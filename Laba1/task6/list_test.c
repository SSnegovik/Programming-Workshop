#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_init_list() {
  CustomList list;
  init_list(&list);
  assert(get_size(&list) == 0);
  assert(list.start == NULL);
}

void test_add_elements() {
  CustomList list;
  init_list(&list);

  add_to_end(&list, 100);
  assert(get_size(&list) == 1);
  assert(list.start->data == 100);

  add_to_beginning(&list, 50);
  assert(get_size(&list) == 2);
  assert(list.start->data == 50);

  add_at_index(&list, 75, 1);
  assert(get_size(&list) == 3);
  assert(find_at_index(&list, 1)->data == 75);

  add_to_end(&list, 200);
  assert(get_size(&list) == 4);
  assert(find_at_index(&list, 3)->data == 200);
}
void test_find_and_delete() {
  CustomList list;
  init_list(&list);
  add_to_end(&list, 5);
  add_to_end(&list, 10);
  add_to_end(&list, 15);

  assert(find_at_index(&list, 1)->data == 10);

  delete_at_index(&list, 1);
  assert(get_size(&list) == 2);
  assert(find_at_index(&list, 1)->data == 15);
}

int main() {
  test_init_list();
  test_add_elements();
  test_find_and_delete();
  return 0;
}
