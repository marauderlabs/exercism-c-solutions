#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stdbool.h>
#include <stdlib.h>
#include <sys/queue.h>

#define PUSH(stack, n) SLIST_INSERT_HEAD(stack, n, next)
#define PEEK(stack)    SLIST_FIRST(stack)
#define POP(stack)     SLIST_REMOVE_HEAD(stack, next)
#define EMPTY(stack)   SLIST_EMPTY(stack)

typedef struct stackNode_s {
    char bracket;
    SLIST_ENTRY(stackNode_s) next;
} stackNode_t;

bool is_paired(const char *input);

#endif
