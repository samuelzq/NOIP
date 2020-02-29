#include <iostream>

using namespace std;

int64_t *eigenv;
int64_t *grade;
int64_t *num;

void cal_eigen(int n)
{
	int i, j;
	int64_t sum = 0, g = ~0, max = ~0, maxg = ~0;
	
	sum = grade[0] = eigenv[0] = num[0]; // eigemvalue for the 1st student is his number
	
	for (i = 1; i < n; i++) {
		sum = sum + num[i];
		if (sum > max)
			max = sum;
		eigenv[i] = max;
		if (sum < 0)
			sum = 0;
		if (g < grade[i - 1] + eigenv[i - 1])
			g = grade[i - 1] + eigenv[i - 1]; // grade;
		grade[i] = g;
	}
}

int main()
{
	int n, p, max;
	
	cin >> n >> p;
	eigenv = new int64_t[n]();
	grade = new int64_t[n]();
	num = new int64_t[n]();
	
	for (int i = 0; i < n; i++)
		cin >> num[i];
	
	cal_eigen(n);
	
	max = grade[0];
	for (int i = 1; i < n; i++) {
		if (max < grade[i])
			max = grade[i];
	}
	cout << max % p << endl;
	return 0;
}
	