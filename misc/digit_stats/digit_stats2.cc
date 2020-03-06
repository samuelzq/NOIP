// statistics for every digits from 1 to n

#include <iostream>

using namespace std;

int main()
{
    int n, i, j, cnt[10] = {0, };

    cin >> n;
    while (n > 0) {
        i = n--;
        while (i) {
            cnt[i % 10]++;
            i /= 10;
        }
    }

    for (i = 0; i < 10; i++)
        cout << cnt[i] << '\n';

    cout << endl;
    return 0;
}
