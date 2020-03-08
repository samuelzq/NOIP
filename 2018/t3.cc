#include <iostream>
#include <algorithm>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
#define M 505

using namespace std;
int n, m;
int a[M], wait[M], dp[M][M][M];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

	std::sort(a, a + n);

    for (int i = 1; i < n; i++)
        wait[i] = a[i] - a[i - 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            dp[n][i][j] = i * j;
	}

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            for (int k = 1; k <= i; k ++){
                if(j > wait[i])
                    dp[i][j][k] = dp[i + 1][j - wait[i]][k + 1] + k * wait[i];
                else
                    dp[i][j][k] = min(dp[i + 1][0][k + 1] + k * wait[i], dp[i + 1][max(0, j + m - wait[i])][1] + k * j);
            }
		}
	}
    cout << dp[1][0][1] << endl;
    return 0;
}
