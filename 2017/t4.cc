// hopscotch
// suppose the cost range is 0~k, binary search for the best cost

#include <iostream>
#include <cstdio>
#include <cstring>

const int MAX = 500000 + 0xAC;
int f[MAX], a[MAX][2], n, d, k, ok, lpos, rpos;
using namespace std;

bool check(int g)
{
	lpos = d - g; // shortest jump
	rpos = d + g; // longest jump

	if (lpos <= 0)
		lpos = 1;
	memset(f, -127, sizeof(f));

	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i][0] - a[j][0] < lpos)
				continue;
			if (a[i][0] - a[j][0] > rpos)
				break;
			f[i] = max(f[i], f[j] + a[i][1]);

			if (f[i] >= k)
				return true;
		}
	}
	return false;
}

int main()
{
	int i, ans = -1, l = 0, r = 1005, m;

	cin >> n >> d >> k;

	for (i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1];

	m = (l + r) / 2;
	while (l <= r)	{
		if (check(m)) {
			ans = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
		m = (l + r) / 2;
	}
	cout << ans;
	return 0;
}


