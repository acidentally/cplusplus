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

int n, a[25] = {}, x;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		for(int j = 24; j >= 0; j--) {
			int c = (x >> j) & 1;
			a[j] += c;
		}
	}
	int ans = 0;
	for(int i = 0; i < 25; i++) {
		cerr << a[i] << endl;
		ans += (n - a[i]) * a[i] * (1 << i);
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("X3.INP", "r", stdin);
	freopen("X3.OUT", "w", stdout);
 	solve();
}