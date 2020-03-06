#include <iostream>

using namespace std;

int main()
{
	const int run_speed = 17, magic_speed = 60;
	const int magic_res = 4, magic_consume = 10;
	int m, s, t, left, run;

	
	cin >> m >> s >> t;

	left = t - m / magic_consume;
	if (left <= 0)   // magic out
		goto success;
	
	run = m / magic_consume * magic_speed;
	while (left > magic_res + 1) {
		// magic is the 1st choice
		run *= magic_speed;
		left -= magic_res + 1;
	}
	run += left * run_speed;
	
	if (run > s)
		goto success;
	cout << "No " << run << endl;
	return 0;
	
success:
	cout << "Yes" << endl;
	return 0;
}
