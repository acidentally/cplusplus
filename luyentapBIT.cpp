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

int n;
int a[maxn], BIT[maxn] = {};
void update(int id, int val) {
	while(id <= n) {
		BIT[id]+= val;
		id += id & -id;
	}
}
int query(int id) {
	int ans = 0;
	while(id > 0) {
		ans += BIT[id];
		id -= id & -id;
	}
	return ans;
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	for(int i= 1; i <= n; i++) {
		cout << query(i) << ' ';
	} cout << endl;
	cout << BIT[3];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}