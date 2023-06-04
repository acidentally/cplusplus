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

char a[1010][1010];
bool luu[1010][1010] = {};

int cinn() {
	int n; cin >> n;
	return n;
}

deque< pair<int, int> > queque;
int m, n;
bool check = false;
void DFS(int x, int y) {
	// cout << x << y;
	// cout << queque.begin() -> fi;
	queque.push_back({x, y});

	if(a[x][y] == 'X' || luu[x][y]) return;
	luu[x][y] = true;
	if((x == 1 || x == n || y == 1 || y == m) && !check) {
		deque< pair<int, int> >::iterator ptr;
		for(ptr = queque.begin(); ptr != queque.end(); ptr++) {
			cout << ptr -> fi << ' ' << ptr -> se << endl;
		}
		check = true;
		return;
	} else if(!check) {
		DFS(x - 1, y);
		queque.pop_back();
		DFS(x + 1, y);
		queque.pop_back();
		DFS(x, y - 1);
		queque.pop_back();
		DFS(x, y + 1);
		queque.pop_back();
	}
	luu[x][y] = false;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

	pair<int, int> luu1 = {-1, -1};
	cin >> m >> n;

	for(int i = 1; i <= n ; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'E') {
				luu1.fi = i;
				luu1.se = j;
			}
		}
	}
	// cout << a[1][3];
	// cout << luu1.fi << ' ' << luu1.se;
	DFS(luu1.fi, luu1.se);
	if(!check) cout << -1;

}