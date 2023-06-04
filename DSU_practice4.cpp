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
int p[10010];
int tc, x, y, t;

void startUp() {
	for(int i = 1; i <= 10000; i++) {
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
bool get(int x, int y) {
	x = find(x);
	y = find(y);
	if(x != y) return 0;
	else return 1;
}
void solve() {
	cin >> tc;
	startUp();
	while(tc--) {
		cin >> x >> y >> t;
		if(t == 1) {
			unionS(x, y);
		} else if(t == 2) {
			cout << get(x, y) << endl;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}