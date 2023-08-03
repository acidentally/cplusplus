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

int n, m;
int a[maxn] = {}, sum[maxn] = {};
int cntLe[2 * maxn] = {}, cntChan[2 * maxn] = {};
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == m) a[i] = 0;
		else a[i] = (a[i] > m) ? 1 : -1;
		sum[i] = a[i] + sum[i - 1];
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		sum[i] += n;
		if(i & 1) {
			ans += cntChan[sum[i]];
			cntLe[sum[i]]++;
		} else {
			ans += cntLe[sum[i]];
			cntChan[sum[i]]++;
		}
		// cout << i << ' ' << ans << endl;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("SUBSTR.INP", "r", stdin);
	freopen("SUBSTR.OUT", "w", stdout);
 	solve();
}