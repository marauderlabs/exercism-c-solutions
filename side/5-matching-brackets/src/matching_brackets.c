#include "matching_brackets.h"

SLIST_HEAD(stack_s, stackNode_s) head = SLIST_HEAD_INITIALIZER(head);

char pop (struct stack_s *stack);
void free_stack (struct stack_s *stack);

char
pop (struct stack_s *stack)
{
    if (EMPTY(stack)) {
        return '\0';
    }

    stackNode_t *top = PEEK(stack);
    char bracket = top->bracket;

    POP(stack);
    free(top);
    return bracket;
}

void
free_stack (struct stack_s *stack)
{
    while (!EMPTY(stack)) {
        stackNode_t *n = PEEK(stack);
        POP(stack);
        free(n);
    }
}

bool
is_paired (const char *input)
{
    SLIST_INIT(&head);
    struct stack_s *stack = &head;

    char top = '\0';

    for (; *input != '\0'; input++) {
        switch (*input) {
            /* intentional fallthrough */
            case '(':
            case '{':
            case '[': 
            {
                stackNode_t *node = calloc(1, sizeof(stackNode_t));
                node->bracket = *input;
                PUSH(stack, node);
                break;
            }
            case ')':
                top = pop(stack);
                if (top != '(') {
                    free_stack(stack);
                    SLIST_INIT(&head);
                    return false;
                }
                break;

            case '}':

                top = pop(stack);
                if (top != '{') {
                    free_stack(stack);
                    SLIST_INIT(&head);
                    return false;
                }
                break;

            case ']':
                top = pop(stack);
                if (top != '[') {
                    free_stack(stack);
                    SLIST_INIT(&head);
                    return false;
                }
                break;
        } /* switch */
    } /* for */

    if (!EMPTY(stack)) {
        free_stack(stack);
        SLIST_INIT(&head);
        return false;
    }

    return true;
}
