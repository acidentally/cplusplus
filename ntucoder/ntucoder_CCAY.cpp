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

int n, k, u, v, cnt = 1;
vi p, par;
void init() {
	p.resize(n + 1);
	par.resize(n + 1);
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
void solve() {
	cin >> n >> k;
	char c;
	init();
	stack< pair<int, int> > st;
	stack<string> ans;	
	for(int i = 1; i <= n; i++) {
		cin >> u;
		par[i] = u; 	
	}
	bool check[n + 1];
	memset(check, 0, sizeof(check));
	while(k--) {
		cin >> c;
		if(c == 'C') {
			cin >> u;
			if(!check[u]) st.push({u, -1});
			check[u] = true;
		} else {
			cin >> u >> v;
			st.push({u, v});
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!check[i] && par[i] != 0) connect(i, par[i]);
	}
	while(!st.empty()) {
		u = st.top().fi; v = st.top().se;
		st.pop();

		if(v == -1) {
			connect(u, par[u]);
		}
		else {
			if(find(u) == find(v)) {
				ans.push("YES");
			} else ans.push("NO");
		}
	}
	cout << "Case #" << cnt++ << ": " << endl;
	while(!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
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
