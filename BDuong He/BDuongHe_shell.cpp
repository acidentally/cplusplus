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
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

bool balls[3][3] = {};
int maxAns[3] = {};
int n, u, v, k;
void solve() {
	cin >> n;
	balls[0][0] = balls[1][1] = balls[2][2] = true;
	for(int i = 0; i < n; i++) {
		cin >> u >> v >> k;
		for(int j = 0; j < 3; j++) {
			swap(balls[j][u - 1], balls[j][v - 1]);
			maxAns[j] += balls[j][k - 1];
		}
	}
	cout << max(maxAns[0], max(maxAns[1], maxAns[2]));
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}