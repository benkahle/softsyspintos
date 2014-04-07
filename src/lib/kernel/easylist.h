#ifndef __LIB_KERNEL_EASYLIST_H
#define __LIB_KERNEL_EASYLIST_H

typedef struct sl_elem {
  struct sl_elem *next;
  void* data;
} SL_elem;

typedef struct{
  SL_elem *start;
} SL_list;

typedef int sl_sort_func(SL_elem *a, SL_elem *b);

SL_elem* sl_new_elem(void *data);
void* sl_list_pop(SL_list*);
int sl_insert_sorted(SL_list *list, void *insert, sl_sort_func *before);


#endif /* lib/kernel/easylist.h */