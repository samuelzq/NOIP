#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int main()
{
    int t, m, i, j;
    int *f, *w, *v;

    cin >> t >> m;
    f = new int[t + 1]();
    w = new int[m]();
    v = new int[m]();

    for (i = 0; i < m; i++)
        cin >> w[i] >> v[i];

    for(i = 0; i < m; i++) {
        for(j = t; j >= w[i]; j--) {
            if (w[i] <= t)
                f[j] = MAX(f[j - w[i]] + v[i], f[j]);
        }
    }
    cout << f[t] << endl;
    delete f;
    delete w;
    delete v;
    return 0; 
}