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
typedef pair<int, int> pi;

int const maxn = 1e4 + 10;
vector<pi> edges;
int n, m, u, v, id = 1, low[maxn] = {}, ids[maxn] = {};
int ans = 0;
stack<int> st;
vi a[maxn];
bitset<maxn> vis, onStack;
set<pi> sett;
bool found = false;
bool check(int a, int b, int x, int y) {
	if(a == x && b == y) return true;
	if(a == y && b == x) return true;
	return false;
}
void DFS(int idx, int p) {
	low[idx] = ids[idx] = id++;
	vis[idx] = 1;
	st.push(idx);
	onStack[idx] = 1;
	for(int i = 0; i < a[idx].size(); i++) {
		int temp = a[idx][i];
		if(temp == p) continue;
		if(!vis[temp]) {
			DFS(temp, idx);
		}
		if(onStack[temp]) {
			low[idx] = min(low[temp], low[idx]);
		}
		// if(low[temp] > ids[idx]) {
		// 	sett.insert({min(temp, idx), max(temp, idx)});
		// }
	}
	// if(low[p] >= num[ids])
	if(low[idx] == ids[idx]) {
		while(!st.empty() && st.top() != idx) st.pop();
		st.pop();
		cout << idx << endl;
		found = true;
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		edges.push_back({u, v});
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) DFS(i, -1);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	// if(sett.empty()) {
	// 	cout << -1;
	// 	return 0;
	// }
	// set<pi>::iterator ptr = sett.begin();
	// while(ptr != sett.end()) {
	// 	cout << ptr -> fi << ' ' << ptr -> se << endl;
	// 	ptr++;
	// }
}