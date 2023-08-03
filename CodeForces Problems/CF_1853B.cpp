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

pi compute(int k) {
	pi a = {1, 0}, b = {0, 1};
	for(int i = 3; i <= k; i++) {
		pi c = b;
		b.fi += a.fi;
		b.se += a.se;
		a = c;
	}
	return b;
}

int n, k;
void solve() {
	cin >> n >> k;

	if(k > 30) {
		cout << 0 << endl;
		return;
	}
	pi cur = compute(k);
	int a = cur.fi, b = cur.se;

	int cnt = 0;
	//a * i + b * gi do = n
	for(int i = 0; i <= n/a; i++) {
		int temp = (n - a * i) / b;
		if((n - a * i) % b == 0 && temp >= i) {
			cnt++;
		}
	}
	cout << cnt << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
} 