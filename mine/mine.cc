#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;

unsigned int count_bomb(char **c, unsigned int i, unsigned int j)
{
    unsigned int cnt = 0;

    if (c[i - 1][j - 1] == '*')
        cnt++;
    if (c[i - 1][j] == '*')
        cnt++;
    if (c[i - 1][j + 1] == '*')
        cnt++;
    if (c[i][j - 1] == '*')
        cnt++;
    if (c[i][j + 1] == '*')
        cnt++;
    if (c[i + 1][j - 1] == '*')
        cnt++;
    if (c[i + 1][j] == '*')
        cnt++;
    if (c[i + 1][j + 1] == '*')
        cnt++;
    cout << cnt;
    return cnt;
}

int main()
{
    unsigned int m, n, j, i, cnt;
    char **c;
    string input;
    stringstream ss;

    scanf("%d%d\n", &m, &n);
    c = new char*[m + 2];
    for (i = 0; i < n + 2; i++) {
        c[i] = new char[m + 2];
        memset(c[i], 0, (m + 2));
    }

    for (i = 1; i < m + 1; i++) {
        getline(cin, input);
        stringstream ss(input);
        for (j = 1; j < n + 1; j++) {
            ss >> c[i][j];
        }
    }

    cnt = 0;
    for (i = 1; i < m + 1; i++) {
        for (j = 1; j < n + 1; j++) {
            if (c[i][j] == '*')
                cout << '*';
            else
                cnt += count_bomb(c, i, j);
            cout << ' ';
        }
        cout << '\n';
    }
    cout << cnt << endl;
    return 0;
}
