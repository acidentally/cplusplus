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

int const maxn = 2e5 + 10;

int n, m, u, v;
int T[maxn] = {}, P[maxn][20] = {};
int h[maxn] = {};
vi a[maxn];

void dfs(int k, int p, int depth) {
	h[k] = depth;
	T[k] = p;
	for(int i = 0; i < a[k].size(); i++) {
		if(a[k][i] == p) continue;
		dfs(a[k][i], k, depth + 1);
	}
}
void precompute() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; (1 << j) < n; j++) {
			P[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; i++) {
		P[i][0] = T[i];
	}
	for(int j = 1; 1 << j < n; j++) {
		for(int i = 1; i <= n; i++) {
			if(P[i][j - 1] != -1) {
				P[i][j] = P[ P[i][j - 1] ][j - 1];
			}
		}
	}
}
void LCA(int x, int y) {
	if(h[x] <= h[y]) swap(x, y);
	int log = 0, k = h[x];
	while(k) {
		log++;
		k >>= 1;
	}
	for(int i = log; i >= 0; i--) {
		if((h[x] - (1 << i)) >= h[y]) x = P[x][i];
	}	
	if(x == y) {
		cout << x << endl; 
		return;
	}
	// cout << x;
	for(int i = log; i >= 0; i--) {
		if(P[x][i] != -1 && P[x][i] != P[y][i]) {
			x = P[x][i];
			y = P[y][i];
		}
	}
	cout << T[x] << endl;
}
int q;
void solve() {
	cin >> n >> q;
	for(int i = 2; i <= n; i++) {
		cin >> u;
		a[i].push_back(u);
		a[u].push_back(i);
	}
	dfs(1, 0, 1);
	precompute();
	
	while(q--) {
		cin >> u >> v;
		// cout << u << v << ' ';
		LCA(u, v);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}