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
int const maxn = 1e5 + 10;
int n, x;
bool cnt[maxn] = {};
void solve() {
	cin >> n;
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		cnt[x] = true;
		maxi = max(maxi, x);
	}
	for(int i = 1; i <= maxi; i++) {
		int k = 0, countDiv = 0;
		for(int j = i; j <= maxi; j += i) {
			if(cnt[j]) {
				if(!k) k = j;
				else {
					k = __gcd(k, j);
				}
				countDiv++;
			}
		}

		if(countDiv < 2 || k != i) {
			cout << i;
			return;
		}
	}
	cout << maxi + 1;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}