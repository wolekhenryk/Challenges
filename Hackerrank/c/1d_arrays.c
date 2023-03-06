#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, i, sum = 0;
    scanf("%d", &n);
    
    int* tab = (int*) malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++)
        scanf("%d\n", &tab[i]);
    
    for (i = 0; i < n; i++)
        sum += tab[i];
     
    printf("%d", sum);
    free(tab);
     
    return 0;
}
