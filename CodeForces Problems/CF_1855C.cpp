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

int n;
int a[50] = {};
pi maxi = mp(0, 0);
void compute(bool thuan) {
	cout << 3 + 2 * n << endl;	
	for(int i = 0; i < 5; i++) {
		cout << maxi.se << ' ' << maxi.se << endl;
	}
	for(int i = 1; i <= n; i++) {
		if(i == maxi.se) continue;
		cout << i << ' ' << maxi.se << endl;
	}
	if(!thuan) { 
		for(int i = n; i > 1; i--) 
			cout << i - 1 << ' ' << i << endl;
	}
	else {
		for(int i = 1; i < n; i++) {
			cout << i + 1 << ' ' << i << endl;
		}
	}
}
void solve() {
	cin >> n;
	maxi = mp(-500, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		maxi = max(maxi, mp(a[i], i));
	}
	if(maxi.fi > 0) compute(1);
	else compute(0);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}