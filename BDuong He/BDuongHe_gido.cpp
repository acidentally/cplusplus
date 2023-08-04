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
int const maxn 		= 	1e6 + 10;
int const INF 		= 	LLONG_MAX;

int n;
char x;
void solve() {
	cin >> n;
	int mini = 0;
	int a[n + 10] = {};
	a[0] = 0;
	for(int i = 1; i <= n - 1; i++) {
		cin >> x;

		if(x == '=') a[i] = a[i - 1];
		else if(x == 'R') a[i] = a[i - 1] + 1;
		else if(x == 'L') a[i] = a[i - 1] - 1;

		mini = min(mini, a[i]);
	}
	mini = max(0ll, 1 - mini);
	for(int i = 0; i < n; i++) {
		cout << a[i] + mini << ' ';

	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("toffees.inp", "r", stdin);
	// freopen("toffees.out", "w", stdout);
 	solve();
} 