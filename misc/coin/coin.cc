#include <iostream>

using namespace std;

int main()
{
    int k, i, j = 1, cnt = 0;

    cin >> k;

    while (k >= j) {
        for (i = 0; i < j; i++) {
            cnt += j;
        }
        k -= j;
        j++;
    }

    for (i = 0; i < k; i++)
        cnt += j;

    cout << cnt << endl;

    return 0;
}
