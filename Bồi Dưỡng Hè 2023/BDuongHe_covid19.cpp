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
int const maxn = 1e5 + 10;

vi a[maxn];
int n, u, v, ans = 0;
bool vis[maxn] = {};
pi lg(int k) {
	if(k <= 0) return {0, -1};

	int ans2 = 0, temp = k - 1;
	while(temp) {
		ans2++;
		temp >>= 1;
	}
	return {ans2, k - (1 << ans2)};
}
void dfs(int k, int p, int d) {
	vis[k] = true;
	int temp = a[k].size();
	for(int i = 0; i < a[k].size(); i++) {
		if(vis[a[k][i]]) temp--;
	}
	pi holder = lg(temp);
	if(holder.se == 0) holder.fi++;
	ans += holder.fi + temp;

	for(int i = 0; i < a[k].size(); i++){
		if(vis[a[k][i]]) {
			continue;
		}
		dfs(a[k][i], k, d + 1);
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1, -1, 0);
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}