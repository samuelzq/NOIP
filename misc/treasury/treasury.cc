#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int find_stair(int **r, int s, int m)
{
    int i, p;

    p = r[s][1];
	i = s;

    while (p) {
        if (r[i][0]) {
            p--;
            continue;
        }
        if (++i == m)
            i = 0;
    }
    return i;
}

int main()
{
    int n, m, s, i, cnt;
    int ***a;

    cin >> n >> m;

    a = new int **[n];
    for (i = 0; i < n; i++) {
        a[i] = new int *[m];
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            a[i][j] = new int[2];
    }

    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j][0] >> a[i][j][1];
        }
    }
    cin >> s;
#if 0
	for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j][0] << ' ' << a[i][j][1] << '\t';
        }
		cout << endl;
    }
#endif

    for (int st = s, i = 0; i < n; i++) {
		cnt += a[i][st][1];
		//cout << a[i][st][1] << ' ' << cnt << endl;
        //cout << '#' << i << "st = " << st << endl;
		st = find_stair(a[i], st, m);
    }
    cout << cnt << endl;

    return 0;
}
