#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, i, j, cnt;
    int *a;
    map<int, int> sum;

    cin >> n;
    a = new int(n);

    for (i = 0; i < n; i++) {
        cin >> a[i];
        sum[a[i]] = i;
    }

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {
            auto itr = sum.find(a[i] + a[j]);
            if ((itr != sum.end()) && (itr->second != ~0)) {
                cnt++;
                itr->second = ~0;
            }
        }

    cout << cnt << endl;
    return 0;
}
