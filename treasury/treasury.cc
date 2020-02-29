#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int find_stair(int **r, int s, int m)
{
    int i, p;

    p = r[s][1];

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
    string input, tmp;
    stringstream ss;

    getline(cin, input);
    ss << input;

    ss >> n >> m;

    a = new int **[n];
    for (i = 0; i < n; i++) {
        a[i] = new int *[m];
        for (int j = 0; j < m; j++)
            a[i][j] = new int[2];
    }

    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            getline(cin, input);
            ss << input;
            ss >> a[i][j][0] >> a[i][j][1];
        }
    }
    cin >> s;

    for (int st = s, i = 0; i < n; i++) {
        st = find_stair(a[i], st, m);
        cnt += a[i][st][1];
    }
    cout << cnt << endl;

    return 0;
}
