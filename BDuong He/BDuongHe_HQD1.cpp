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
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

struct vec {
	int x, y;
	vec() {
		x = 0; y = 0;
	}
	vec(int x_, int y_)  : x(x_), y(y_) {}
	int calc(vec a1, vec a2) {
		return a1.x * a2.x + a1.y + a2.y;
	}
};
struct point {
	int x, y;
	point() {
		x = 0, y = 0;
	}
	point(int x_, int y_) : x(x_), y(y_) {}
};
pi transform1(vec a) {
	int x = a.x, y = a.y;
	if(x == 0 && y == 0) return {INF, 0};
	int k = __gcd(x, y);
	if(k == 0 || y == 0) {
		return {INF, 0};
	}
	if(x == 0) return {0,0};
	return {x/y, (x % y) / k};
}
pi transform2(vec a) {
	int x = a.y, y = a.x;
	if(x == 0 && y == 0) return{INF, 0};
	int k = __gcd(x, y);
	if(y == 0) {
		return {INF, 0};
	}
	if(x == 0) return {0,0};
	return {-x/y, (x % y) / k};
}

int n, x, y, ans = 0;
vec temp;
vector<point> a;
map<pi, int>::iterator ptr;
map<pi, int> mpXY, mpYX;
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		a.pb(point(x, y));
	}
	for(int i = 0; i < n; i++) {
		// cout << i << endl;
		point cur = a[i];
		mpXY.clear();
		mpYX.clear();
		for(int j = 0; j < n; j++) {
			if(j == i) continue;
			temp = vec(a[j].x - cur.x, a[j].y - cur.y);	
			mpXY[transform1(temp)]++;
			mpYX[transform2(temp)]++;
			//(x, y) và (x', y') -> xx' = yy'
			//x/y = y'/x'
		}
		int ans1 = 0;
		ptr = mpXY.begin();
		while(ptr != mpXY.end()) {
			ans1 += mpYX[ptr -> fi] * ptr -> se;
			ptr++;
		}
		ans += ans1 / 2;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}