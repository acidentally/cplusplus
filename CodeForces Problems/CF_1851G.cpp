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
int const maxn 		= 	2e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, u;
int m, q, v, w, h[maxn] = {};
vi a[maxn] = {};
struct DSU {
	vi p;
	DSU(int l) : p(l + 5) {}
	int find(int v) {
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    void connect(int u, int v) {
    	u = find(u); v = find(v);
    	p[u] = v;
    }
    void reset(int l) {
    	for(int i = 1; i <= l; i++) p[i] = i;
    }
} dsu(maxn);
void solve() {
	cin >> n >> m;
	dsu.reset(n + 10);
	vector<pi> sortedEdges;

	for(int i = 1; i <= n; i++) {
		cin >> h[i];
		sortedEdges.pb(mp(h[i], ~i));
		a[i] = vi();
	}
	while(m--) {
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	cin >> q;
	bool qans[q + 1] = {};
	int qu[q + 1] = {}, qv[q + 1] = {}, qw[q + 1] = {};

	for(int i = 1; i <= q; i++) {
		cin >> qu[i] >> qv[i] >> qw[i];
		sortedEdges.pb(mp(h[qu[i]] + qw[i], i));
	}
	sort(all(sortedEdges));

	//Xét theo phần tử đầu tiên của sortedEdge là lẫn lộn
	//các limit của cạnh và độ dài các cạnh theo thứ tự
	//từ nhỏ tới lớn

	vector<bool> pass(n + 2, 0);
	for(auto e : sortedEdges) {
		int idx = e.se;
		if(idx >= 0) {
			qans[idx] = (dsu.find(qu[idx]) == dsu.find(qv[idx]));
			continue;
		}
		idx = ~idx;
		for(auto i : a[idx]) {
			if(pass[i]) {
				dsu.connect(i, idx);
			}
		}
		pass[idx] = true;
	}
	
	//couting computation
	for(int i = 1; i <= q; i++) {
		if(qans[i]) YES
		else NO
	}
	cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}