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
int mini[3010][3010] = {};
bool a[3010][3010] = {};
void check(int u, int v) {
	mini[u][v] = 3001;
	int k = u - 1;
	int cur = 0;
	while(k >= 1 && a[k][v]) {
		cur++;
		k--;
	}
	mini[u][v] = min(mini[u][v], cur);
	cur = 0;
	k = u + 1;
	while(k <= n && a[k][v]) {
		cur++;
		k++;
	} 
	mini[u][v] = min(mini[u][v], cur);
	cur = 0;
	k = v - 1;
	while(k >= 1 && a[u][k]) {
		cur++;
		k--;
	} 
	mini[u][v] = min(mini[u][v], cur);
	cur = 0;
	k = v + 1;
	while(k <= m && a[u][k]) {
		cur++;
		k++;
	}
	mini[u][v] = min(mini[u][v], cur);
}
int couting = 0;
void dp(int u, int v) {
	int k = u + 1, cur = mini[u][v];
	// cout << cur << endl;
	int idx = 1;
	while(k <= n && a[k][v] && mini[k][v] - idx > 0) {
		cur = min(cur, mini[k][v]);
		// cout << cur << endl;
		idx++;
		k++;
	}
	k = u - 1;
	idx = 1;
	while(k >= 1 && a[k][v] && mini[k][v] - idx > 0) {
		cur = min(cur, mini[k][v]);
		idx++;
		k--;
	} 
	k = v + 1;
	idx = 1;
	while(k <= m && a[u][k] && mini[u][k] - idx > 0) {
		cur = min(cur, mini[u][k]);
		idx++;
		k++;
	} 
	k = v - 1;
	idx = 1;
	while(k >= 1 && a[u][k] && mini[u][k] - idx > 0) {
		cur = min(cur, mini[k][v]);
		idx++;
		k--;
	} 
	couting += cur + 1;
}
void solve() {
	cin >> n >> m;
	char c;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> c;
			a[i][j] = (c == '0') ? 0 : 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j]) check(i, j);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j]) {
				dp(i, j);
			}
		}
	}
	cout << couting;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}