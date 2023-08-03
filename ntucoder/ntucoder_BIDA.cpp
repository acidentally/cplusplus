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
	int n, m, y, x, k;
	cin >> n >> m >> y >> x >> k;
	int ytemp = k % (2 * n - 2);
	int xtemp = k % (2 * m - 2);
	y += ytemp;
	x += xtemp;
	if(x > m) x = 2 * m - x;
	if(y > n) y = 2 * n - y;
	if(x < 1) x = 2- x;
	if(y < 1) y = 2 - y;
	cout << y << ' ' << x;
}

// 1 2 3 4