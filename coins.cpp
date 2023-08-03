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
int cinTemp;
multiset<int> a;

void solve(int n) {
	int k = n;
	multiset<int>::iterator ptr = upper_bound(a.begin(), a.end(), k);
	ptr--;
	int d = 0;
	while(ptr != a.begin() && n > 0) {
		if(*ptr > n) {
			// while(*ptr > n) ptr--;
			ptr--;
		}
		else {
			n -= *ptr;
			d++;
			ptr--;
		}
	}
	// cout << n << endl;
	if(n == 0) {
		cout << d << endl;
		return;
	} else if(n < 0) {
		cout << -1 << endl;
	} else if(ptr == a.begin() && n == *ptr) {
		cout << d + 1 << endl;
	} else {
		cout << -1 << endl;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) {
		a.insert(cinn());
	}

	for(int i = 0; i < q; i++) {
		solve(cinn());
	}
}