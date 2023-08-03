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

int const maxn = (int) 1e6 + 10;
vi minPrime(maxn, 0);
void eratos() {
	for(int i = 0; i < maxn; i++) minPrime[i] = i;
	for(int i = 2; i * i <= maxn; i++) {
		if(minPrime[i] == i) {
			for(int j = i * i; j <= maxn; j += i) {
				if(minPrime[j] == j) minPrime[j] = i;
			}
		}
	}
}
int x;
void solve() {
	cin >> x;
	map<int, int> mp;
	while(x != 1) {
		mp[minPrime[x]]++;
		x /= minPrime[x];
	}
	int ans = 1;
	for(auto i : mp) ans *= i.se + 1;
	cout << ans << endl; 
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	eratos();
	while(n--) {
		solve();
	}
}
