// ********* T4 *************

#include <iostream>

using namespace std;
inline bool check(float Xa, float Xb, float Xc, float Xd)
{
	if ((Xa < Xb) && (Xb < Xc) && (Xc < Xd))
		return ((Xb - Xa) == 2 * (Xd - Xc)) && ((Xb - Xa) < (Xc - Xb) / 3);
	else
		return false;
}

const int maxim = 40000 + 0xac;
int ans[maxim][4] = {0};
int m[maxim];

int main()
{
	int n, g, i, a, b, c, d, s;
	int t[4]; // every combination sorted from smallest to biggest in this array

	cin >> g >> n;
	for (i = 0; i < n; i++)
		cin >> m[i];

	for (i = 0; i < n - 3; i++) {
		a = m[i];
		for (int j = i + 1; j < n - 2; j++) {
			t[0] = a;
			b = m[j];
			if (b > a) {
				t[1] = b;
			} else {
				t[1] = t[0];
				t[0] = b;
			}
			for (int k = j + 1; k < n - 1; k++) {
				c = m[k];
				for (s = 2; s > 0; s--) {
					if (t[s - 1] > c)
						t[s] = t[s - 1];
					else
						break;
				}
				t[s] = c;
				for (int l = k + 1; l < n; l++) {
					d = m[l];
					for (s = 3; s > 0; s--) {
						if (t[s - 1] > d)
							t[s] = t[s - 1];
						else
							break;
					}
					t[s] = d;

					if (check(t[0], t[1], t[2], t[3])) {
						ans[t[0] - 1][0]++;
						ans[t[1] - 1][1]++;
						ans[t[2] - 1][2]++;
						ans[t[3] - 1][3]++;
					}
				}
			}
		}
	}
	for (i = 0; i < n; i++)
		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << '\n';
	return 0;
}