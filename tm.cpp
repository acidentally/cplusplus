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
	int n; cin >> n;
	int t[n + 1], r[n + 2];
	fr(i,1,n + 1) {
		cin >> t[i];
	}
	fr(i,1,n) {
		cin >> r[i];
	}
	r[n] = t[n];
	r[n + 1] = 0;
	for(int i = n - 1; i >= 1; i--) {
		r[i] = min(r[i] + r[i + 2], t[i] + r[i + 1]);
	}
	cout << r[1];
	//t1 t2 t3 t4 t5
	//r1 r2 r3 r4 t5 0
}