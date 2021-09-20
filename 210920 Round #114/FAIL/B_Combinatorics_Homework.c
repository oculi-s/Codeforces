#include <stdio.h>

int t, a, b, c, d, m, f, e;

typedef struct {
	int a, b, c, d;
	char e;
} node;

node s[13000000];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &a, &b, &c, &m), d = 0;
		s[0].a = a, s[0].b = b, s[0].c = c, s[0].d = d, s[0].e = -1, e = 1;
		while (e) {
			e--, a = s[e].a, b = s[e].b, c = s[e].c, d = s[e].d, f = s[e].e;
			if (a + b + c == 0) {
				if (d == m)
					break;
			}
			else if (d <= m) {
				if (a)
					s[e].a = a - 1, s[e].b = b, s[e].c = c, s[e].d = d + (f == 0), s[e].e = 0, e++;
				if (b)
					s[e].a = a, s[e].b = b - 1, s[e].c = c, s[e].d = d + (f == 1), s[e].e = 1, e++;
				if (c)
					s[e].a = a, s[e].b = b, s[e].c = c - 1, s[e].d = d + (f == 2), s[e].e = 2, e++;
			}
		}
		printf("%s\n", a + b + c == 0 && d == m ? "YES" : "NO");
	}
	return 0;
}