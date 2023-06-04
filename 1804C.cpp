/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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
	int n, x, p;
	bool check;
	while(tc--) {
		check = false;
		cin >> n >> x >> p;
		if(p < 2 * n) {}
		else if(p > 2 * n) p = 2 * n + 1;

		for(int i = 1; i <= p; i++) {
			if(((x + i * (i + 1) / 2 ) % n) == 0) {
				cout << "YES" << endl; check = true; break;
			}
		}
		if(!check) cout << "NO" << endl;
	}
}