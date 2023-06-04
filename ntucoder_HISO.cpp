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
int cinTemp, n;
vi a, b;
void solve() {
	b[n - 1] = a[n - 1];
	b[n - 2] = a[n - 1];
	int maxi = b[n - 2] - a[n - 2];
	for (int i = a.size() - 2; i >= 0; i--) {
		b[i] = max(a[i], b[i + 1]);
		maxi = max(maxi, b[i] - a[i]);
	}
	cout << maxi;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
		b.push_back(cinTemp);
	}
	solve();
}
