#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector <int> >
#define endl '\n'
#define fr(i, a, b) for(int i = a; i < b; i++)



void solve(int n) {
	pair<int, int> s[200];
	int res = 0;
	int idx = 0;
	int dem[200];
	int a, p;
	s[0] = make_pair(0,0);
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			a = i; p = 0;
			while(n % i == 0) {
				n /= i;
				p++;
			}
			s[++idx] = make_pair(p, a);
		}
	}
	if(n != 1) s[++idx] = make_pair(1, n);
	sort(s + 1, s + idx + 1);
	dem[idx + 1] = 1;
	for(int i = idx; i >= 1; i--) {
		dem[i] = dem[i + 1] * s[i].se;
	}
	int ans = 0; int lmao = 0;
	for(int i = 1; i <= idx; i++) {
		if(s[i].fi != s[i - 1].fi) ans += dem[i] * (s[i].fi - s[i - 1].fi), lmao += 1;
	}

	cout << ans << endl;

}

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		solve(n);
	}
}