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

#define pi pair<int, int>


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int n, m, x, y, ans = 1;
int a[101][101] = {};
bool vis[101][101] = {};
int u, v, _u, _v;

bool check(int i, int j) {
	if(i >= 1 && i <= n && j >= 1 && j <= m) return true;
	return 0;
}

void BFS() {
	queue<pi> q;
	q.push({y, x});
	while(!q.empty()) {
		u = q.front().fi;
		v = q.front().se;
		q.pop();

		for(int i = 0; i < 4; i++) {
			_u = u + dy[i];
			_v = v + dx[i];
			if(check(_u, _v) && !vis[_u][_v] && !a[_u][_v]) {
				vis[_u][_v] = true;
				ans++;
				q.push({_u, _v});
			}
		}
	}
	cout << ans;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n >> m >> y >> x;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	vis[y][x] = 1;
	BFS();
}