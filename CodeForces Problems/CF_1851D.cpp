/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			unsigned long long
#define uint 			long long
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
int const maxn 		= 	2e5 + 10;
int const INF 		= 	LLONG_MAX;

int n;
int a[maxn] = {};
void solve() {
	cin >> n;
	bool check[n + 10] = {};
	int OverLoad = 0;
	for(int i = 1; i <= n - 1; i++) {
		cin >> a[i];
		if(a[i] - a[i - 1] > n) OverLoad = a[i] - a[i - 1];
		else {
			if(!check[a[i] - a[i - 1]]) check[a[i] - a[i - 1]] = true;
			else OverLoad = a[i] - a[i - 1];
		}
	}
	int cnt = 0;
	if(OverLoad == 0) {
		YES  
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!check[i]) {
			OverLoad -= i;
			cnt++;
		}
	}
	if(cnt == 1) {
		YES
	} else {
		cout << ((OverLoad == 0) ? "YES" : "NO");
		cout << endl;
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	uint t; cin >> t;
	while(t--) solve();
}