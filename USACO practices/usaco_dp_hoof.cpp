/*
Good luck for those who are trying your best
May the most glorious victory come
File name: usaco_dp_hoof.cpp
Code by : acident / lckintrovert
Created since : 04/08/2023 ~~ 14:02:43
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

int n, k;
char x;
void solve() {
	cin >> n >> k;
	map<char, int> f;
	f['H'] = 0; f['P'] = 1; f['S'] = 2;
	//This map each "gesture char" to its respective value
	//And the reason I map them this way is for them to be "sorted"
	//in a way that if char a wins char b : f[a] = f[b] + 1.
	//e.g Paper wins Hoof : f[Paper] = f[Hoof] + 1.

	//And you can understand f['h'] = 3 but since we only care about
	//winning, taking modulo 3 would be abundant.
	int dp[n + 1][4][30] = {};
	//dp[i][c][k] tells us that at index i in the game, Bessie has already
	//changed her gestures k times and her current gesture is the one mapped to
	//value c - 1. And you'll see later why it's c - 1.

	cin >> x;
	//Input the index 1 first cus it's **s p e c i a l**
	dp[1][f[x] + 1][0] = 1;
	//Since f[x] + 1 is the integer dedicated to win f[x], we have our
	//fundamental state of this dp, which is at index 1, Bessie has changed 
	//her gesture 0 times, and now currently have the gesture which points to
	//f[x] + 1.
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		cin >> x;
		dp[i][1][0] = dp[i - 1][1][0];
		dp[i][2][0] = dp[i - 1][2][0];
		dp[i][3][0] = dp[i - 1][3][0];
		//All the special cases goes first
		dp[i][f[x] + 1][0]++;
		//And we want to update our win cases;
		ans = max(ans, dp[i][1][0]);
		ans = max(ans, dp[i][2][0]);
		ans = max(ans, dp[i][3][0]);
		//And also our answer.

		for(int K = 1; K <= min(k, i - 1); K++) {
			//Since after i index, the maximum changes you can do
			//is i - 1 ~~ aka you can't change k times if you're only 
			//at index k.
			dp[i][1][K] = max(dp[i - 1][2][K - 1], dp[i - 1][3][K - 1]);
			dp[i][2][K] = max(dp[i - 1][3][K - 1], dp[i - 1][1][K - 1]);
			dp[i][3][K] = max(dp[i - 1][1][K - 1], dp[i - 1][2][K - 1]);
			//Update every value points.
			if(K < i - 1) { //K < i - 1 since we want to update our current
				//index to the dp of our previous index, and using the same
				//logic as above, you can't already changed i - 1 times 
				//after i - 1 index. Hence K < i - 1;
				dp[i][1][K] = max(dp[i][1][K], dp[i - 1][1][K]);
				dp[i][2][K] = max(dp[i][2][K], dp[i - 1][2][K]);
				dp[i][3][K] = max(dp[i][3][K], dp[i - 1][3][K]);
			}
			dp[i][f[x] + 1][K]++; //f[x] + 1 wins x, so the wins of
			//index i after changed K times to f[x] + 1 should be increased 
			//by 1.
			//This part should be self-explanatory
			ans = max(ans, dp[i][1][K]);
			ans = max(ans, dp[i][2][K]);
			ans = max(ans, dp[i][3][K]);
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
    freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
 	solve();
}