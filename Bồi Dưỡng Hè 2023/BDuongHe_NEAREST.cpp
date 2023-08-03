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
#define dub 			double
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

struct point {
	double x, y;
	bool operator < (const point& com) {
		if(x != com.x) return x < com.x;
		else return y < com.y;
	}
	point() {
		x = 0, y = 0;
	}
	point(double x_, dub y_) : x(x_), y(y_) {}
};

struct cmp{
	bool operator() (const point& a, const point& b) const {
		if(a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	}
};
int n;
double u, v;
set<point, cmp> s;
vector<point> a;
double sqr(double k) {
	return k * k;
}
double dist(point a, point b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> u >> v;
		a.pb(point(u, v));
	}
	dub ans = dist(a[0], a[1]);
	sort(all(a));
	point cur;
	for(auto k : a) {
		u = k.x; v = k.y;
		dub temp = sqrt(ans);

		cur = point((dub)-1e7, v - temp);
		while(1) {
			auto ptr = s.upper_bound(cur);
			if(ptr == s.end()) break;
			cur = *ptr;

			if(cur.y > v + temp || cur) break;
			if(cur.x < u - temp) {
				s.erase(ptr);
				continue;
			}

			if(dist(k, cur) < ans) {
				ans = dist(k, cur);
			}
		}

		s.insert(k);
	}
	cout << fixed << setprecision(5) << sqrt(ans);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("NEAREST.INP", "r", stdin);
	// freopen("NEAREST.OUT", "w", stdout);
 	solve();
}