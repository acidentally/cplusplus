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

map<int, int> a;
int cinTemp;
void solve(int n) {
	map<int, int>::iterator ptr = a.end(); ptr--;
	int d = 0, k;
	while(n > 0 && ptr -> fi != 0) {
		k = min(n / ptr -> fi, ptr -> se);
		n -= (ptr -> fi) * k;
		d += k;
		ptr--;
	}
	if(n == 0) {
		cout << d << endl;
		return;
	} else cout << -1 << endl;

}


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, q; cin >> n >> q;
	a[0] = 0;
	for(int i = 0; i < 32; i++) {
		a[1 << (unsigned long long)i] = 0;
	}
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a[cinTemp]++;
	}

	for(int i = 0; i < q; i++) {
		solve(cinn());
	}
	// cout << (1ull << 31ull);
	// cout << (1 << 0);
}