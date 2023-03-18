/* problem statement: https://exercism.org/tracks/c/exercises/linked-list */

#include "linked_list.h"
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

// constructs a new (empty) list
struct list *list_create(void) {
   struct list *new_list = malloc(sizeof(struct list));
   new_list->first = NULL;
   new_list->last = NULL;
   return new_list;
}

// counts the items on a list
size_t list_count(const struct list *list) {
   int count = 0;
   if (list != NULL) {
      struct list_node *node = list->first;
      while (node != NULL) {
         count++;
         node = node->next;
      }
   }
    return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data) {
   if (list == NULL) list = list_create();
   struct list_node *new_tail = malloc(sizeof(struct list_node));
   new_tail->data = item_data;
   new_tail->prev = list->last;
   new_tail->next = NULL;
   if (list->last != NULL) list->last->next = new_tail;
   list->last = new_tail;
   if (list->first == NULL) list->first = new_tail;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list) {
   struct list_node *old_tail = list->last;
   ll_data_t data = old_tail->data;
   list->last = list->last->prev;
   if (list->last != NULL) list->last->next = NULL;
   if (list->first == old_tail) list->first = NULL;
   free(old_tail);
   return data;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data) {
   if (list == NULL) list = list_create();
   struct list_node *new_head = malloc(sizeof(struct list_node));
   new_head->data = item_data;
   new_head->next = list->first;
   new_head->prev = NULL;
   if (list->last == NULL) list->last = new_head;
   if (list->first != NULL) list->first->prev = new_head;
   list->first = new_head;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list) {
   struct list_node *old_head = list->first;
   ll_data_t data = old_head->data;
   list->first = old_head->next;
   if (list->first != NULL) list->first->prev = NULL;
   if (list->last == old_head) list->last = NULL;
   free(old_head);
   return data;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data) {
   struct list_node *curr = list->first;
   while (curr != NULL && curr->data != data) {
      curr = curr->next;
   }
   if (curr != NULL) {
      struct list_node *prev = curr->prev;
      struct list_node *next = curr->next;
      if (next != NULL) next->prev = prev;
      if (prev != NULL) prev->next = next;
      if (list->first == curr) list->first = next;
      if (list->last == curr) list->last = prev;
      free(curr);
   }
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list) {
   if (list != NULL) {
      struct list_node *node = list->first;
      struct list_node *prev;
      while (node != NULL) {
         prev = node;
         node = node->next;
         free(prev);
      }
      free(list);
   }
}
