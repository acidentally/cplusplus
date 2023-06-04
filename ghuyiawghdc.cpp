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
	int n, k, x; cin >> n >> k;
	map<int, bool> mapp;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		mapp[x] = true;
	}
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(mapp[x]) ans += ((x > 0) ? x : -x);
	}
	if(ans >= k) cout << "WIN";
	else cout << "NO";
}