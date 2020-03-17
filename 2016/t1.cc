//********** T1 **********

#include <iostream>

using namespace std;

#define MIN(x, y) ((x) > (y) ? (y) : (x))
int main()
{
	int n, i;
	int a[3][2];
	unsigned int cost = ~0;
	
	cin >> n;
	for (i = 0; i < 3; i++) {
		cin >> a[i][0] >> a[i][1];
		cost = MIN((n / a[i][0] + 1) * a[i][1], cost);
	}
	cout << cost << endl;
	return 0;
}