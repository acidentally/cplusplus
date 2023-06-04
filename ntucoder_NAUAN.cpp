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
	map<int, int> mapp;
	int n, x; cin >> n;
	int presum = 0;
	vi a;
	for(int i = 0; i < n; i++) {
		cin >> x;
		presum += x;
		mapp[presum] = i + 1; 
		a.push_back(presum);
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> x;
		cout << mapp[*lower_bound(a.begin(), a.end(), x)] << ' ';
	}
}