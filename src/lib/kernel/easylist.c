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

void* sl_list_pop(SL_list *list) {
  SL_elem *first = list->start;
  void *data = first->data;
  if (list->start->next) {
    list->start = list->start->next;
  } else {
    list->start = NULL;
  }
  //free(first);
  return data;
}

/*
Inserts an element into a SORTED list in the proper place by comparison function
*/
int sl_insert_sorted(SL_list *list, void *insert, sl_sort_func *before) {
  SL_elem *new_elem = sl_new_elem(insert);
  printf("<New list elem>\n");
  //if new element is first
  if (list->start == NULL || before(new_elem, list->start)){
    new_elem->next = list->start;
    list->start = new_elem;
    printf("<New elem added to start of list: %p>\n", list->start);
    return 1;
  }
  SL_elem *e = list->start;
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