#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int dig, freq;
} digit;

int main() {

    int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    digit* freqDigits = (digit*) malloc(10 * sizeof(digit));
    
    for (int i = 0; i < 10; i++) {
        freqDigits[i].dig = i;
        freqDigits[i].freq = 0;
    }    
    char word[1024];
    scanf("%[^\n]s", &word);
    
    int x = 0;
    while (word[x] != '\0') {
        for (int i = 0; i < 10; i++) {
            if (word[x] - '0' == digits[i]) {
                freqDigits[i].freq++;
                break;
            }
        }
        x++;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", freqDigits[i].freq);
    }
    
    free(freqDigits);
    
    return 0;
}
