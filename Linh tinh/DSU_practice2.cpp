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

vi p;
vi sizes, mini, maxi;
int n, m;


//https://codeforces.com/edu/course/2/lesson/7/1/practice
void startUp() {
	p.resize(n + 1);
	sizes.resize(n + 1);
	mini.resize(n + 1);
	maxi.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		mini[i] = i;
		maxi[i] = i;
		sizes[i] = 1;
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
		sizes[x] += sizes[y];
		sizes[y] = sizes[x];	
		mini[x] = min(mini[x], mini[y]);
		maxi[x] = max(maxi[x], maxi[y]);
	}	
}
void get(int x) {
	x = find(x);
	cout << mini[x] << ' ' << maxi[x] << ' ' << sizes[x] << endl;
}
void solve() {
	cin >> n >> m;
	startUp();
	string s; int x, y;
	while(m--) {
		cin >> s;
		if(s == "union") {
			cin >> x >> y;
			unionS(x, y);
		}
		else {
			cin >> x;
			get(x);
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}