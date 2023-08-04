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
int y0, x0, y, x, yHau, xHau, len = 2;
int bang[9][9] = {};
bool cheo1[15] = {}, cheo2[15] = {};
pair<int, int> trace[9][9], temp;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[8] = {1, -1, 2, -2, 2, -2, 1, -1}; 
char _u, _v, u, v;

void BFS(int i, int j) {
	queue< pair<int, int> > q;
	q.push({i, j});
	while(!q.empty()) {
		// cout << len << endl;
		len++;
		u = q.front().fi;
		v = q.front().se;
		q.pop();

		if(u == y && v == x) {
			bang[y][x] = len;
			temp = {y, x};
			while(temp.fi != y0 || temp.se != x0) {
				temp = trace[temp.fi][temp.se];
				bang[temp.fi][temp.se] = len--;
			}
			for(int k = 1; k <= 8; k++) {
				for(int l = 1; l <= 8; l++) {
					cout << bang[k][l] << ' ';
				}
				cout << endl;
			}
			return;
		}
		for(int o = 0; o < 8; o++) {
			_u = u + dy[o];
			_v = v + dx[o];
			if(_u >= 1 && _u <= 8 && _v >= 1 && _v <= 8	&& bang[_u][_v] != 1) {
				
				q.push({_u, _v});
				trace[_u][_v] = {u, v};
			}
		}
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> yHau >> xHau >> y0 >> x0 >> y >> x;
	for(int i = 1; i < 9; i++) {
		for(int j = 1; j <= 8; j++) {
			if(i - j == yHau - xHau) bang[i][j] = 1;
			if(i + j == yHau + xHau) bang[i][j] = 1;
			if(i == yHau) bang[i][j] = 1;
			if(j == xHau) bang[i][j] = 1;
		}
	}
	bang[y0][x0] = 2;
	cheo1[yHau - xHau + 7] = true;
	cheo2[yHau + xHau - 2] = true;
	BFS(y0, x0);
}