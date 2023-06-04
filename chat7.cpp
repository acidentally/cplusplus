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
#define vpi vector< pair<int, int> >


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

int t; 
int solve(vpi& a, vpi& b, int l, int r) {
	if(l == r) return l;

	int mid = (l + r)/2;
	int btime = t - mid, aVal = 0, bVal = 0;

	for(int i = 0; i < a.size(); i++) {
		aVal += max(0ll, mid - a[i].fi);
		if(mid - a[i].fi > 0) aVal += (mid - a[i].fi) / a[i].se; 
	}

	for(int i = 0; i < b.size(); i++) {
		bVal += max(0ll, btime - b[i].fi);
		if(btime - b[i].fi > 0) bVal += (btime - b[i].fi) / b[i].se;
	}

	if(aVal == bVal) return mid;
	else if(aVal > bVal) {
		return solve(a, b, l, mid);
	}
	else return solve(a, b, mid + 1, r);

}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> t;
	int a, b;
	vpi a1, a2;

	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		a1.push_back({a, b});
	}

	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		a2.push_back({a, b});
	}

	cout << solve(a1, a2, 1, t);

}