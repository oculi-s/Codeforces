#include <stdio.h>
#include <stdlib.h>
#define D 998244353

typedef unsigned long long ld;

int _c(int* a, int* b) {
	return *a - *b;
}

ld _f(int n, int k) {
	ld v = 1;
	n++;
	while (--n)
		if (n != k)
			v *= n, v %= D;
	return v % D;
}

int t, n, x[200010], i;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", x + i);
		qsort(x, n, sizeof(int), _c);
		if (x[n - 1] - x[n - 2] > 1)
			printf("0\n");
		else if (x[n - 1] - x[n - 2] == 1) {
			i = n - 2;
			while (x[i] == x[n - 1] - 1)
				i--;
			printf("%lld\n", (_f(n, 0) + D - _f(n, n - i - 1)) % D);
		}
		else
			printf("%lld\n", _f(n, 0));
	}
	return 0;
}