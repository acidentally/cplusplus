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
#define mod 998244353

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

void solve(int l, int r) {
	int fi = 0, temp = l;
	while(temp <= r) {
		fi++;
		temp *= 2;
	}
	cout << fi << ' ';
	int mul = (1 << (fi - 1));
	int se = r/mul - l + 1;
	// cout << se << endl;
	mul /= 2;
	r /= 3;
	if(mul == 0) cout << se << endl;
	else {
		cout << se % mod + (max(0ll, r/mul - l + 1) % mod) * ((fi - 1) % mod) << endl;

	}

}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	int l, r;
	while(tc--) {
		cin >> l >> r;
		solve(l, r);
	}
}