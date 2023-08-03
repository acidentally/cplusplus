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
int const maxn 		= 	3e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, k;
int a[maxn] = {};
void solve() {
	cin >> n >> k;
	priority_queue<pi> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
		if(a[i] == 0) a[i] = k;
		q.push(mp(a[i], -i));
	}
	while(!q.empty()) {
		cout << -q.top().se << ' ';
		q.pop();
	}
	cout << endl;


}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}