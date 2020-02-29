#include <iostream>

using namespace std;

#define MIN(x, y) ((x) > (y) ? (y) : (x))
int main()
{
	int r, c, kr, kc, k, x, y, p, q;
	int *ra = NULL, *ca = NULL;
	
	cin >> r >> c >> kr >> kc >> k; 
	
	ra = new int[r]();
	ca = new int[c]();
	
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> p >> q;
		if (x == p)
			ca[MIN(y, q)]++;
		else if (y == q)
			ra[MIN(x, p)]++;
		else
			return -1;
	}

	for (int j = 0; j < kr; j++) {
		int largest = 0;
		for (int i = 0; i < r; i++) {
			if (ra[largest] < ra[i])
				largest = i;
		}
		ra[largest] = 0;
		cout << largest;
		if (j < kr - 1)
			cout << ' ';
	}
	cout << '\n';
	
	for (int j = 0; j < kc; j++) {
		int largest = 0;
		for (int i = 0; i < c; i++) {
			if (ca[largest] < ca[i])
				largest = i;
		}
		ca[largest] = 0;
		cout << largest;
		if (j <= kc - 1)
			cout << ' ';
	}
	cout << endl;
	return 0;
}