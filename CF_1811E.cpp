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

int so4(int idx, bool restricted, int ans, vi a) {

}

void solve(int l, int r, int req) {
	if(l == r) {
		cout << l << endl;
		return;
	}
	int mid = l + r >> 1;
	vector<int> a;
	while(mid) {
		a.push_back(mid % 10);
		mid /= 10;
	}
	int k = so4(a.size(), 1, 0, a);
	
	if(k == req) {
		cout << k << endl;
		return;
	} else if(k < req) {
		solve(l, mid, req);
	} else solve(mid + 1, r, req);
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;

	while(tc--) {
		cin >> x;
		if(x == 1) {
			cout << 1;
			continue;
		} else {
			solve(x, maxn, x);
		}

	}
}