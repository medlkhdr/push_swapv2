#include "push_swap.h"
void is_sorted_stack(stack_t *a)
{
    node_t *tmp = a->head;
    while(tmp->next)
    {
        if(tmp->i > tmp->next->i)
        {
            printf("not sorted");
            return ;
        }
        tmp = tmp->next;
    }
    printf("sorted"); 
}
int main(int ac, char **av)
{
    int k;
    int *ar;
    stack_t *stacka;
    stack_t *stackb;

    k = 0;
    if (ac < 2)
        return (0);
    if (av[1] == NULL)
    {
        message();
        exit(1);
    }
    ar = parse_input(ac, av, &k);
    is_here_dup(ar, k);
    stackb = initialize_stack();
    stacka = fill_stack(ar, k);
    int size = stack_size(stacka);
    int *sorted_ar = sorted(ar, k);
    if (size == 2) 
        sort_2(stacka);
    else if (size == 3) 
        sort_3(stacka);
    else if (size <= 5) 
        sort_5(stacka, stackb);
    else
        big_sort(stacka, stackb, sorted_ar);
    afficher_stack(stacka);
    is_sorted_stack(stacka);
    free_stack(stacka);
    free_stack(stackb);
    free(ar);
    return (0);
}