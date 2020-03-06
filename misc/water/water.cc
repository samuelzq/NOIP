#include <iostream>

using namespace std;

int find_largest(int *a, int cnt)
{
	int largest = a[0];
	for (int i = 1; i < cnt; i++) {
		if (largest < a[i])
			largest = a[i];
	}
	return largest;
}

bool replace(int *a, int cnt, int &n)
{
	for (int i = 0; i < cnt; i++) {
		if (--a[i] == 0) {
			n = i;
			return true;
		}
	}
	return false;
}

int main()
{
	bool r = false;
	int n, m, t, i, l, c;
	int *a = NULL, *w = NULL;
	cin >> n >> m;
	
	a = new int[m];
	t = (n > m) ? m : n;
	for (i = 0; i < t; i++)
		cin >> a[i];
	if (n > m) {
		w = new int[n - m];
		for (i = 0; i < n - m; i++)
			cin >> w[i];
		l = n - m;
	}
	
	if (w == NULL) {
		cout << find_largest(a, n);
		return 0;
	}
	
	t = 0;
	while (l--) {
		do {
			r = replace(a, m, c);
			t++;
		} while (r == false);
		a[c] = w[l];
	}	
	t += find_largest(a, m);
	cout << t << endl;
	return 0;
}