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
int const maxn 		= 	2e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, k;
int a[maxn] = {};
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int stIdx = 0, cnt = 0, cnt2 = 0, endIdx = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[1]) cnt++;
		if(cnt == k) {
			stIdx = i;
			break;
		}
	}
	if(stIdx == 0) {
		NO  
		return;
	}
	if(a[1] == a[n] && stIdx != 0) {
		YES  
		return;
	}
	for(int i = n; i >= 1; i--) {
		if(a[i] == a[n]) cnt2++;
		if(cnt2 == k) {
			endIdx = i;
			break;
		}
	}
	if(endIdx == 0) {
		NO  
		return;
	}
	if(endIdx > stIdx) {
		YES
		return;
	}
	NO
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}