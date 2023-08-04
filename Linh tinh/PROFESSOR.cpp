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

int n, a[maxn] = {}, b[maxn] = {};
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	pi ans = {1, a[0]};

	for(int i = 1; i <= 5; i++) {
		int l = 0; //r - l + 1
		for(int j = 0; j < n; j++) {
			if(a[j] != i && b[j] != i) {
				if(j - l > ans.fi) {
					ans.fi = j - l;
					ans.se = i;
				}
				l = j + 1;
			}
		}
		if(l != n + 1 && n - l > ans.fi) {
			ans.fi = n - l;
			ans.se = i;
		}
	}
	cout << ans.fi << ' ' << ans.se;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("PROFESSOR.INP", "r", stdin);
	freopen("PROFESSOR.OUT", "w", stdout);
 	solve();
}