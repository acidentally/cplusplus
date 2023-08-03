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
int const maxn 		= 	2e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, m, l, r;
char x;
bool a[maxn] = {};
int L[maxn] = {}, R[maxn] = {};
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = (x == '1');
	}
	int cur = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i]) R[i] = R[i - 1];
		else R[i] = i;
	}
	L[n + 1] = n;
	for(int i = n; i >= 1; i--) {
		if(!a[i]) L[i] = L[i + 1];
		else L[i] = i;
	}
	set<pi> s;
	while(m--) {
		cin >> l >> r;
		if(L[l] >= R[r]) {
			s.ins(mp(0, 0));
			continue;
		}
		s.ins(mp(L[l], R[r]));
	}	
	cout << s.size() << endl;
	// cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}