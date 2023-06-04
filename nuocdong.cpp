#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector <int> >
#define endl '\n'
#define fr(i, a, b) for(int i = a; i < b; i++)

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n; int cinTemp;
	vi a;
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		a.push_back(cinTemp);
	}
	int l[n], r[n];
	l[0] = a[0]; r[n - 1] = a[n - 1];
	for(int i = 1; i < n; i++) {
		l[i] = max(l[i - 1], a[i]);
	}
	
	for(int i = n - 2; i > 0; i--) {
		r[i] = max(r[i + 1], a[i]);
	}

	int res = 0;
	for(int i = 0; i < n; i++) {
		int temp = min(l[i], r[i]);
		if(temp > a[i]) res += temp - a[i];
	}
	cout << res;
}