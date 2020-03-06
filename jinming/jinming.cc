#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int main()
{
    int t, m, i, j;
    int **f, *w, *v;

    cin >> t >> m;
    w = new int[m + 1]();
    v = new int[m + 1]();
	f = new int *[m + 1]();
	for (i = 0; i < m + 1; i++)
		f[i] = new int[t + 1]();

    for (i = 1; i < m + 1; i++) {
        cin >> w[i] >> v[i];
		v[i] *= w[i];
	}

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= t; j++) {
            if (j >= w[i])
                f[i][j] = MAX(f[i - 1][j - w[i]] + v[i], f[i - 1][j]);
			else
				f[i][j] = f[i - 1][j];
        }
    }
    cout << f[m][t] << endl;
    delete f;
    delete w;
    delete v;
    return 0; 
}