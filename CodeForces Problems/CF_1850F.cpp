/*
Good luck for those who are trying your best
May the most glorious victory come
File name: CF_1850F.cpp
Code by : acident / lckintrovert
Created since : 26/09/2023 ~~ 09:59:35
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

int n, x;
int cnt[maxn] = {}, ans[maxn] = {};
inline void solve() {
	cin >> n;
	int realAns = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(x > n) continue;
		cnt[x]++;
	}
	for(int i = 1; i <= n; i++) {
		if(cnt[i]) {
			for(int j = i; j <= n; j += i) ans[j] += cnt[i];
		}
	}
	for(int i = 1; i <= n; i++) maximize(realAns, ans[i]);
	cout << realAns << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//File?
	int tc; cin >> tc;
	while(tc--) solve();
}

/*A place to scribble thoughts

*/