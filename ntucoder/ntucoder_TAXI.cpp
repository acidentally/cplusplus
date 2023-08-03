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

int n, x, c[5] = {};
vi a;
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		c[x]++;
	}
	int ans = c[4] + min(c[3], c[1]) + c[2]/2;

	c[3] -= min(c[3], c[1]);
	c[1] -= min(c[3], c[1]);
	c[2] %= 2;
	if(c[1]) {
		ans += min(c[1]/2, c[2]);
		c[1] -= min(c[1]/2 * 2, c[2]);
		c[2] -= min(c[1]/2 * 2, c[2]);
		ans += c[2]/2 + c[2]%2;
	} else if(c[3]) ans += c[3] + 1;
	cout << ans;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}