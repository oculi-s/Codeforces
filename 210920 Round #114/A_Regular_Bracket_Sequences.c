#include <stdio.h>

int t, n, i, j;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			for (j = 0; j < i; j++)
				printf("(");
			for (j = 0; j < i; j++)
				printf(")");
			for (j = 0; j < n - i; j++)
				printf("(");
			for (j = 0; j < n - i; j++)
				printf(")");
			printf("\n");
		}
	}
	return 0;
}