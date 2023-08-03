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
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, k, u;
map<int, int> mp;
int a[maxn] = {};
void solve() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> u;
		a[i] = u;
		if(u - k >= 0) mp[u - k]++;
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += mp[a[i]];
		// cerr << ans << endl;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}