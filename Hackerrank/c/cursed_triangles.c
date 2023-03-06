#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double calculateArea(const struct triangle *tr) {
    double area, s;
    s = 0.5 * (tr->a + tr-> b + tr->c);
    return sqrt(s * (s - tr->a) * (s - tr->b) * (s - tr->c));
}

int cmp(const void *a, const void *b) {
    triangle tr1 = *(const struct triangle*) a;
    triangle tr2 = *(const struct triangle*) b;
    
    if (calculateArea(&tr1) > calculateArea(&tr2)) {
        return -1;
    } else if (calculateArea(&tr1) < calculateArea(&tr2)) {
        return 1;
    } else {
        return 0;
    }
}

void sort_by_area(triangle* tr, int n) {
	qsort(tr, n, sizeof(struct triangle), cmp);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}