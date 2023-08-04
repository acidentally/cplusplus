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

int const maxn = 1e5 + 10;
vector< set<int> > a(maxn);
bool vis[maxn], found = false;
int n, m, s, t, u, v;

void BFS(int x) {
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto i : a[u]) {
			if(i == t) {
				cout << "YES";
				exit(0);
			}
			if(!vis[i]) {
				vis[i] = true;
				q.push(i);
			}
		}
	}
}

void solve() {
	cin >> n >> m >> s >> t;
	while(m--) {
		cin >> u >> v;
		a[u].insert(v);
		a[v].insert(u);
	}
	memset(vis, 0, sizeof(vis));
	BFS(s);
	cout << "NO";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}