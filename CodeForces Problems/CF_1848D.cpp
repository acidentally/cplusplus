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

vi d[10];
void init() {

}
int n, k;
void solve() {
	cin >> n >> k;
	if(n == 0) {
		cout << 0 << endl;
		return;
	}
	int startMod = n % 10;
	if(startMod == 5) {
		cout << max((k - 1) * (n + 5), n * k) << endl;
		return;
	}
	int l = 1, r = k;
	int ans = 0, cur;
	while(l < r) {
		int mid = l + r >> 1;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	init();
	int t; cin >> t;
	while(t--) solve();
}