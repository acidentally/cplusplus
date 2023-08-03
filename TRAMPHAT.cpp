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

vi p(maxn);
int n;
void init() {
	for(int i = 1; i <= n; i++) p[i] = i;
}
int find(int u) {
	if(u != p[u]) p[u] = find(p[u]);
	return p[u];
}
void connect(int u, int v) {
	u = find(u); v = find(v);
	p[u] = v;
}

struct point {
	int x, y;
	point(int x_, int y_) : x(x_), y(y_) {}
	point() : x(0), y(0) {}
};
typedef pair<point, point> pp;

int dis(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

point a[maxn] = {};
void solve() {
	cin >> n;
	init();
	int SCCs = n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	vector< pair<int, pi> > A;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			A.pb(mp(dis(a[i], a[j]), mp(i, j)));
		}
	}

	sort(all(A));
	int furDis = 0;
	int u, v, curDis, idx = 0;
	while(SCCs != 1) {
		u = A[idx].se.fi; v = A[idx].se.se;
		curDis = A[idx].fi;
		idx++;
		if(find(u) != find(v)) {
			furDis = curDis;
			connect(u, v);
			SCCs--;
		}
	}
	cout << fixed << setprecision(7) << (double)sqrt(furDis)/2.0 ;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("TRAMPHAT.INP", "r", stdin);
	freopen("TRAMPHAT.OUT", "w", stdout);
	solve();
}