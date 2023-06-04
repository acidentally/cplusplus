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
	int n, x; cin >> n;
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> x;
		m[x]++;
	}
	int ans = 0;
	map<int, int>::iterator ptr = m.begin();
	while(ptr != m.end()) {
		ans += (ptr -> se) * (ptr -> se - 1) / 2;
		ptr++;
	}
	cout << ans;
}