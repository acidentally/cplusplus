/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e3 + 10;
int const INF 		= 	LLONG_MAX;

struct DSU {
	vi p;
	DSU() : p(maxn) {}
	DSU createDSU(int l) {
		DSU tem;
		iota(tem.p.begin() + 1, tem.p.begin() + l + 1, 1);
		return tem;
	}
	int find(int v) {
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    void connect(int u, int v) {
    	u = find(u); v = find(v);
    	p[u] = v;
    }
}dsu;

vi a[maxn] = {};
int n, m, u, v;
char x;
void solve() {
	cin >> n >> m;
	dsu = dsu.createDSU(n);
	while(m--) {
		cin >> x >> u >> v;
		if(x == 'F') {
			dsu.connect(u, v);
		}
		else {
			a[u].pb(v);
			a[v].pb(u);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(auto j : a[i]) {
			for(auto k : a[j]) {
				dsu.connect(i, k);
			}
		}
	}
	set<int> s;
	for(int i = 1; i <= n; i++) s.insert(dsu.find(i));
	cout << s.size();
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}