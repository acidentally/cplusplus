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

int n, m, f; 
int cinTemp;
vvi H;
vi vecTemp;
vector< vector<bool> > check;
vector<bool> temp;
int temptemp;
int ans;
void solve(int i, int j, int t, int maxn) {
	if(t == 0) {
		temptemp = min(temptemp, maxn);
		return;
	}
	if(i > 0 && !check[i - 1][j]) {
		check[i - 1][j] = true;
		solve(i - 1, j, t - 1, max(maxn, abs(H[i][j] - H[i - 1][j])));
		check[i - 1][j] = false;
	}
	if(i < n - 1 && !check[i + 1][j]) {
		check[i + 1][j] = true;
		solve(i + 1, j, t - 1, max(maxn, abs(H[i + 1][j] - H[i][j])));
		check[i + 1][j] = false;
	}
	if(j > 0 && !check[i][j - 1]) {
		check[i][j - 1] = true;
		solve(i, j - 1, t - 1, max(maxn, abs(H[i][j - 1] - H[i][j])));
		check[i][j - 1] = false;
	}
	if(j < n - 1 && !check[i][j + 1]) {
		check[i][j + 1] = true;
		solve(i, j + 1, t - 1, max(maxn, abs(H[i][j + 1] - H[i][j])));
		check[i][j + 1] = false;
	} 
	if(t == f) ans += temptemp;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n >> m >> f;

	for(int i = 0; i < n; i++) {
		vecTemp = vi();
		for(int j = 0; j < m; j++) {
			vecTemp.push_back(cinn());
			if(i == 0) temp.push_back(false);
		}
		check.push_back(temp);
		H.push_back(vecTemp);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> cinTemp;
			if(cinTemp == 1) {
				for(int o = 0; o < n; o++) {
					for(int u = 0; u < m; u++) {
						check[o][u] = false;
					}
				}
				temptemp = (int)1e9 + 2;
				solve(i, j, f, 0);
			}
		}
	}
	cout << ans;
}