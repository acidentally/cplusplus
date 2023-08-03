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
#define pb 				emplace_back
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
int const maxn 		= 	2e3 + 10;
int const INF 		= 	LLONG_MAX;

struct point {
	int x, y;
	point() : x(0), y(0) {}
	point(int x_, int y_) : x(x_), y(y_) {}
};
pi compute(point a) {
	int x = a.x, y = a.y;
	if(x == 0) return mp(0, 1);
	if(y == 0) return mp(1, 0);
	int k = __gcd(x, y);
	return mp(x/k, y/k);
}

int n;
void solve() {
	cin >> n;
	point a[n + 2] = {};
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	
	int ans = 0;

	for(int i = 1; i <= n; i++) {
		vi A[maxn] = {};
		int id = 0;
		map<pi, int> mpIdx;

		for(int j = 1; j <= n; j++) {
			if(j == i) continue;
			int curX = a[j].x - a[i].x;
			int curY = a[j].y - a[i].y;
			int rot = 0;
			
			while(curX < 0 || curY <= 0) {
				swap(curX, curY);
				curY = ~curY + 1;
				rot++;
			}

			pi temp = compute(point(curX, curY));
			
			if(mpIdx[temp] == 0) mpIdx[temp] = ++id;
			
			A[mpIdx[temp]].pb(rot);
		}
		
		for(int o = 1; o <= id; o++) {
			int cnt[4] = {};
			for(auto k : A[o]) cnt[k]++;
			ans += cnt[0] * cnt[1] +	
				   cnt[1] * cnt[2] + 
				   cnt[2] * cnt[3] + 
				   cnt[3] * cnt[0];
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}