#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

// Stack node structure
typedef struct node
{
    int i;
    struct node *next;
    struct node *prev;
} node_t;

// Stack structure
typedef struct stack
{
    node_t *head;
    node_t *tail;
} stack_t;

// Function prototypes
void message(void);
void bubble_sort(int *arr, int size);
int *sorted(int *a, int size);
// Utility functions
size_t ft_strlen(const char *s);
int is_sorted(int *a, int k);
char *join(int ac, char **av, size_t size);
void da7k(char *string, int *i);

// Parsing functions
void replace_by_space(char *str);
void check(char *str);
void handle_overflow(int *a, char *b);
int *parse_input(int ac, char **av, int *k);
void parse_numbers(char *input, int *arr);
int extract_number(char *input, int *i, int *arr);
void is_here_dup(int *a, int k);

// Sorting functions
void sort_2(stack_t *a);
void sort_3(stack_t *a);
void sort_5(stack_t *a, stack_t *b);
void big_sort(stack_t *a, stack_t *b, int *array);
// Stack operations
void rotate(stack_t *stack);
void ra(stack_t *a);
void rb(stack_t *b);
void rr(stack_t *a, stack_t *b);
void reverse_rotate(stack_t *stack);
void rra(stack_t *a);
void rrb(stack_t *b);
void rrr(stack_t *a, stack_t *b);
void swap(stack_t *stack);
void sa(stack_t *a);
void sb(stack_t *b);
void ss(stack_t *a, stack_t *b);
void push(stack_t *from, stack_t *to);
void pa(stack_t *a, stack_t *b);
void pb(stack_t *a, stack_t *b);

// Stack utility functions
int stack_size(stack_t *stack);
int get_min(stack_t *stack);
int get_max(stack_t *stack);
stack_t *fill_stack(int *arr, int k);
void free_stack(stack_t *stack);
stack_t *initialize_stack(void);
void afficher_stack(stack_t *a);

#endif // PUSH_SWAP_H