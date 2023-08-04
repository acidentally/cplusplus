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

int const mod = 2013;

int n;
void solve() {
	cin >> n;
	int u = n + 1;
	int v = u + n;
	if(!(n % 3)) n /= 3;
	else if(!(u % 3)) u /= 3;
	else v /= 3;

	if(!(n % 2)) n /= 2;
	else if(!(u % 2)) u /= 2;
	else v /= 2;
	cout << (((n % mod) * (u % mod)) * (v % mod)) % mod << endl;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc = 10;
	while(tc--) {
		solve();
	}
}