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


int const mod = 1e9 + 7;

int n;

int sqr(int n) {
	return n * n % mod;
}
int modPow(int n, int k) {
	if(k == 0) return 1;
	if(k == 1) return n % mod;
	else {
		if(k % 2) return n * sqr(modPow(n, k / 2)) % mod;
		else return sqr(modPow(n, k/2)) % mod;
	}
}
void solve() {
	cin >> n;
	cout << modPow(2, n);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}