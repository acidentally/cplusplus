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
int n, m;
void solve(int a, int b) {
	map<int, int> v2i, i2v;
	pair<int, int> in;
	cin >> cinTemp; in.fi = cinTemp;

	for(int i = 0; i < a - 1; i++) {
		cin >> cinTemp;
		in.se = cinTemp;
		v2i[in.se - in.fi] = i;
		i2v[i] = in.se - in.fi;
		in.fi = cinTemp;	
	}
	int temp, insVal, times = n - m;
	while(time--) {
		temp = v2i.begin() -> fi;
		
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;

	while(tc--) {
		cin >> n >> m;
		solve(n, m);
	}
}