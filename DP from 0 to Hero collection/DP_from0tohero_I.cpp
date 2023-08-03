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

int sol[maxn] = {};
void init() {
	sol[0] = 1; sol[1] = 2; sol[2] = 7;
	int sum = 1;
	for(int i = 3; i <= maxn; i++) {	
		sol[i] = (
				2 * sol[i - 1] % mod +
				3 * sol[i - 2] % mod +
				2 * sum % mod
				) % mod;
		(sum += sol[i - 2]) % mod;
	}
}
int n;
void solve() {
	cin >> n; cout << sol[n];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	init();
 	solve();
}