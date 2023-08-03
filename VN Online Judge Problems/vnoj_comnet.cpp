/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define vi vector<int>
#define endl '\n'
typedef pair<int, int> pi;

struct layline {
	int u, v, w;
	layline() {
		u = 0; v = 0; w = 0;
	}
};
struct DSU {
	vi p;
	DSU() : p((int)1e5 + 100) {}
	DSU createDSU(int l) {
		DSU tem;
		iota(tem.p.begin() + 1, tem.p.begin() + l + 1, 1);
		return tem;
	}
	int find(int v) {
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    void make(int i) {
    	p[i] = i;
    }
    void connect(int u, int v) {
    	u = find(u); v = find(v);
    	p[u] = v;
    }
} g1;

int n, m, q, k, place, newVal, s;
int u, v, w;

void compute(int& k, vector<layline> a, pi b[101], int& s) {
	for(int i = 0; i < s; i++) {
		a[b[i].fi].w = b[i].se;
	}
	u = a[k].u; v = a[k].v; w = a[k].w;

	g1 = g1.createDSU(n + 10);
	for(int i = 1; i <= m; i++) {
		if(a[i].w >= w || i == k) continue;
		g1.connect(a[i].u, a[i].v);
	}
	if(g1.find(u) == g1.find(v)) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}
pi ans[101];
vector<layline> A((int)1e6 + 100);
void solve() {
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++) {
		cin >> A[i].u >> A[i].v >> A[i].w;
	}
	while(q--) {
		cin >> k >> s;
		for(int i = 0; i < s; i++) {
			cin >> ans[i].fi >> ans[i].se;
		}
		compute(k, A, ans, s);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
}
 