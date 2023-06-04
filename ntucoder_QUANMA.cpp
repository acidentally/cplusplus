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

int n, m, x0, y0, x, y;
int u, v, _u, _v, len = 0;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
pi trace[1002][1002];
bool vis[1002][1002] = {};


bool check(int x, int k) {
	if(x >= 1 && x <= k) return true;
	else return 0;
}

void BFS() {
	queue<pi> q;
	q.push({x0, y0});
	while(!q.empty()) {
		u = q.front().fi;
		v = q.front().se;
		q.pop();

		if(u == x && v == y) {
			_u = x; _v = y;
			while(trace[_u][_v].fi != x0 || trace[_u][_v].se != y0) {
				u = trace[_u][_v].fi;
				v = trace[_u][_v].se;
				_u = u;
				_v = v;
				len++;
			}
			cout << len + 1;
			return;
		}

		for(int i = 0; i < 8; i++) {
			_u = u + dx[i];
			_v = v + dy[i];
			if(check(_u, n) && check(_v, m) && !vis[_u][_v]) {
				q.push({_u, _v});
				vis[_u][_v] = true;
				trace[_u][_v] = {u, v};
			}
		}
	}
}


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n >> m >> x0 >> y0 >> x >> y;
	BFS();
}