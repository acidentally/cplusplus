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
int const maxn = 10010;
int a[maxn][4];
bool b[7][4] = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {1,0,1,0}, {1,0,0,1}, {0,1,0,1}};
map<int, vector<int> > mapp;
int maxi[7] = {};
int maxTemp[7] = {};

void khoitao() {
	mapp[0] = {1, 2, 3, 6};
	mapp[1] = {0, 2, 3, 4, 5};
	mapp[2] = {0, 1, 3, 5, 6};
	mapp[3] = {0, 1, 2, 4};
	mapp[4] = {1, 3, 6};
	mapp[5] = {1, 2};
	mapp[6] = {0, 2, 4};
}
int countCol(int idx, int style) {
	int ans = 0;
	for(int i = 0; i < 4; i++) {
		if(b[style][i]) ans += a[idx][i];
	}
	return ans;
}

int countPre(int idx, vector<int> styles) {
	int ans = 0;
	for(int i = 0; i < styles.size(); i++) {
		ans = max(ans, maxTemp[styles[i]]);
	}
	return ans;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> a[i][j];
			if(a[i][j] < 0) a[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int i = 0; i < 7; i++) {
			maxTemp[i] = maxi[i];
		}
		if(i == 0) {
			for(int style = 0; style < 7; style++) {
				maxi[style] = countCol(i, style);
			}
			continue;
		}
		else {
			for(int style = 0; style < 7; style++) {
				maxi[style] = countCol(i, style) + countPre(i - 1, mapp[style]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 7; i++) {
		ans = max(ans, maxi[i]);
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	khoitao();
	solve();
}