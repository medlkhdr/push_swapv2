#include "push_swap.h"

typedef struct vars
{
    int mid ;
    int size;
    int offset;
    int div ;
    int start;
    int end ;

}vars;
static void init(vars *u , stack_t *a)
{
    u->size = stack_size(a);
    u->div = u->size < 100 ? 2 : 8 ;
    u->mid = u->size / 2 - 1 ;
    u->offset = u->size / u->div;
    u->end = u->mid + u->offset ;
    u->start = u->mid - u->offset;
    if(u->start < 0)
        u->start = 0;
    if(u->end > u->size )
        u->end = u->size - 1;
}
void big_sort(stack_t *a   , stack_t *b , int *array , int size_ar)
{
    vars *outils = malloc(sizeof(vars));
    if(!outils)
        return;
    
   free(outils);    
}