#include "push_swap.h"

typedef struct vars
{
    int size;
    int chunk_size;
    int num_chunks;
} vars;

void init(vars *u, stack_t *a)
{
    u->size = stack_size(a);
    if (u->size <= 100)
        u->chunk_size = 15; // Smaller chunk size for small stacks
    else if (u->size <= 500)
        u->chunk_size = 30; // Medium chunk size for medium stacks
    else
        u->chunk_size = 50; // Larger chunk size for large stacks
    u->num_chunks = (u->size + u->chunk_size - 1) / u->chunk_size;
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

void smart_rotate(stack_t *a, int target)
{
    int index = find_index(a, target);
    if (index == -1)
        return;

    int mid = stack_size(a) / 2;
    if (index <= mid)
    {
        while (a->head->i != target)
            ra(a);
    }
    else
    {
        while (a->head->i != target)
            rra(a);
    }
}

void push_to_b_in_chunks(stack_t *a, stack_t *b, int *arr, vars *utils)
{
    int i = 0;
    while (i < utils->num_chunks)
    {
        int chunk_start = i * utils->chunk_size;
        int chunk_end = chunk_start + utils->chunk_size;
        if (chunk_end > utils->size)
            chunk_end = utils->size;

        int j = chunk_start;
        while (j < chunk_end)
        {
            int target = arr[j];
            smart_rotate(a, target);
            pb(a, b);
            j++;
        }
        i++;
    }
}

void push_back_to_a(stack_t *a, stack_t *b)
{
    while (b->head)
    {
        int max_val = get_max(b);
        int index = find_index(b, max_val);
        int mid_b = stack_size(b) / 2;

        if (index <= mid_b)
        {
            while (b->head->i != max_val)
                rb(b);
        }
        else
        {
            while (b->head->i != max_val)
                rrb(b);
        }
        pa(a, b);
    }
}

void big_sort(stack_t *a, stack_t *b, int *array)
{
    vars *outils = malloc(sizeof(vars));
    if (!outils)
        return;

    init(outils, a);
    push_to_b_in_chunks(a, b, array, outils);
    push_back_to_a(a, b);

    free(outils);
}