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
int const maxn 		= 	1e6 + 10;
int const INF 		= 	LLONG_MAX;

char x;
int a[26] = {};
int FAC[maxn] = {}, invFac[maxn] = {};
int sqr(int k) {
	return (k * k) % mod;
}
int modPow(int k, int exp) {
	if(exp == 0) return 1;
	if(exp == 1) return k;
	if(exp & 1) return (k * sqr(modPow(k, exp/2))) % mod;
	return sqr(modPow(k, exp/2)) % mod;
}
void init(int k) {
	FAC[1] = 1;
	for(int i = 2; i <= k; i++) {
		FAC[i] = (FAC[i - 1] * i % mod) % mod;
	}
	invFac[k] = modPow(FAC[k], mod - 2);
	for(int i = k; i >= 1; i--) {
		invFac[i - 1] = (invFac[i] * i) % mod;
	}
}
void solve() {
	int cnt = 0;
	while(cin >> x) {
		a[x - 'a']++; cnt++;
	}
	init(cnt);
	int ans = FAC[cnt];
	for(int i = 0; i < 26; i++) {
		ans = ans % mod * invFac[a[i]] % mod % mod;
	}
	cout << ans % mod;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}