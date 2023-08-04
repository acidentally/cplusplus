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

int n, m;
void solve() {
	cin >> m >> n;
	int Top = 1, Fro = 2, R = 3;
	int ans = (n - 1) / 4 * m * 14 + 1;
	n = (n - 1) % 4;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(i & 1) {
				swap(R, Top);
				Top = 7 - Top;
			}
			else {
				swap(R, Top);
				R = 7 - R;
			}
			cerr << Top << endl;
			ans += Top;
		}
		swap(Top, Fro);
		Top = 7 - Top;
		cerr << Top << endl;
		if(i != m) ans += Top;
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}