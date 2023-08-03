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

int n;
char x;
vector<bool> a, b;
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		a.pb(x - '0');
	}
	for(int i = 0; i < n; i++) {
		cin >> x;
		b.pb(x - '0');
	}
	int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 0; i < n; i++) {
		if(!a[i] && !b[i]) cnt0++;
		if(!a[i] && b[i]) cnt1++;
		if(a[i] && !b[i]) cnt2++;
		if(a[i] && b[i]) cnt3++;
	}
	// 0 0 1 1
	// 0 1 0 1
	cout << cnt0 * (cnt2 + cnt3) + cnt1 * cnt2;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}