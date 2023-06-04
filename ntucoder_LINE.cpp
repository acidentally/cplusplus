#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

bool a[31][31];
deque< pair<char, char> > q;
char dx[4] = {0, 0, 1, -1};
char dy[4] = {1, -1, 0, 0};
int y, x, _y, _x, n;
pair<char, char> trace[31][31] = {}, temp;
char len = 2;
char _u, _v, u, v, k;

void BFS(char i, char j) {
	q.push_back({i, j});
	while(!q.empty()) {
		u = q.front().fi, v = q.front().se;
		q.pop_front();
		// cout << (int)u << ' ' << (int)v << endl;
		if(u == y && v == x) {
			q = deque<pair<char,char> >();
			temp = trace[y][x];
			while(temp.fi != _y || temp.se != _x) {
				len++;
				q.push_back(temp);
				temp = trace[temp.fi][temp.se];
			}
			cout << (int)len << endl << (int)_y << ' ' << (int)_x << endl;

 			while(!q.empty()) {
				cout << (int)q.back().fi << ' ' << (int)q.back().se << endl;
				q.pop_back();
			}

			cout << y << ' ' << x;
			break;
		}
		// cout << a[4][4] << endl;
		a[u][v] = true;

		for(k = 0; k < 4; k++) {
			_u = u + dy[k];
			_v = v + dx[k];
			if(_u >= 1 && _u <= n && _v >= 1 && _v <= n && !a[_u][_v]) {
				// cout << (int)_u << ' ' << (int)_v << endl;
				trace[_u][_v] = {u, v};
				a[_u][_v] = 1;
				q.push_back({_u, _v});	
			}
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	cin >> _y >> _x;
	cin >> y >> x;
	for(char i = 1; i <= n; i++) {
		for(char j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	BFS(_y, _x);
}
