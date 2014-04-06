#include "easylist.h"
#include "threads/malloc.h"
#include <stdio.h>

SL_elem* sl_new_elem(void *data){
  SL_elem *new_elem = malloc(sizeof (SL_elem));
  ASSERT(new_elem != NULL);
  new_elem->next = NULL;
  new_elem->data = data;
  return new_elem;
}

void sl_list_push(SL_elem *start, void *data) {
  SL_elem *new_elem = sl_new_elem(data);
  new_elem->next = start;
  start = new_elem;
}

SL_elem* sl_list_pop(SL_elem *start) {
  if (start->next) {
    start = start->next;
  }
  return start;
}

/*
Inserts an element into a SORTED list in the proper place by comparison function
*/
int sl_insert_sorted(SL_elem *start, void *insert, sl_sort_func *before) {
  SL_elem *new_elem = sl_new_elem(insert);
  printf("<New list elem>\n");
  //if new element is first
  if (start == NULL || before(new_elem, start)){
    new_elem->next = start;
    start = new_elem;
    printf("<New elem added to start of list\n");
    return 1;
  }
  SL_elem *e = start;
  SL_elem *last = e;
  for (; e != NULL; e = e->next) {
    if (before(new_elem, e)) {
      break;
    }
    last = e;
  }
  last->next = new_elem;
  new_elem->next = e;
  return 1;
}