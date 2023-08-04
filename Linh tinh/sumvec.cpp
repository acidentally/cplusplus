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

int n, a, b;
typedef pair<int, int> pi;
vector<pair<int, int> > vecs;
void solve() {
	cin >> n;
	int x = 0, y = 0;
	pair<int, int> dp[n + 1];
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		vecs.push_back({a, b});
	}
	
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}