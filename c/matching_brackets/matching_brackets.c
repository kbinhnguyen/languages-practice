// problem statement: https://exercism.org/tracks/c/exercises/matching-brackets

#include "matching_brackets.h"
#include <stdlib.h>

list *create_stack() {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    l->size = 0;
    return l;
}

void destroy_stack(list *stack) {
    while (stack->head) {
        node *curr = stack->head;
        stack->head = curr->next;
        free(curr);
    }
    free(stack);
}

bool stack_is_empty(list *l) {
    return (l->size) == 0;
}

void stack_push(list *l, char c) {
    node *n = malloc(sizeof(node));
    n->data = c;
    n->next = l->head;
    l->head = n;
    (l->size)++;
}

char stack_pop(list *l) {
    if (l->size > 0) {
        node *old_head = l->head;
        l->head = l->head->next;
        (l->size)--;
        char data = old_head->data;
        free(old_head);
        return data;
    }
    return '\0';
}

bool is_paired(const char *input) {
    list *stack = create_stack();

    for (const char *c = input; *c != '\0'; c++) {
        switch(*c) {
            case '[':
            case '{':
            case '(':
                stack_push(stack, *c);
                break;
            case ']':
                if (stack_is_empty(stack) || stack_pop(stack) != '[')
                    return false;
                break;
            case '}':
                if (stack_is_empty(stack) || stack_pop(stack) != '{')
                    return false;
                break;
            case ')':
                if (stack_is_empty(stack) || stack_pop(stack) != '(')
                    return false;
                break;
        }
    }
    bool ans = stack_is_empty(stack);
    destroy_stack(stack);
    return ans;
}