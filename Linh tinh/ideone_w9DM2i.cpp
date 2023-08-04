#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1001;

int n, m, disc[maxn], low[maxn], timer = 0;
vector<int> adj[maxn];
bool is_cut[maxn];

void in(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(disc, 0, sizeof(disc));
	memset(low, 0, sizeof(low));
	memset(is_cut, false, sizeof(is_cut));
}

void dfs(int u, int parent){
	low[u] = disc[u] = ++timer;
	int child = 0;
	for(int v : adj[u]){
		if(v == parent) continue;
		if(!disc[v]){
			++child;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(parent != -1 && low[v] >= disc[u]){
				is_cut[u] = true;
			}
		}else low[u] = min(low[u], disc[v]);
	}
	if(parent == -1 && child > 1) is_cut[u] = true;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	in();
	for(int i = 1; i <= n; i++){
		if(!disc[i]){
			dfs(i, -1);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += is_cut[i] == true;
	}
	cout << ans << endl;
}