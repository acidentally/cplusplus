/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define fif 			first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const maxn 		= 	2e5 + 10;

int n, u, v, w, v_, w_;
int mini[maxn] = {0}, maxi[maxn] = {0};
int mainMini[maxn] = {0}, mainMaxi[maxn] = {0};
int curVal[maxn] = {0};
int cnt = 2;
char x;
void update(int cur, int pre, int weight) {
	curVal[cur] = curVal[pre] + weight;

	mini[cur] = min(curVal[cur], mini[pre]);
	maxi[cur] = max(curVal[cur], maxi[pre]);

	mainMini[cur] = min(mainMini[pre], curVal[cur] - maxi[pre]);
	mainMaxi[cur] = max(mainMaxi[pre], curVal[cur] - mini[pre]);
}
void solve() {
	cin >> n;
	update(1, 0, 1);
	cnt = 2;
	while(n--) {
		cin >> x;
		if(x == '+') {
			cin >> v_ >> w_;
			update(cnt, v_, w_);
			++cnt;
		} else if(x == '?'){
			cin >> u >> v >> w;
			if((mainMini[v] <= w && w <= mainMaxi[v]) || w == 0) YES 
			else NO
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}