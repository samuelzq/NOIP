#include <iostream>
#include <algorithm>

using namespace std;

void simple_ratio(int a, int b, int l, int &c, int &d)
{
    static float min_delt;
    int r;
    float fr, tmp, delt;
    bool updated = false;

    r = a / b;
    min_delt = fr = (float)a / (float)b;

    for (int i = l; i > 0; i--) {
        updated = false;
        for (int j = l / r + 1; j > 0; j--) {
            if (__gcd(i, j) != 1)
                continue;
            tmp = (float)i / (float)j;
            delt = tmp > fr ? (tmp - fr) : (fr - tmp);
            if (delt < min_delt) {
                min_delt = delt;
                updated = true;
                c = i;
                d = j;
            } else {
                if (updated == true)
                    break;
            }
        }
    }

}

int main()
{
    int a, b, c, d, l;

    cin >> a >> b >> l;

    if (l > b || l > a)
        return -1;

    if (a > b)
        simple_ratio(a, b, l, c, d);
    else
        simple_ratio(b, a, l, d, c);
    cout << c << d << endl;

    return 0;

}
