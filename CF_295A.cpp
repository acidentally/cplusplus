/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

int cinn() {
	int n; cin >> n;
	return n;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, m, k, x; cin >> n >> m >> k;
	vi a; a.push_back(0);
	for(int i = 0; i < n; i++) {
		a.push_back(cinn());
	}

	vector<vi> operations;
	operations.push_back({0});
	vi tempOp;

	for(int i = 0; i < m; i++) {
		tempOp = vi();
		for(int j = 0; j < 3; j++) {
			tempOp.push_back(cinn());
		}
		operations.push_back(tempOp);
	}

	int countOp[m + 1] = {}, d = 0, l, r;
	for(int i = 0; i < k; i++) {
		cin >> l >> r;
		countOp[l]++;
		if(r < m) countOp[r + 1]--;
	}
	int countOp2[m + 1] = {};
	for(int i = 1; i <= m; i++) {
		d += countOp[i];
		countOp2[i] = d;
	}
	int countArr[n + 1] = {};
	for(int i = 1; i <= m; i++) {
		countArr[operations[i][0]] += countOp2[i] * operations[i][2];
		countArr[operations[i][1] + 1] -= countOp2[i] * operations[i][2];
	}
	d = 0;
	for(int i = 1; i <= n; i++) {
		d += countArr[i];
		cout << a[i] + d << ' ';
	}
}