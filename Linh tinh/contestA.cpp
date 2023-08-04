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
#define dub 			double
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
#define ins 			insert

typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;

int const maxn 		= 	1e6 + 10; 
int const INF 		= 	LLONG_MAX;

int sqr(int k) {
	return k * k;
}
int modPow(int a, int k) {
	if(k == 0) return 1;
	if(k == 1) return a;
	if(k & 1) return a * sqr(modPow(a, k/2));
	return sqr(modPow(a, k/2));
}

int n, x;
vector<pi> a;
void solve() {
	cin >> n >> x;
	int k = x;
	for(int i = 2; i * i <= k; i++) {
		if(x % i == 0) {
			int cur = 0;
			while(x % i == 0) {
				x /= i;
				cur++;
			}
			a.pb(mp(i, cur));
		}
	}
	if(x != 1) {
		a.pb(mp(x, 1));
	}
	int ans = 1;
	for(auto s : a) {
		cerr << s.fi << ' ' << s.se << endl;
		if(n > s.se) continue;
		ans *= modPow(s.fi, s.se/n);
		cerr << ans << endl;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}