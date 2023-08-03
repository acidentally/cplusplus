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


//https://codeforces.com/edu/course/2/lesson/7/1/practice
vi p;
int n, m, k;
typedef pair<int, int> pi;

void startUp() {
	p.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
}
int find(int x) {
	if(x != p[x]) 
	p[x] = find(p[x]);
	return p[x];
}
void unionS(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) {
		p[y] = x; 
	}
}
deque<string> ans;
void get(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) ans.push_back("NO");
	else ans.push_back("YES");
}
void solve() {
	cin >> n >> m >> k;
	startUp();
	vector<string> q; vector< pi > _q;

	string s; int x, y;
	while(m--) {
		cin >> x >> y;
	}

	while(k--) {
		cin >> s >> x >> y;
		q.push_back(s);
		_q.push_back({x, y});
	}
	while(!q.empty() && !_q.empty()) {
		if(q.back() == "ask") {
			x = _q.back().fi;
			y = _q.back().se;
			get(x, y);
		}
		else {
			x = _q.back().fi;
			y = _q.back().se;
			unionS(x, y);
		}
		q.pop_back();
		_q.pop_back();
	}
	while(!ans.empty()) {
		cout << ans.back() << endl;
		ans.pop_back();
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}