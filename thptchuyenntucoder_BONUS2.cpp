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

int const maxn = 1500;
int a[maxn + 10][maxn + 10];
int sqr[maxn + 10][maxn + 10];
int F[maxn + 10][maxn + 10];

int m, n, k;

int sumSqr(int i, int j) {
	return a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
}


void solve() {
	cin >> m >> n >> k;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			if(i >= k && j >= k) sqr[i][j] = sumSqr(i, j);
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}