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
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

int m;
void solve() {
	cin >> m;
	vi modLeft, modRight;
	int diff = m, cur = 1;
	while(diff != 0) {
		if(diff % 3 == 1) {
			diff -= 1;
			modRight.pb(cur);
		}
		if(diff % 3 == 2) {
			diff += 1;
			modLeft.pb(cur);
		}
		diff /= 3;
		cur *= 3;
	}

	cout << modLeft.size() << ' ';
	for(auto k : modLeft) cout << k << ' ';
	cout << endl << modRight.size() << ' ';
	for(auto k : modRight) cout << k << ' ';
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("can3.inp", "r", stdin);
	// freopen("can3.out", "w", stdout);
 	solve();
}