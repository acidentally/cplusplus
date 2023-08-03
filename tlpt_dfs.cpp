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
vi a[maxn], couting;
bool vis[maxn] = {};
string trash = "Thanh phan ";
int temp;
void dfs(int k) {
	vis[k] = true;
	couting.push_back(k);
	for(int i = 0; i < a[k].size(); i++) {
		temp = a[k][i];
		if(!vis[temp]) {
			dfs(temp);
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
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			dfs(i);
			cnt++;
		}
	}
	if(cnt > 1) cout << "NO";
	else cout << "YES";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}