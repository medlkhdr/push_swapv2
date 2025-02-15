#include "push_swap.h"

void message(void)
{
    write(2, "Error\n", 5);
}

void bubble_sort(int *arr, int size) {
    int i, j, temp;

    i = 0;
    while (i < size - 1) {
        j = 0;
        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int *sorted(int *a, int size) {
    int *sorted_arr = (int *)malloc(size * sizeof(int));
    if (!sorted_arr)
        return NULL;

    int i = 0;
    while (i < size) {
        sorted_arr[i] = a[i];
        i++;
    }

    bubble_sort(sorted_arr, size);
    return sorted_arr;
}


size_t ft_strlen(const char *s)
{
    const char *ptr = s;

    if (s[0] == '\0')
    {
        message();
        exit(1);
    }
    while (*ptr)
        ptr++;
    return ((size_t)(ptr - s));
}

int is_sorted(int *a, int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}

char *join(int ac, char **av, size_t size)
{
    char *str;
    int i, j, k;

    i = 1, j = 0;
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
    {
        write(2, "Memory allocation failed\n", 24);
        exit(1);
    }
    while (i < ac)
    {
        k = 0;
        while (av[i][k])
            str[j++] = av[i][k++];
        if (i < ac - 1)
            str[j++] = 32;
        i++;
    }
    str[j] = '\0';
    return (str);
}

void da7k(char *string, int *i)
{
    int j;

    j = 0;
    while (string[j])
    {
        while (string[j] == 32)
            j++;
        if (string[j] >= '0' && string[j] <= '9')
        {
            (*i)++;
            while (string[j] >= '0' && string[j] <= '9')
                j++;
        }
        else
            j++;
    }
}