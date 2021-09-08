#include <stdio.h>
#include <string.h>

int t, n, i, j, a, b;
char s[51];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d\n%s", &n, s);
		for (i = 1; i < n; i++)
			if (s[i - 1] != s[i]) {
				printf("%d %d\n", i, i + 1);
				break;
			}
		if (i == n)
			printf("-1 -1\n");
	}
	return 0;
}