/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dub double
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int const maxn = 1e9 + 7;
int const maxn2 = 100*maxn;
int n, a, b, c;
map< pair<int, int>, int > mp;
void solve() {
	cin >> n;
	while(n--) {
		cin >> a >> b >> c;
		if(!a && !b && !c) continue;
		if(a == 0) mp[{0, 1}]++;
		else if(b == 0) mp[{1, 0}]++;
		else mp[{a/__gcd(a, b), b/__gcd(a, b)}]++;
	}
	vi vec, preSum;
	int prefixSum = 0, sqSum = 0, ans = 0, temp, prexuli;
	for(auto i : mp) {
		temp = i.se % maxn;
		prexuli = (prefixSum * prefixSum % maxn - sqSum % maxn) % maxn;
		ans += ((temp * prexuli % maxn) * 500000004) % maxn;
		prefixSum = (prefixSum + temp) % maxn;
		sqSum += temp * temp % maxn;
	}
	while(ans < 0) ans += maxn;
	cout << ans % maxn;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}