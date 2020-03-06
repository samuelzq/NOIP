#include <iostream>

using namespace std;

int main()
{
	int d, r;
	bool valid = false;
	cin >> d;

	if (d < 0) {
		cout << '-';
		d *= -1;
	}
	if (d == 0) {
		cout << d << endl;
		return 0;
	}

	while (d) {
		r = d % 10;
		if (r || valid) {
			cout << r;
			valid = true;
		}
		d /= 10;
	}
	cout << endl;
	return 0;
}