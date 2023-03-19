#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H
#include <stdbool.h>

typedef struct list_node node;

typedef struct linked_list list;

struct list_node {
    char data;
    node *next;
};

struct linked_list {
    node *head;
    int size;
};

list *create_stack();

void destroy_stack(list *stack);

bool stack_is_empty(list *l);

void stack_push(list *l, char c);

char stack_pop(list *l);

bool is_paired(const char *input);

#endif