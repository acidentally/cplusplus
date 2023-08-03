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

int minPrime[maxn] = {};
void eratos() {
	minPrime[0] = minPrime[1] = 1;
	for(int i = 2; i * i <= maxn; i++) {
		if(!minPrime[i]) {
			for(int j = i * i; j <= maxn; j += i) {
				if(!minPrime[j]) minPrime[j] = i;
			}
		}
	}
	for(int i = 2; i <= maxn; i++) {
		if(!minPrime[i]) minPrime[i] = i;
	}
}
int compute(int a) {
	if(a == 1) return 0;
	int cur = minPrime[a], cnt = 0;
	int ans = 0;
	while(a % cur == 0) {
		a /= cur;
		cnt++;
	}
	return ans ^ (cnt + compute(a));
}	
int n;
void solve() {
	cin >> n;
	int a[maxn] = {}, s = 0, x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x == 1) continue;
		s ^= compute(x);
	}
	if(s == 0) {
		cout << "BOB"; 
	} else cout << "ALICE";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	eratos();
 	solve();
}