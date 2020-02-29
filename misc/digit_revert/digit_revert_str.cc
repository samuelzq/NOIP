#include <iostream>
#include <string>

using namespace std;

int main()
{
	string d;
	int s;
	bool output = false;

	s = 1;
	cin >> d;
	if (d[0] == '-')
		cout << '-';
	else
		s = 0;

	for (int i = d.length() - 1; i >= s; i--) {
		if ((d[i] != '0') || (output != false)) {
			cout << d[i];
			output = true;
		}
	}

	return 0;
}