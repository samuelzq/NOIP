#include <iostream>

using namespace std;

int main()
{
	int n, i;
	long long m, p1, s1, s2, p2, dragon, tiger, diff;
	long long *soldier, *power;

	cin >> n;
	soldier = new long long[n]();
	power = new long long[n]();

	for (i = 0; i < n; i++)
		cin >> soldier[i];
	cin >> m >> p1 >> s1 >> s2;

	m--;
	for (i = 0, dragon = 0; i < m; i++)
		dragon += soldier[i] * (m - i);
	for (i = m + 1, tiger = 0; i < n; i++)
		tiger += soldier[i] * (i - m);
	p1--;
	if (p1 < m)
		dragon += s1 * (m - p1);
	if (p1 > m)
		tiger += s1 * (p1 - m);

	if (dragon > tiger) {
		long tmp = 0;
		tmp = diff = dragon - tiger;
		for (p2 = m + 1; p2 < n; p2++) {
			if (diff <= ((p2 - m) * s2))
				break;
		}
	} else if (dragon < tiger) {
		long tmp = 0;
		tmp = diff = tiger - dragon;
		for (p2 = m - 1; p2 >= 0; p2--) {
			if (diff <= (m - p2) * s2)
				break;
		}
		if (p2 < 0)
			p2 = 0;
	} else {
		p2 = m;
	}
	cout << p2 + 1 << endl;
	return 0;
}