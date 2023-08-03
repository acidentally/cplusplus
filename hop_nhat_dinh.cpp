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
int n, m, u, v, d = 0, k, p[maxn];
vi a[maxn];
string trash = "Thanh phan ";
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
	while(m--) {
		cin >> u >> v;
		if(p[u] != p[v]) {
			d++;
			k = p[v];
			for(int i = 1; i <= n; i++) {
				if(p[i] == k) {
					p[i] = p[u];
				}
			}
		}
	}
	cout << "So thanh phan lien thong: " << n - d << endl;
	for(int i = 1; i <= n; i++) {
		a[p[i]].push_back(i);
	}
	int cnt = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i].size()) {
			cout << trash << cnt++ << ": ";
			for(auto j : a[i]) cout << j << ' ';
			cout << endl;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}