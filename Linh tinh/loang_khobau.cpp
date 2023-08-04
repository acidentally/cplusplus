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
int a[4][4];
int ans = 0, premax = 9, u, v, _u, _v;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
bool vis[4][4] = {};
int t1, t2;

void solve(int k) {
	if(k > 9) {
		ans = max(premax, ans);
		return;
	}

	bool check = false;
	for(int o = 0; o < 4; o++) {
		int i = dx[o], j = dy[o];
		t1 = u + i; t2 = v + j;

		if(t1 >= 1 && t1 <= 3 && t2 >= 1 && t2 <= 3 && !vis[t1][t2]) {
			check = true;
			cout << t1 << ' ' << t2 << endl;
		
			vis[t1][t2] = true;
			u += i; v += j;
			premax = premax * 10 + a[t1][t2];
		
			solve(k + 1);

			premax /= 10; 
			u -= i; v -= j;
			vis[t1][t2] = false;
		}
	}
	if(!check) {
		vis[u][v] = false;
		return;
	}

}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		premax = 9;
		ans = 0;
		for(int i = 1; i <= 3; i++) {
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if(a[i][j] == 9) {
					u = i;
					v = j;
					t1 = u; t2 = v;
					vis[t1][t2] = true;
				}
			}
		}
		solve(2);
		cout << ans << endl;
	}
}