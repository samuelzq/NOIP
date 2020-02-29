#include <iostream>

using namespace std;

int main()
{
    unsigned int l, r, d, tmp, cnt;

    cin >> l >> r >> d;

    if ((l > r) || (d > 9))
        return -1;
    cnt = 0;
    tmp = l;
    while (tmp <= r) {
        if (tmp % 10 == d)
            cnt++;
        tmp = tmp / 10;
        if (tmp == 0)
            tmp = ++l;
    }
    cout << cnt;
    return 0;
}
