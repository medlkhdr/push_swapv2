#include "push_swap.h"

void rotate(stack_t *stack)
{
    if (!stack || !stack->head || !stack->head->next)
        return;
    node_t *first = stack->head;
    stack->head = first->next;
    stack->head->prev = NULL;
    stack->tail->next = first;
    first->prev = stack->tail;
    first->next = NULL;
    stack->tail = first;
}

void ra(stack_t *a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(stack_t *b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(stack_t *a, stack_t *b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void reverse_rotate(stack_t *stack)
{
    if (!stack || !stack->head || !stack->head->next)
        return;
    node_t *last = stack->tail;
    stack->tail = last->prev;
    stack->tail->next = NULL;
    last->prev = NULL;
    last->next = stack->head;
    stack->head->prev = last;
    stack->head = last;
}

void rra(stack_t *a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(stack_t *b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(stack_t *a, stack_t *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}

void swap(stack_t *stack)
{
    if (!stack || !stack->head || !stack->head->next)
        return;
    node_t *first = stack->head;
    node_t *second = first->next;
    first->next = second->next;
    if (first->next)
        first->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->head = second;
    if (stack->tail == second)
        stack->tail = first;
}

void sa(stack_t *a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(stack_t *b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(stack_t *a, stack_t *b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void push(stack_t *from, stack_t *to)
{
    if (!from || !from->head)
        return;
    node_t *top = from->head;
    from->head = top->next;
    if (from->head)
        from->head->prev = NULL;
    else
        from->tail = NULL;
    top->next = to->head;
    if (to->head)
        to->head->prev = top;
    else
        to->tail = top;
    to->head = top;
    top->prev = NULL;
}

void pa(stack_t *a, stack_t *b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(stack_t *a, stack_t *b)
{
    push(a, b);
    write(1, "pb\n", 3);
}