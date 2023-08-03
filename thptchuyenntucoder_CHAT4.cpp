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



int m, n, k;
int solve(int l, int r) {
	if(l == r) return l;
	int mid = (l + r)/2, mini = min(m, n), maxi = max(m, n);
	int cnt = 0, i = 1;
	while(mid/i != 0 && i <= mini) {
		cnt += min(mid/i, maxi);
		i++;
	}
	// cout << cnt << endl;
	
	if(cnt > k) {
		return solve(l, mid);
	}
	if(cnt == k) {
		return mid;
	}
	if(cnt < k) {
		return solve(mid + 1, r); 
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n >> m >> k;
	cout << solve(1, m*n);
	return 0;
}
