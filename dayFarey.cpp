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

vector< pair<int, int> > ans;
int n;

void solve(int a, int b, int c, int d) {
	if(b + d > n) {
		return;
	} else {
		solve(a, b, a + c, b + d);
		cout << a + c << '/' << b + d << endl;
		solve(a + c, b + d, c , d);
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	cout << 0 << '/' << 1 << endl;
	solve(0, 1, 1, 1);
	cout << 1 << '/' << 1;
}

