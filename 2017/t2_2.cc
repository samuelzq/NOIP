#include <iostream>

const int MAX = 1000 + 0xAC;
int code[MAX], querry[MAX][2];

using namespace std;

int pow10(int n)
{
	int p = 1, i;
	for (i = 0; i < n; i++)
		p *= 10;
	return p;
}	

int main()
{	int n, q, l;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++)
		cin >> code[i];
	for (int i = 0; i < q; i++)
		cin >> querry[i][0] >> querry[i][1];
	
	for (int i = 0; i < q; i++) {
		int t = 0;
		l = -1;
		for (int j = 0; j < n && code[j] >= querry[i][1]; j++) {
			t = code[j] - querry[i][1];
			if (t % pow10(querry[i][0]) == 0) {
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