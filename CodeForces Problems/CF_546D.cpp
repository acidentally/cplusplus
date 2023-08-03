/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
int const maxn = 5e6 + 10;
int minPrime[maxn] = {}; 
int f[maxn] = {}, F[maxn] = {};

void sieve() {
	minPrime[0] = minPrime[1] = 1;
	for(int i = 2; i * i <= maxn; i++) {
		if(minPrime[i] == 0) {
			for(int j = i * i; j <= maxn; j += i) {
				if(minPrime[j] == 0) minPrime[j] = i;
			}
		}
	}
	for(int i = 0; i <= maxn; i++) {
		if(!minPrime[i]) minPrime[i] = i;
	}
	for(int i = 1; i <= maxn; i++) {
		int cur = i;
		while(cur != 1) {
			f[i]++;
			cur /= minPrime[cur];
		}
	}
	F[0] = f[0];
	for(int i = 1; i <= maxn; i++) {
		F[i] = F[i - 1] + f[i];
	}
}
int a, b;
void solve() {
	cin >> a >> b;
	cout << F[a] - F[b] << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	sieve();
	int t; cin >> t;
	while(t--)
	solve();
}