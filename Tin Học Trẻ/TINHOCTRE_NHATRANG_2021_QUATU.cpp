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
int n;
int a[1001][1001];
int c1[2010] = {}, c2[2010] = {};
int solve() {
	int maxi1 = 0, maxi2 = 0;
	pair<int, int> pnt1 = make_pair(1, 1), pnt2 = make_pair(1, 1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {			
			if((i + j) % 2 == 0) {
				if(c1[i + j - 2] + c2[i - j + n - 1] - a[i][j] > maxi1) {
					maxi1 = c1[i + j - 2] + c2[i - j + n - 1] - a[i][j];
					pnt1.fi = i; pnt1.se = j;
				}
			} else if((i + j) % 2 == 1) {
				if(c1[i + j - 2] + c2[i - j + n - 1] - a[i][j] > maxi2) {
					maxi2 = c1[i + j - 2] + c2[i - j + n - 1] - a[i][j];
					pnt2.fi = i; pnt2.se = j;
				}
			}
		}
	}
	cout << maxi1 + maxi2 << endl;	
	cout << pnt1.fi << ' ' << pnt1.se << ' ' << pnt2.fi << ' ' << pnt2.se; 
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			c1[i + j - 2] += a[i][j];
			c2[i - j + n - 1] += a[i][j];
			// if(i + j == 4) cout << c1[i + j - 2] << endl;
		}
	}
	// cout << c1[1 + 4 - 2] << endl;
	// cout << c2[2 + 2 - 2];
	solve();
}