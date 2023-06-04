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

int n, x;

int gcd(int a, int b) {
	while(a && b) {
		a %= b;
		if(b) b %= a;
	}
	return ((a == 0) ? b : a);
}

void solve() {
	cin >> n;
	int x;
	vi a;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	int pre = a[n - 1] - a[0];
	for(int i = 1; i < n/2; i++) {
		pre = __gcd(pre, a[i] - a[n - 1 - i]);
	}
	cout << abs(pre) << endl;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

	int tc; cin >> tc;

	while(tc--) {	
		solve();
	}
}