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
	int n, m; cin >> n >> m;
	vi a; int cinTemp;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
	}
	int d, cnt, mini;
	int l = 0, r = (int)1e9, mid;
	while(l < r) {
		mid = (l + r)/2;
		// cout << mid << ' ';
		d = 0; cnt = 1;
		mini = 0;
		for(int i = 0; i < n; i++) {
			if(d + a[i] > mid) {
				cnt++;
				mini = max(mini, d);
				d = a[i];
			}
			else d += a[i];
		}
		if(cnt > m) {
			l = mid + 1;
		} else if(cnt <= m) {
			r = mid;
		}
	}
	cout << mini;
}