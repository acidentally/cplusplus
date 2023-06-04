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
	int n, s, x; cin >> n >> s;
	map<int, int> mapp;
	int halfS = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		mapp[x]++;
		mapp[s - x] = max(0ll, mapp[s - x]);
		if(2 * x == s) halfS++;
	}
	int ans = 0;
	map<int, int>::iterator ptr = mapp.begin();
	while(ptr != mapp.end()) {
		if(2 * ptr -> fi != s) ans += (ptr -> se) * (mapp[s - ptr->fi]);
		ptr++;
	}
	cout << ans / 2 + halfS * (halfS - 1) / 2;
}