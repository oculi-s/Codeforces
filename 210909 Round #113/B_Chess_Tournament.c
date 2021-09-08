#include <stdio.h>
#include <string.h>

char m[51][51], s[51];
int t, n, i, j;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d\n%s", &n, s);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				m[i][j] = '=', m[j][i] = '=';
			m[i][i] = 'X';
		}
		for (i = 0; i < n; i++)
			if (s[i] == '2') {
				for (j = 0; j < n; j++)
					if (s[j] != '1' && m[i][j] == '=') {
						m[i][j] = '+', m[j][i] = '-';
						break;
					}
				if (j == n) {
					printf("NO\n");
					break;
				}
			}
		if (i == n) {
			printf("YES\n");
			for (i = 0; i < n; i++)
				m[i][n] = 0, printf("%s\n", m[i]);
		}
	}
	return 0;
}