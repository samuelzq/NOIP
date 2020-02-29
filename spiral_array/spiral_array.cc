#include <iostream>

using namespace std;

#define MIN(x, y) \
        ((x) < (y) ? (x) : (y))
int main()
{
    int n, q, i, j, ans, cnt;

    cin >> n >> i >> j;

    if (n < i || n < j)
        return -1;
    q = MIN(MIN(i, j), MIN(n - i + 1, n - j + 1));
    cnt = (q - 1) * (n - (q - 1)) * 4;
    if (i <= j)
        ans = cnt + i + j - 2 * q + 1;
    else
        ans = q * (n - q) * 4 - (i + j - 2 * q + 1) + 2;
    cout << ans << endl;
    return 0;
}
