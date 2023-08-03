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

int n, k;
int p[110] = {};
bool check[maxn] = {};
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		cin >> p[i];
		check[p[i]] = 1;
	}
	for(int i = 1; i <= n; i++) {
		if(check[i]) {
			cout << 'W';
			continue;
		}
		for(int j = 1; j <= k; j++) {	
			if(p[j] > i) continue;
			check[i] |= !check[i - p[j]];
		}
		cout << ((check[i]) ? 'W' : 'L');
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}