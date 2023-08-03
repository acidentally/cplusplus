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

int const maxn 		= 	1e5 + 10; 
int const INF 		= 	LLONG_MAX;

int n, x;
int a[2000] = {};
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		int mask = 0;
		while(x) {
			int c = x % 10;
			mask |= (1 << c);
			x /= 10;
		}
		a[mask]++;
	}	
	int ans = 0;
	for(int i = 1; i <= 1024; i++) {
		ans += a[i] * (a[i] - 1);
		for(int j = i + 1; j <= 1024; j++) {
			if(i & j && a[i] != 0 && a[j] != 0) {
				ans += a[i] * a[j];
			}
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}