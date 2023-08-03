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
int n, m, u, v;
bool vis[maxn] = {};
vi a[maxn];
string trash = "Thanh phan ";
vi couting;

void bfs(int k) {
	couting.push_back(k);
	vis[k] = true;
	queue<int> q;
	q.push(k);
	while(!q.empty()) {
		int temp = q.front();
		if(!vis[temp]) couting.push_back(temp);
		vis[temp] = true;
		q.pop();
		for(int i = 0; i < a[temp].size(); i++) {
			if(!vis[a[temp][i]]) {
				q.push(a[temp][i]);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int cnt = 1;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			cout << trash << cnt << ": "; 
			couting = vi();
			bfs(i);
			cnt++;
			cout << couting.size() << ' ';
			for(auto i : couting) cout << i << ' ';
			cout << endl;
		}
	}
	// cout << ((cnt == 1) ? "YES" : "NO");
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}