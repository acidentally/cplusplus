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

int check(int a, int b, int c, int x, int y) {
	return a * x + b * y + c;
}

void gpt(int x1, int y1, int x2, int y2, int x3, int y3) {
	cout << "NO" << endl;
}

void solve(vector< pair<int, int> > coords) {

	int a = coords[2].se - coords[3].se;
	int b = coords[3].fi - coords[2].fi;
	int c = - coords[2].fi * (coords[2].se - coords[3].se) - coords[2].se * (coords[3].fi - coords[2].fi);

	if(check(a, b, c, coords[0].fi, coords[0].se) * check(a, b, c, coords[1].fi, coords[1].se) > 0) {
		cout << "NO" << endl;
		return;
	} else {
		if(check(a, b, c, coords[0].fi, coords[0].se) == 0 && (coords[0].fi >= min(coords[2].fi, coords[3].fi) && coords[0].fi <= max(coords[2].fi, coords[3].fi))) {
			cout << "YES" << endl;
			return;
		}
		else if(check(a, b, c, coords[1].fi, coords[1].se) == 0 && (coords[1].fi >= min(coords[2].fi, coords[3].fi) && coords[1].fi <= max(coords[2].fi, coords[3].fi))) {
			cout << "YES" << endl;
			return;
		} else if(check(a, b, c, coords[0].fi, coords[0].se) * check(a, b, c, coords[1].fi, coords[1].se) < 0) {
			if()
			gpt(coords[1].fi - coords[0].fi, coords[1].se - coords[0].se, coords[2].fi - coords[0].fi, coords[2].se - coords[0].se, coords[3].fi - coords[0].fi, coords[3].se - coords[0].se);
			return;

		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	vector<pair<int, int> > coords(4, {0, 0});
	while(tc--) {
		for(int i = 0; i < 4; i++) {
			cin >> coords[i].fi >> coords[i].se;
		}
		solve(coords);
	}
}