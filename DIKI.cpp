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

const int maxn = (int)1e5 + 5;

int n, m, k;
bool found = false;
int a[maxn];

void solve(int l, int r, int sum) {
	// cout << l << ' ' << r << ' ' << sum << endl;
	// if(sum < 0) return;
	// cout << sum << endl;
	if(l == r) {
		if(sum == a[l]) {
			cout << min(sum, k) << ' ' << max(sum, k);
			found = true;
		} 	
		return;
	}
	int mid = (l + r)/2;
	if(a[mid] == sum) {
		cout << min(sum, k) << ' ' << max(sum, k);
		found = true;
		return;
	}
	else if(a[mid] > sum) {
		r = mid;
		solve(l, r, sum);
	} else {
		l = mid + 1;
		solve(l, r, sum);
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		// cout << a[i] << endl;
	}
	for(int i = 0; i < n; i++) {
		// cout << a[i] << ' ';
		k = a[i];
		solve(0, n - 1, m + a[i]);
		if(found) break;
	}
	if(!found) cout << -1;
}
