
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

int n, x;
bool check[maxn] = {};
void solve() {
	cin >> n;
	int cnt[maxn] = {};
	for(int i = 1; i <= 2 * n; i++) {
		cin >> x;
		cnt[x]++;
		check[x] = true;
	}
	int mex = 1;
	while(check[mex]) mex++;
	for(int i = 1; i < mex; i++) {
		if(cnt[i] < 2) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}