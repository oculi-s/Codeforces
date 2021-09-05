#include <stdio.h>
#include <string.h>

int t, n, i;
char s[101];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d\n%s", &n, s);
		for (i = 0; i < strlen(s); i++)
			if (s[i] == 'L' || s[i] == 'R')
				printf("%c", s[i]);
			else if (s[i] == 'U')
				printf("D");
			else
				printf("U");
		printf("\n");
	}
	return 0;
}