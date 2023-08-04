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

int n, m, q;
void solve() {
	cin >> m >> n >> q;
	int alr = min(m/2, n);
	q -= m + n - 3 * alr;
	if(q <= 0) {
		cout << alr;
		return;
	}
	cout << alr - (q - 1)/3 - 1;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("TEAMS.INP", "r", stdin);
	freopen("TEAMS.OUT", "w", stdout);
 	solve();
 	// cin >> n;
 	// cout << (n - 1)/3 + 1;
}