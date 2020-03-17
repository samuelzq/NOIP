#include <iostream>

const int MAX = 1000 + 0xAC;
int code[MAX], querry[2][MAX];

using namespace std;

int main()
{
	int n, q, l;
	string c;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++)
		cin >> code[i];
	for (int i = 0; i < q; i++)
		cin >> querry[0][i] >> querry[1][i];

	for (int i = 0; i < q; i++) {
		string input = to_string(querry[1][i]);
		l = -1;
		for (int j = 0; j < n; j++) {
			bool match = true;
			c = to_string(code[j]);
			int len = c.length();
			if (querry[0][i] > len)
				continue;
			for (int k = 1; k <= querry[0][i]; k++) {
				if (c[len - k] != input[querry[0][i] - k]) {
					match = false;
					break;
				}
			}
			if (match == true) {
				if (l == -1)
					l = code[j];
				else
					l = (l < code[j]) ? l : code[j];
			}
		}
		cout << l << '\n';
	}
	cout << endl;
	return 0;
}