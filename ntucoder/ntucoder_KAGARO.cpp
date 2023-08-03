/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/

int cinn() {
	int n; cin >> n;
	return n;
}

void solve(int a, int b, int n) {
	int ans = n/b, sum = n/b * b;
	ans += (n - sum)/a; sum += (n - sum) / a * a;
	int countB = ans;
	// cout << countB << endl;
	// cout << sum << endl;
	while(sum + a != n && sum != n) {
		// cout << sum + a << endl;
		sum -= b;
		countB--;
		ans--;
		while(sum + a <= n) {
			sum += a;
			ans++;
		}
		if(countB < 0) {
			cout << -1; return;
		}
	}
	cout << ans;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

	int n, a, b; cin >> n >> a >> b;
	int sum = a + b;
	a = min(a, b);
	b = sum - a;

	solve(a, b, n);
}