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
#define pi pair<int, int>

int cinn() {
	int n; cin >> n;
	return n;
}

bool vis[9][9];
pi trace[9][9]; 
int a[9][9] = {};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int x0, y0, x, y; 
bool check(int k) {
	if(k >= 1 && k <= 8) return true;
	else return 0;
}
void BFS() {
	queue<pi> q;
	int u, v, _u, _v, len = 3;
	q.push({y0, x0});
	while(!q.empty()) {
		u = q.front().fi;
		v = q.front().se;
		q.pop(); 

		if(u == y && v == x) {
			while(u != y0 && v != x0) {
				a[u][v] = len;
				len++;
				_u = u; _v = v;
				u = trace[_u][_v].fi;
				v = trace[_u][_v].se;
			}
			for(int i = 1; i <= 8; i++) {
				for(int j = 1; j <= 8; j++) {
					if(a[i][j] <= 2) cout << a[i][j];
					else cout << len + 2 - a[i][j];
					cout << ' ';
				}
				cout << endl;
			}
			break;
		}
		for(int i = 0; i < 8; i++) {
			_u = u + dy[i];
			_v = v + dx[i];
			if(check(_u) && check(_v) && a[_u][_v] == 0 && !vis[_u][_v]) {
				vis[_u][_v] = true;
				q.push({_u, _v});
				trace[_u][_v] = {u, v};
			}
		}
	}
}


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int xHau, yHau; cin >> yHau >> xHau;
	for(int i = 1; i <= 8; i++) {
		for(int j = 1; j <= 8; j++) {
			if(i == yHau || j == xHau || i + j == xHau + yHau || i - j == yHau - xHau) {
				a[i][j] = 1;
			}
		}
	}
	cin >> y0 >> x0 >> y >> x;
	a[y0][x0] = 2;
	BFS();
}