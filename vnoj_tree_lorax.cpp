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

int n, q, u, v, x;
int const maxn = 1e5 + 10;
int a[maxn], st[4 * maxn], idx[maxn];
int countNum[maxn] = {};
bool check[maxn]; 
map<int, int> mapp;

void update(int id, int l, int r, int u, int v) {

}
void solve() {
	cin >> n >> q;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		mapp[u] = v;
		mapp[v] = u;
		countNum[u]++;
		countNum[v]++;
		if(countNum[u] == 2) check[u] = true;
		if(countNum[v] == 2) check[v] = true;
	}
	for(int i = 1; i <= n; i++) {
		if(!check[i]) u = i;
	}
	while(n--) {
		a[n] = u;
		idx[u] = n;
		u = mapp[u];
	}
	while(q--) {
		cin >> u >> v >> x;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}