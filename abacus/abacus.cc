#include <iostream>

using namespace std;

int main()
{
    int n, i, j, k, cnt;

    cin >> n;

    int *a = new int(n);

    for (i = 0; i < n; i++)
        cin >> a[i];

    cnt = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n && j != i; j++)
            for (k = j + 1; k < n && k != i; k++)
                if (a[i] == a[j] + a[k]) {
                    cnt++;
                    j = k = i;
                }

    cout << cnt << endl;
    delete a;
    return 0;
}
