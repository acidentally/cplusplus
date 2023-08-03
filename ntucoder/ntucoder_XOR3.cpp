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
	int tc; cin >> tc;
	int n, x, ans;
	vi a;
	while(tc--) {
		cin >> n;
		a = vi(); ans = 0;
		f(i,n) {
			cin >> x;
			a.push_back(x);
		}
		for(int i = 0; i < n; i++) {
			ans ^= ((i + 1) * (n - i) % 2) * a[i];
		}
		cout << ans << endl;
	}
}