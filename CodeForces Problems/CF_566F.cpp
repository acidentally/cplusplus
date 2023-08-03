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
bool check[maxn] = {};
int n, x, sz[maxn] = {};
int maxi = 0;
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		check[x] = 1;
		maxi = max(maxi, x);
	}
	int ans = 0;
	
	for(int i = 1; i <= maxi; i++) {
		if(check[i]) {
			for(int j = 2 * i; j <= maxi; j += i) {
				if(check[j]) sz[j] = max(sz[j], sz[i] + 1);
				ans = max(ans, sz[j]); 
			}
		}
	}
	cout << ans + 1;

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}