#include <iostream>

using namespace std;

int main()
{
	int max, n, ans, *gift;
	
	cin >> max >> n;
	
	gift = new int[n]();
	
	cin >> gift[0];
	// insert sort is used
	for (int tmp, j, i = 1; i < n; i++) {
		j = i;
		cin >> tmp;
		for (; j > 0; j--) {
			if (tmp > gift[j - 1])
				gift[j] = gift[j - 1];
			else
				break;
		}
		gift[j] = tmp;
	}
	
	ans = 0;
	for (int i = 0, last = n - 1; i <= last; i++) {
		if (gift[i] + gift[last] < max)
			last--;
		ans++;
	}
	
	cout << ans << endl;
	return 0;
}	