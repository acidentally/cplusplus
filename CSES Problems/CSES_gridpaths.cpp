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
int ans = 0;
bool vis[9][9] = {};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
string s;

bool check(int i, int j) {
	if(i >= 1 && i <= 7 && j >= 1 && j <= 7) return 1;
	return 0;
}
void DFS(int i, int j, int idx) {
	if(!check(i, j) || vis[i][j]) return;
	vis[i][j] = true;
	if(i == 7 && j == 1 && idx == 49) {
		ans++;
		return;
	}
	switch(s[idx]) {
		case 'D': {
			DFS(i + 1, j, idx + 1);
		}
		case 'U': {
			DFS(i - 1, j, idx + 1);
		}
		case 'L': {
			DFS(i, j - 1, idx + 1);
		}
		case 'R': {
			DFS(i, j + 1, idx + 1);
		}
		case '?': {
			for(int k = 0; k < 4; k++) {
				DFS(i + dy[k], j + dx[k], idx + 1);
			}
		}
	}
	vis[i][j] = false;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> s;
	// vis[1][1] = true;
	DFS(1, 1, 0);
	cout << ans;
}