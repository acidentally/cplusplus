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
int n;
int a[51][51];
int temp = 2;
void solve(int x, int y, bool len) {
	if(x > n || y > n) return;
	if(len) {
		int d = x + y;
		while(y >= 1 && d - y <= n) {
			a[d - y][y] = temp;
			y--;
			temp++;
		}
		if(d - x + 1 > n) {solve(d - x, x + 1, false);}
		else {solve(d - x + 1, 1, false);}
	} else if(!len) {
		int d = x + y;
		while(x >= 1 && d - x <= n) {
			a[x][d - x] = temp;
			x--;
			temp++;
		}
		x++;
		// temp--;
		if(d - y + 1 > n) {solve(y + 1, d - y, true);}
		else {solve(1, d - y + 1, true);}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	a[1][1] = 1;
	a[n][n] = n * n;
	solve(2, 1, false);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[j][i] << ' ';
		}
		cout << endl;
	}
}