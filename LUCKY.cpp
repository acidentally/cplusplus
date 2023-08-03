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

int logu(int k) {
	int ans = 0;
	k++;
	while(k) {
		ans++;
		k >>= 1;
	}
	return ans - 1;
}
int n;
void solve() {
	cin >> n;
	int k = logu(n);
	// cout << k << endl;
	int place = (1 << k) - ((1 << (k + 1)) - n - 2) - 1;
	bool a[k] = {};
	for(int i = 0; i < k; i++) {
		if(place & 1) a[i] = 1;
		place >>= 1;
	}
	for(int i = k - 1; i >= 0; i--) {
		cout << (a[i] ? 7 : 4);
	}
	cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LUCKY.INP", "r", stdin);
	freopen("LUCKY.OUT", "w", stdout);
 	solve();	
	
}

// 12 -> 1
// 3456 -> 2
// 7 -> 14 -> 3