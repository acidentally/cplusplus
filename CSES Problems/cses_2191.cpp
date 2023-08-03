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

struct point {
	int x, y;
	point() : x(0), y(0) {}
	point(int x_, int y_) : x(x_), y(x_) {}
};

int compute(point a, point b) {
	int width = a.x - b.x;
	int height = a.y + b.y;
	return width * height;
}
point a[maxn] = {};
int n, ans = 0;
void solve() {
	cin >> n;
	cin >> a[1].x >> a[1].y;
	for(int i = 2; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		ans += compute(a[i], a[i - 1]);
	}
	cout << abs(ans + compute(a[1], a[n]));
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}