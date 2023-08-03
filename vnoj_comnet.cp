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

struct layline {
	int u, v, w;
	layline() {
		u = 0; v = 0; w = 0;
	}
};
bool cmp(layline a, layline b) {
	return a.w <= b.w;
}
struct DSU {
	vector<int> p;
	DSU(int n) : p(n + 5) {};
	int find(int v) {
        return v == p[v] ? v : p[v] = find(p[v]);
    }
    void make(int i) {
    	p[i] = i;
    }
    void connect(int u, int v) {
    	u = find(u); v = find(v);
    	if(u == v) return;
    	p[u] = v;
    }
};
int n, m, q, k, place, newVal, s;


void compute(int k, vector<layline> a, vector<pi> b, int s) {
	for(int i = 0; i < s; i++) {
		a[b[i].fi].w = b[i].se;
	}
	int u = a[k].u, v = a[k].v, w = a[k].w;

	sort(a.begin() + 1, a.begin() + m + 1, cmp);
	
	DSU g1(n + 5), g2(n + 5);
	int MST1 = 0, MST2 = 0;
	
	for(int i = 1; i <= n; i++) {
		g1.make(i); g2.make(i);
	}
	
	for(int i = 1; i <= m; i++) {
		if(g1.find(a[i].u) == g1.find(a[i].v)) continue;
		g1.connect(a[i].u, a[i].v);
		MST1 += a[i].w;
	}
	bool c = 1;
	for(int i = 1; i <= m; i++) {
		if(a[i].w >= w && c) {
			MST2 += w;
			g2.connect(u, v);
			c = !c;
			i--;
		}
		else if(g2.find(a[i].u) == g2.find(a[i].v)) continue;
		else {
			g2.connect(a[i].u, a[i].v);
			MST2 += a[i].w;
		}
	}
	cout << MST1 << ' ' << MST2 << ' ';
	cout << ((MST1 != MST2) ? "YES" : "NO") << endl;
}

void solve() {
	cin >> n >> m >> q;
	vector<layline> a(m + 1);
	vector<pi> ans(101);
	for(int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	while(q--) {
		cin >> k >> s;
		for(int i = 0; i < s; i++) {
			cin >> ans[i].fi >> ans[i].se;
		}
		compute(k, a, ans, s);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
}
