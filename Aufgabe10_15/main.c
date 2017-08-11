#include <stdio.h>
#include <stdlib.h>

int main()
{
    // lokale Variablen
    int i = 0, *ptr, *ptr_ptr;

    printf("%p\n",&i);
    printf("%p\n",ptr);
    ptr = NULL;
    printf("%p\n",ptr);
    ptr = &i;
    printf("%p\n",ptr);
    printf("%d\n",*ptr);
    printf("%p\n",&ptr);
    ptr_ptr = &ptr;
    printf("%p",*ptr_ptr);
    printf("%d\n",&i-ptr);
    return 0;
}
