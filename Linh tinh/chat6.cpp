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
	int tc, n; cin >> tc;
	string s;
	while(tc--) {
		cin >> n;
		int res = 0;
		string a[2];
		for(int i = 0; i < 2*n - 2; i++) {
			cin >> s;
			if(s.size() == n - 1) {
				a[res] = s;
				res++;
			}
		}
		// cout << "NO";
		string x = a[0], y = a[1];
		if(x[0] != y[n - 2]) {
			cout << "NO" << endl;
			continue;
		} else {
			string xtemp;
			for(int i = x.size() - 1; i > 0; i--) {
				xtemp += x[i];
			}
			y.erase(y.size() - 1, 1);
			if(xtemp == y) {
				cout << "YES" << endl; 
				continue;
			} else {
				cout << "NO" << endl;
				continue;
			}
		}
		// cout << "YES" << endl;
	}
}