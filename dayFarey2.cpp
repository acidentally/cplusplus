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
	int n; cin >> n;
	stack<pair<int, int> > stR;
	stR.push({1, 1});
	pair<int, int> l = {0,1}, r = {1, 1};

	cout << 0 << '/' << 1 << endl;
	while(1) {
		if(l.fi + r.fi == n - 1 && l.se + r.se == n) {
			cout << n - 1 << '/' << n << endl;
			break;
		}
		if(l.se + r.se > n) {
			cout << r.fi << '/' << r.se << endl;
			l = r;
			r = stR.top();
			stR.pop();
			continue;
		}

		else {
			stR.push(r);
			r = {l.fi + r.fi, l.se + r.se};
		}
	}
	cout << 1 << '/' << 1;
}


