#include <stdio.h>

int _diff(int i, int j) {
	int k = i - j, c = 0, l = 10, t = 0;
	while ((i && j) || t && c < k) {
		if (i % 10 - j % 10 - t % 10 < 0)
			c += l, t += 100;
		l *= 10, i /= 10, j /= 10, t /= 10;
	}
	return k - 9 * c;
}

int _count(int n) {
	int i, j, c = 0, v;
	for (i = 1; i <= n / 2; i++) {
		v = _diff(n, i);
		if (v >= i)
			c += 1 + (i != v);
	}
	return c;
}

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", _count(n));
	}
	return 0;
}