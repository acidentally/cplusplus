/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define dub 			double
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				emplace_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define ins 			insert

typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;

int const maxn 		= 	1e5 + 10; 
int const INF 		= 	LLONG_MAX;

int compute(multiset<int> mor, multiset<int> les) {
	if(mor.empty() || les.empty()) return 0;
	multiset<int>::iterator m = mor.begin(), l = les.begin();
	int res = 0;
	while(m != mor.end() && l != les.end()) {
		if(*m >= *l) l++;
		else {
			res++;
			m++;
			l++;
		}
	}
	return res;
}

int n, x;
multiset<int> posNam, posNu, negNam, negNu;
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x > 0) posNam.ins(x);
		else negNam.ins(-x);
	}
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x > 0) posNu.ins(x);
		else negNu.ins(-x);
	}
	int ans = compute(posNam, negNu);
	ans += compute(posNu, negNam);
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("PLEASE.INP", "r", stdin);
	freopen("PLEASE.OUT", "w", stdout);
 	solve();
}