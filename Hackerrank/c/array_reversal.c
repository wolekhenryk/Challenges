#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    int *tab = (int*) malloc(num * sizeof(int));
    for (i = 0; i < num; i++) {
        tab[num - i - 1] = arr[i];
    }
    
    memcpy(arr, tab, num * sizeof(int));

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
        
    free(arr);
    free(tab);
    
    return 0;
}
