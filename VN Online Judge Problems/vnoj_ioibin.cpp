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

int const maxn = 1e4 + 10;
int p[maxn + 1], u, v, q, t, k;
void solve() {
	cin >> q;
	for(int i = 1; i < maxn; i++) {
		p[i] = i;
	}
	while(q--) {
		cin >> u >> v >> t;
		if(t == 1 && p[u] != p[v]) {
			k = p[u];
			for(int i = 1; i < maxn; i++) {
				if(p[i] == k) {
					p[i] = p[v];
				}
			}
			p[u] = p[v];
		} else if(t == 2) {
			cout << ((p[u] == p[v]) ? 1 : 0) << endl;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}