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
int x1, x2, y1, y2, n, m, k;
int const maxn = 5e6 + 10;
int p[maxn] = {};
void init() {
	for(int i = 0; i < m * n; i++) {
		p[i] = i;
	}
}
int find(int k) {
	if(k != p[k]) p[k] = find(p[k]);
	return p[k];
}
void connect(int u, int v) {
	u = find(u); v = find(v);
	if(u != v) {
		p[u] = v;
	}
}
bool get(int u , int v,
		 int u_, int v_) {
	u = find(u);
	v = find(v);
	u_ = find(u_);
	v_ = find(v_);
	set<int> s;
	s.insert(u); s.insert(v); 
	s.insert(u_); s.insert(v_);
	if(s.size() >= 3) {
		if(u == v || u == u_ || v_ == v || v_ == u_) return false;
		return true;
	}
	else return false;
}
void solve() {
	cin >> n >> m >> k;
	init();
	while(k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		connect(x1 * m + y1, x2 * m + y2);
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < m - 1; j++) {
		
			if(!get(
				
				(i * m + j),        (i * m + j + 1), 
				((i + 1) * m + j),  ((i + 1) * m + j + 1))

				) {

				cout << "NO" << endl;
				return;
			
			}

		}
	}
	cout << "YES" << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	solve();
}