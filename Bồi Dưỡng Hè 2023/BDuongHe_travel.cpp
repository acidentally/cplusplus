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
int const mod 	  = 	1e9 + 7;
int const maxn 	  = 	1e3 + 10;
int const INF 	  = 	LLONG_MAX;

int n, m, C, u, v;
vi a[maxn] = {};
int b[maxn] = {};
vector<pi> c;
bool vis[maxn] = {};
void start(int k, int d, int p) {
	vis[k] = true;
	if(k == 1) {
		c.push_back({p, d});
	}
	cerr << k << endl;

	for(int i = 0; i < a[k].size(); i++) {
		if(a[k][i] == 1) {c.push_back({p, d + 1});}
		if(!vis[a[k][i]]) {
			start(a[k][i], d + 1, p + b[a[k][i]]);
		}
	}
}
void dijkstra() {
	priority_queue<pi, 
}
void solve() {
	cin >> n >> m >> C;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
	}
	start(1, 0, 0);
	for(int i = 0; i < c.size(); i++) {
		cout << c[i].fi << ' ' << c[i].se << endl;
	}

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}