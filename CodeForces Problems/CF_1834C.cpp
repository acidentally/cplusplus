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
char s1[maxn] = {}, s2[maxn] = {};
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s1[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> s2[i];
	}
	int d1 = 0, d2 = 0;
	for(int i = 1; i <= n; i++) {
		if(s1[i] != s2[i]) d1++;
		if(s1[i] != s2[n + 1 - i]) d2++;
	}
	cout << min(2 * d1, 2 * d2 - 1) << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}