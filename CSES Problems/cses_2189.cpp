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

struct point {
	int x, y;
	point() : x(0), y(0) {}
	point(int x_, int y_) : x(x_), y(y_) {}

} A, B, C;
struct vec {
	int x, y;
	vec() : x(0), y(0) {}
	vec(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
}ab, ac;
int cross(vec& a, vec& b) {
	return a.x * b.y - a.y * b.x;
}

void solve() {
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	ac = vec(A, C);
	ab = vec(A, B);
	if(cross(ab, ac) < 0) {
		cout << "RIGHT" << endl;
	} else if(cross(ab, ac) > 0) {
		cout << "LEFT" << endl;
	} else cout << "TOUCH" << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}