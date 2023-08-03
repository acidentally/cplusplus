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
int n, m, q, u, v;
stack<int> st, dq;
vi p;
vector< pair<int, int> > a;
bool check[maxn];

void init() {
	p.resize(n + 10);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
}
int find(int i) {
	if(i != p[i]) p[i] = find(p[i]);
	return p[i];
}
void connect(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) {
		p[a] = b;
	}
}
int DEMTPLT() {
	unordered_map<int, bool> mp;
	int couting = 0;
	for(int i = 1; i <= n; i++) {
		if(!mp[find(i)]) {
			mp[find(i)] = true;
			couting++;
		}
	}
	return couting;
}
void solve() {
	cin >> n >> m >> q;
	init();
	a.push_back({0,0});
	memset(check, true, sizeof(check));

	for(int i = 1; i <= m; i++) {
		cin >> u >> v;
		a.push_back({u, v});
	}
	while(q--) {
		cin >> u;	
		dq.push(u);
		check[u] = false;
	}
	for(int i = 1; i <= m; i++) {
		if(check[i]) {
			connect(a[i].fi, a[i].se);
		}
	}

	int count = DEMTPLT();
	while(!dq.empty()) {
		st.push(count);	
		u = a[dq.top()].fi;
		v = a[dq.top()].se;
		dq.pop();
		if(find(u) != find(v)) {
			connect(u, v);
			count--;
		}
	}
	while(!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}