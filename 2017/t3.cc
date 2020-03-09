#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

const int MAX = 100 + 0xAC;
using namespace std;

int n, ans, m, a[MAX][MAX], color[MAX][MAX];
const int dx[4] = {1, 0, -1, 0};  // four directions
const int dy[4] = {0, 1, 0, -1};  // four directions

/*
 * @x: X-coordinate
 * @y: Y-coordinate
 * @cost: cost
 * @p: color changed
 */
void dfs(int x, int y, int cost, int p)
{
	int c;

	if ((x == n) && (y == n)) {
		ans = min(ans,cost);
		return;
	}

	if (a[x][y] <= cost)
		return; // cut
	else 
		a[x][y] = cost; // replace
	if (cost > ans)
		return; // cut

	for (int i = 0; i < 4; i++) {
		if ((x + dx[i] > 0) && (x + dx[i] <= n) &&
			(y + dy[i] > 0) && (y + dy[i] <= n)) {
			// keep on board
			if (color[x][y] == color[x + dx[i]][y + dy[i]]) {
				// same color
				c = color[x][y];
				if (p)
					color[x][y] = 0; // color changed
				dfs(x + dx[i], y + dy[i], cost, 0); // add cost
				color[x][y] = c;   // recover the colour
			} else if (color[x + dx[i]][y + dy[i]])	{
				// different color
				c = color[x][y];
				if (p)
					color[x][y] = 0;
				dfs(x + dx[i], y + dy[i], cost + 1, 0); //cost+1
				color[x][y] = c;
			} else if (!p) {
				// no color change
				color[x + dx[i]][y + dy[i]] = color[x][y];
				dfs(x + dx[i], y + dy[i], cost + 2, 1); //cost+2
				color[x + dx[i]][y + dy[i]] = 0; // color recovery
			}
		}
	}
}

int main()
{
	int x, y, c;

	memset(a, 127/3, sizeof(a));
	ans=a[0][0];

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> c;
		color[x][y] = c + 1;
	}
	dfs(1, 1, 0, 0);
	if (ans == a[0][0])
		ans = -1;
	cout << ans << endl;
}