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

int const maxn = 1e6 + 10;
int n, k, x;
vi minPrime(maxn, 0);
map<int, int> mp;
void eratos() {
	for(int i = 0; i <= k; i++) {
		minPrime[i] = i;
	}
	for(int i = 2; i * i <= k; i++) {
		if(minPrime[i] == i) {
			for(int j = i * i; j <= k; j += i) {
				if(minPrime[j] == j) minPrime[j] = i;
			}
		}
	}
	for(int i = 2; i <= k; i++) {
		mp[minPrime[i]]++;
	}
}
void solve() {
	cin >> n >> k;
	eratos();
	while(n--) {
		cin >> x;
		cout << mp[x] << endl;
	}
	// cout << mp[2];
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}