#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int p = 0, cnt = 0;
	string w, cache;
	
	cin >> w;
	transform(w.begin(), w.end(), w.begin(), ::toupper);
	
	while (cin >> cache) {
		transform(cache.begin(), cache.end(), cache.begin(), ::toupper);
		if (cache != w) {
			if (cnt == 0)
				p++;
		} else {
			cnt++;
		}
	}
	if (cnt == 0)
		cout << -1;
	else
		cout << cnt << ' ' << p;
	cout << endl;

	return 0;
}
	