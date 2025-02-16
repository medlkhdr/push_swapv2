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
    {
        u->chunk_size = 20;
        u->num_chunks = (u->size + u->chunk_size - 1) / u->chunk_size;
    }
    else if (u->size <= 500)
    {
        u->chunk_size = 50;
        u->num_chunks = (u->size + u->chunk_size - 1) / u->chunk_size;
    }
    else
    {
        u->chunk_size = 100;
        u->num_chunks = (u->size + u->chunk_size - 1) / u->chunk_size;
    }
}


// Finds index of the target element in the stack
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
   
    
    // Rotate only if necessary
    if (index <= mid) {
        while (a->head->i != target) {
            ra(a);
        }
    } else {
        while (a->head->i != target) {
            rra(a);
        }
    }
}


void push_to_b_in_chunks(stack_t *a, stack_t *b, int *arr, vars *utils)
{
    for (int i = 0; i < utils->num_chunks; i++)
    {
        int chunk_start = i * utils->chunk_size;
        int chunk_end = chunk_start + utils->chunk_size;

        for (int j = chunk_start; j < chunk_end; j++)
        {
            int target = arr[j];
            smart_rotation(a, target);
            pb(a, b);
        }
    }
}

void push_back_to_a(stack_t *a, stack_t *b)
{
    while (b->head)
    {
        int max_val = get_max(b);
        int index = find_index(b, max_val);
        int mid_b = stack_size(b) / 2;
        
        if (index <= mid_b) {
            while (b->head->i != max_val)
                rb(b);
        } else {
            while (b->head->i != max_val)
                rrb(b);
        }
        
        pa(a, b);
        if (a->head->next && a->head->i > a->head->next->i)
            sa(a);
    }
}

// Main sorting function for large stacks
void big_sort(stack_t *a, stack_t *b, int *array)
{
    vars *outils = malloc(sizeof(vars));
    if (!outils)
        return;

    init(outils, a);  // Initialize the chunk sizes and other variables

    push_to_b_in_chunks(a, b, array, outils);  // Push elements to stack B in chunks
    push_back_to_a(a, b);  // Push back elements to stack A in sorted order

    free(outils);  // Free allocated memory
} 