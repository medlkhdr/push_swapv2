#include "push_swap.h"
#include <stdio.h> // For debugging (remove later)

typedef struct vars
{
    int mid;
    int size;
    int offset;
    int div;
    int start;
    int end;
    int check;
} vars;

static void init(vars *u, stack_t *a)
{
    u->size = stack_size(a);
    u->div = 2;
    u->mid = u->size / 2;
    u->offset = u->size / u->div;
    u->end = u->mid + u->offset;
    u->start = (u->mid - u->offset < 0) ? 0 : u->mid - u->offset;
    if (u->end >= u->size)
        u->end = u->size - 1;
    printf("Stack Size: %d, Div: %d, Start: %d, End: %d\n", u->size, u->div, u->start, u->end);
}

int is_in_range(int i, int *arr, int size, int start)
{
    for (int j = start; j < size; j++)
    {
        if (i == arr[j])
            return 1;
    }
    return 0;
}

int find_index(stack_t *a, int target)
{
    int index = 0;
    node_t *current = a->head;
    while (current)
    {
        if (current->i == target)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}

void smart_rotation(stack_t *a, int target)
{
    int index = find_index(a, target);
    if (index == -1)
        return;
    int mid = stack_size(a) / 2;
    while (a->head->i != target)
    {
        if (index <= mid)
            ra(a);
        else
            rra(a);
    }
}

void push_to_b(stack_t *a, stack_t *b, int *arr, vars *utils)
{
    while (utils->start <= utils->end)
    {
        int target = arr[utils->start];
        int index = find_index(a, target);

        if (index == -1)
        {
            utils->start++;
            continue;
        }
        while (a->head->i != target)
            smart_rotation(a, target);
        pb(a, b);
        if (b->head && b->head->i > arr[utils->mid])
            rb(b);

        utils->start++;
    }
}

void update_range(vars *outils)
{
    if (outils->start >= outils->size)
        return;

    outils->start = (outils->start - outils->offset < 0) ? 0 : outils->start - outils->offset;
    outils->end = (outils->end + outils->offset >= outils->size) ? outils->size - 1 : outils->end + outils->offset;
    if (outils->start < 0)
        outils->start = 0;
    if (outils->end >= outils->size)
        outils->end = outils->size - 1;
    printf("Updated Range: Start: %d, End: %d\n", outils->start, outils->end);
}

void push_back_to_a(stack_t *a, stack_t *b)
{
    while (b->head)
    {
        int max_val = get_max(b);
        int index = find_index(b, max_val);
        while (b->head->i != max_val)
        {
            if (index <= stack_size(b) / 2)
                rb(b);
            else
                rrb(b);
        }

        pa(a, b);
        if (a->head->next && a->head->i > a->head->next->i)
            sa(a);
    }
}
void big_sort(stack_t *a, stack_t *b, int *array)
{
    vars *outils = malloc(sizeof(vars));
    if (!outils)
        return;

    init(outils, a);
    outils->check = 0;

    while (outils->check < outils->div)
    {
        push_to_b(a, b, array, outils);
        update_range(outils);
        outils->check++;
    }

    push_back_to_a(a, b);
    free(outils);
}