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

int n, m, x;
bool F[50][50] = {};
vi a;
void solve() {
	a.push_back(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		a.push_back(x);
	}
	for(int j = 1; j <= n; j++) {
		for(int i = 1; i <= a[j]; i++) {
			F[i][j] = 1;
		}
	}
	for(int j = m; j >= 1; j--) {
		for(int i = 1; i <= n; i++) {
			if(F[j][i]) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();

}