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
#define all(i) 			i.begin(), i.end()
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

int app;
bool cmp(int &a, int &b){
    return a % app > b % app;
}
int n, k, x;

void solve() {
	cin >> n >> k;
	vi a(n);
	int maxApp = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		maxApp = max(maxApp, a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= maxApp; i++) {
		int boxx = 0;
		for(int j = 0; j < n; j++) {
			boxx += a[j] / i;
		}

		if(boxx >= k) {
			ans = max(ans, (k/2)*i);
			continue;
		}

		if(boxx >= k/2) {
			int cur = (boxx - (k/2)) * i;
			app = i;
			sort(all(a), cmp);
			for(int j = 0; j + boxx < k && j < n; j++) {
				cur += a[j] % app;
			}
			ans = max(ans, cur);
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}