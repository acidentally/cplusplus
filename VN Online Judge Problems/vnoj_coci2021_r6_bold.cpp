/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int n, m;
bool ans[101][101];
char x;
void pre(int u, int v) {
	ans[u][v] = 1;
	ans[u + 1][v] = 1;
	ans[u][v + 1] = 1;
	ans[u + 1][v + 1] = 1;
}
void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> x;
			if(x == '#') pre(i, j);
		}
	}	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << ((ans[i][j]) ? '#' : '.');
		}
		cout << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}