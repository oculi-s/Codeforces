#include <stdio.h>
#include <stdlib.h>

typedef long long ld;
ld n, m, i, x[200000], a, b, s, d, e;
ld _max(ld a, ld b) {
	return a > b ? a : b;
}

ld _min(ld a, ld b) {
	return a < b ? a : b;
}

ld c(ld* a, ld* b) {
	if (*a == *b)
		return 0;
	else
		return *a > *b ? 1 : -1;
}

ld bisect(ld v) {
	ld l = 0, r = n - 1, m;
	while (l < r) {
		m = (l + r) / 2;
		if (x[m] >= v)
			r = m;
		else
			l = m + 1;
	}
	return r;
}

int main() {
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", x + i), s += x[i];
	qsort(x, n, sizeof(ld), c);
	scanf("%lld", &m);
	while (m--) {
		scanf("%lld %lld", &a, &b);
		i = bisect(a);
		d = _max(a - x[i], 0) + _max(b - (s - x[i]), 0);
		if (i)
			d = _min(d, _max(a - x[i - 1], 0) + _max(b - (s - x[i - 1]), 0));
		printf("%lld\n", d);
	}
}