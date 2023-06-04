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
int n, k, maxi = 0;
int a[(int)1e5 + 10];
int cinn() {
	int n; cin >> n;
	return n;
}
int mid, d;
int solve() {
	int l = 0, r = maxi;
	while(r - l > 1) {
		mid = (l + r)/2;
		d = 0;
		for(int i = 0; i < n; i++) {
			d += a[i]/mid;
		}
		// cout << l << ' ' << r << ' ' << mid << ' ' << d << endl;
		if(d == k) {
			l = mid;
		}
		else if(d > k) {
			l = mid + 1;
		} else r = mid;
	}
	cout << l;
	
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n >> k;
	fr(i,0,n) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}
	sort(a, a + n);
	solve();
}