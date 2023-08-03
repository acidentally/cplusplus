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
int const maxn 		= 	1e6 + 10;
int const INF 		= 	LLONG_MAX;

int sol[maxn + 2] = {};
void init() {
	sol[1] = 1;
	sol[2] = 2;
	for(int i = 3; i <= maxn; i++) {
		sol[i] = (sol[i - 1] % mod + sol[i - 2] % mod) % mod;
	}
}
int n;
void solve() {
	cin >> n;
	cout << sol[n] << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	init();
	int t; cin >> t;
	while(t--) solve();
}