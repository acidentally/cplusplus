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

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef pair<int, int> pi;
int const maxn = 1e4 + 10;
int n, m, u, v, x;
map<int, vector<pi> > mp;
vi p;
// deque< tuple<int, int, int> > ans;
void init() {
	for(int i = 0; i <= n; i++) {
		p.push_back(i);
	}
}
int find(int k) {
	if(k == p[k]) return k;
	return p[k] = find(p[k]);
}
void connect(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	p[a] = b;
}

void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> x;
		mp[x].push_back({u, v});
	}
	init();
	int couting = 0;
	for(auto i : mp) {
		for(int j = 0; j < i.se.size(); j++) {
			int a = i.se[j].fi, b = i.se[j].se;
			if(find(a) == find(b)) continue;
			else {
				couting += i.fi;
				// ans.push_back(make_tuple(i.fi, a, b));
				connect(a, b);
			}
		}
	}
	cout << couting << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	// while(!ans.empty()) {
	// 	int a, b, c;
	// 	tie(a, b, c) = ans.front();
	// 	cout << b << ' ' << c << ' ' << a << endl;
	// 	ans.pop_front();
	// }
}