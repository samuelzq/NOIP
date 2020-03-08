#include <iostream>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define M 1000005

using namespace std;

struct node{
    int l;      // idx of left node
	int r;      // idx of right node
	int v;      // value of current node
};
node a[M] = {0};
int num[M];

bool symmetry(int l, int r)
{
	if (l == -1 || r == -1) // node dose not exist
		return false;
	if (num[l] != num[r]) // both nodes do not have the same number of nodes
		return false;

	if (a[l].l == -1 && a[l].r == -1 &&
		a[r].l == -1 && a[r].r == -1 &&
		a[l].v == a[r].v)  // leaf node with same value, so they are symmetry
		return true;
	else if (a[l].l == -1 && a[r].r == -1 &&  // l node dose not have sub-l, r node dose not have sub-r
		     a[l].r != -1 && a[r].l != -1 &&  // l node has sub-r, r node has sub-l
			 a[l].v == a[r].v)                // l and r has the same value
		return symmetry(a[l].r, a[r].l);      // compare sub-r of l and sub-l of r
	else if (a[l].r == -1 && a[r].l == -1 &&  // r node dose not have sub-l, l node dose not have sub-r
			 a[l].l != -1 && a[r].r != -1 &&  // r node has sub-r, l node has sub-l
			 a[l].v == a[r].v)                // r and l has the same value
		return symmetry(a[l].l, a[r].r);      // compare sub-r of r and sub-l of l
	else if(a[l].r != -1 && a[l].l != -1 &&
			a[r].l != -1 && a[r].r != -1 &&
			a[l].v == a[r].v)
		return symmetry(a[l].l, a[r].r) && symmetry(a[l].r, a[r].l);
	else
		return false;
}

// depth-first search get nodes in a sub-tree
int get_nodes_cnt(int idx)
{
	int sub_l = 0, sub_r = 0;

	if (a[idx].l > 0)
		sub_l = get_nodes_cnt(a[idx].l);
	if (a[idx].r > 0)
		sub_r = get_nodes_cnt(a[idx].r); 
	num[idx] = 1 + sub_l + sub_r;
	return num[idx];
}

int main()
{
	int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
		cin >> a[i].v;
		num[i] = 1;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i].l >> a[i].r;
	get_nodes_cnt(0);

	for (int i = 0; i < n; i++) {
		if (num[i] > ans && symmetry(a[i].l, a[i].r))
			ans = max(ans, num[i]);
	}

	cout << ans << endl;
	return 0;
}