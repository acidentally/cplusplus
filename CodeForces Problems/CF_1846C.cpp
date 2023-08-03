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
typedef pair<int, int> pi;

bool cmp(pi& a, pi& b) {
	if(a.fi == b.fi) return a.se < b.se;
	return a.fi > b.fi;
}

int n, m, h, t;
void solve() {
	cin >> n >> m >> h;
	vector<pi> a;
	for(int i = 1; i <= n; i++) {
		priority_queue< int, vector<int>, greater<int> > qe;
		for(int j = 0; j < m; j++) {
			cin >> t;
			qe.push(t);
		}
		int cnt = 0, time = 0, pen = 0;
		while(!qe.empty()) {
			time += qe.top();
			if(time <= h) {
				cnt++;
				pen += time;
				qe.pop();
			}
			else {
				break;
			}
		}
		a.push_back({cnt, pen});
	}
	pi Ru = a[0];
	// cout << Ru.fi << ' ' << Ru.se << endl;
	sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < a.size(); i++) {
		// cout << a[i].fi << ' ' << a[i].se << endl;
		if(a[i] == Ru) {
			cout << i + 1 << endl;
			return;
		}
	}
	cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >>tc;
	while(tc--)
	solve();
}