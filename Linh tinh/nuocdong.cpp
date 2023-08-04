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

int const maxn 		= 	2e7 + 1;
int const INF 		= 	LLONG_MAX;


int n;
int a[maxn] = {}, l[maxn] = {}, r[maxn] = {};
uint res = 0;
signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		l[i] = max(l[i - 1], a[i]);
	}
	for(int i = n; i >= 1; i--) r[i] = max(r[i + 1], a[i]);
	for(int i = 1; i <= n; i++) res += max((uint)min(l[i], r[i]) - a[i], 0ull);
	cout << res;
}