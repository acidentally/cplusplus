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
int const mod 		= 	1000000000;

int const maxn 		= 	1e3 + 10; 
int const INF 		= 	LLONG_MAX;

int n;
int x;
map<int, int> m;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		for(int j = 2; j * j <= x; j++) {
			while(x % j == 0) {
				x /= j;
				m[j]++;
			}
		}
		if(x != 1) m[x]++;
	}

	int ans = 1;
	bool g = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		for(int j = 2; j * j <= x; j++) {
			while(x % j == 0) {
				x /= j;
				if(m[j] > 0) {
					ans = ans * j;
					m[j]--;
					if(ans >= mod) {
						g = 1;
						ans %= mod;
					}
				}
			}
		}
		if(x != 1 && m[x] > 0) {
			ans = ans * x; 
			m[x]--;
			if(ans >= mod) {
				g = 1;
				ans %= mod;
			}
		}
	}
	if(!g) {
		cout << ans;
		return;
	}
	vi cac;
	while(ans) {
		cac.pb(ans % 10);
		ans /= 10;
	}
	while(cac.size() < 9) cac.pb(0);
	reverse(all(cac));
	for(int i : cac) cout << i;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("ASSIGN.INP", "r", stdin);
	freopen("ASSIGN.OUT", "w", stdout);
 	solve();
}