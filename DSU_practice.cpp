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
int n, m;

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
	if(x != y) p[y] = x;
}
void get(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) cout << "YES" << endl;
	else cout << "NO" << endl;
}
void solve() {
	cin >> n >> m;
	startUp();
	string s; int x, y;
	while(m--) {
		cin >> s >> x >> y;
		if(s == "union") unionS(x, y);
		else get(x, y);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}