#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int x, y;
} node;

node s[300000];
int t, n, m, k, i, j, c;
int tx[200000], ty[200000];
bool x[1000001], y[1000001];

bool _in(int i, int j, char d) {
	int k;
	if (d == 'x') {
		if (i < j) {
			for (k = i + 1; k < j; k++)
				if (x[k])
					return 1;
		}
		else
			for (k = j + 1; k < i; k++)
				if (x[k])
					return 1;
	}
	else
		if (i < j) {
			for (k = i + 1; k < j; k++)
				if (y[k])
					return 1;
		}
		else
			for (k = j + 1; k < i; k++)
				if (y[k])
					return 1;
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		for (i = 0; i < n; i++)
			scanf("%d", tx + i), x[tx[i]] = 1;
		for (i = 0; i < m; i++)
			scanf("%d", ty + i), y[ty[i]] = 1;
		for (i = 0; i < k; i++)
			scanf("%d %d", &(s[i].x), &(s[i].y));
		c = k * (k - 1) / 2;
		for (i = 0; i < k; i++)
			for (j = i + 1; j < k; j++)
				if (x[s[i].x] && s[i].x == s[j].x)
					c--;
				else if (y[s[i].y] && s[i].y == s[j].y)
					c--;
				else if (x[s[i].x] && y[s[j].y])
					c--;
				else if (x[s[j].x] && y[s[i].y])
					c--;
				else if (x[s[i].x] && x[s[j].x] && _in(s[i].y, s[j].y, 'y'))
					c--;
				else if (y[s[i].y] && y[s[j].y] && _in(s[i].x, s[j].x, 'x'))
					c--;
		printf("%d\n", c);
		for (i = 0; i < n; i++)
			x[tx[i]] = 0;
		for (i = 0; i < m; i++)
			y[ty[i]] = 0;
	}
	return 0;
}