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

int n, k, a[maxn] = {};
void solve() {
	cin >> n >> k;
	int cur = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
		if(a[i] == 0) continue;
		cur = __gcd(a[i], cur);
	}	
	cur = __gcd(cur, k);
	if(cur == 0) {
		cout << "1\n0";
		return;
	}
	cout << k/cur + (k%cur != 0) << endl;
	for(int i = 0; i < k; i += cur) {
		cout << i << ' ';
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}