// ********************** T3 ************************
// Data structure for nationality is as this:
// +------+                  +------+
// | Head |                  | Tail |
// +--+---+                  +--+---+
//    |                         |
// +--v-----+  +--------+  +----v---+
// |People0 |-->People1 |-->People2 |
// +--------+  +--------+  +--------+

#include <iostream>

#define MAX (100000 + 0xAC)
using namespace std;

struct people {
	struct people *next;
	int t; // arrive time
	int n; // nationality
} p[3 * MAX];

int na_id[MAX] = {0}; // nationality on one ship
const int T = 86400;

int main()
{
	int n, i, t, ans = 0;
	struct people *pHead, *pTail;
	pHead = pTail = &p[0];

	cin >> n;
	for (i = 0; i < n; i++) {
		int k, num = 0;
		cin >> t >> k;
		for (int j = 0; j < k; j++) {
			int kj = 0;
			pTail->t = t;
			cin >> kj;
			pTail->n = kj;
			if (na_id[kj] == 0)
				ans++;
			na_id[kj] += 1;
			pTail = pTail->next = &p[i + 1];
		}

		while (t - pHead->t >= T) {
			int n = pHead->n;
			if (na_id[n] != 0)
				na_id[n]--;
			if (na_id[n] == 0)
				ans--;
			pHead = pHead->next;
		}
		cout << ans << '\n';
	}

	return 0;
}


