//********* 2016 T2 **********

#include <iostream>
#include <string>

using namespace std;
int d[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int check_year(int year)
{
	int r = 0;
	
	if (year % 100 == 0) {
		if (year % 400 == 0)
			r = 1;
		else
			r = 0;
	} else {
		if (year % 4 == 0)
			r = 1;
	}
	return r;
}

bool check_date(int date)
{
	string s = to_string(date);
	
	if (s.size() < 8)
		return false;
	for (int i = 0; i < 4; i++) {
		if (s[i] != s[7-i])
			return false;
	}
	cout << s << '\n';
	return true;
}

int main()
{
	int date1, date2, cnt = 0;
	int year, month, day;
	
	cin >> date1 >> date2;
	year = date1 / 10000;
	day = date1 % 100;
	month = ((date1 - day) / 100) % 100;
	while (date1 <= date2) {
		int r = 0;
		if (check_date(date1))
			cnt++;
		r = check_year(year);
		if (day < d[r][month - 1]) {
			day += 1;
			date1++;
		} else {
			date1 = date1 - day + 1;
			if (month < 12) {
				month++;
				date1 += 100;
			} else {
				date1 = date1 - 100 * (month - 1);
				month = 1;
				date1 += 10000;		
				year++;		
			}
			day = 1;
		}
		//cout << date1 << '\n';
	}
	cout << cnt << endl;
	return 0;
}