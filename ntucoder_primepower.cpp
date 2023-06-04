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
#define mod 1000000007

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
int idx2 = -1, n;
vi p;
void solve() {
	if(n == 2) {
		cout << "1 1" << endl;
		return;
	}
	if(idx2 == -1) {
		for(int i = 1; i <= n - 1; i++) {
			if(i % 2 == 0) cout << mod - 1 << ' ';
			else cout << mod + 1 << ' ';
		}
	} else {

	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	int x;
	while(tc--) {
		cin >> n;
		idx2 = -1; p = vi();
		f(i,n) {
			cin >> x;
			if(x == 2) idx2 = i;
			p.push_back(x);
		}
		solve();
	}
}