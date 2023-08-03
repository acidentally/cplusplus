#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector <int> >
#define endl '\n'
#define fr(i, a, b) for(int i = a; i < b; i++)

int sqr(int x) {
	return x * x % 998244353;
}

int moduInverse(int i, int b, int mod) {
	if(b == 0) return 1;
	else if(b == 1) return i;
	else {
		if(b % 2 == 0) return sqr(moduInverse(i, b/2, mod)) % mod;
		else if(mod % 2 == 1) return i * sqr(moduInverse(i, b/2, mod)) % mod;
	}
}

int com(int n, int mod) {
	int res = 1, cnt = 1;

 	for(int i = n/2 + 1; i <= n; i++) {
 		res = (res % 998244353) * i % 998244353;
 		res = (res % 998244353) * moduInverse(cnt, mod - 2, mod) % 998244353;
 		cnt++;
 	}
 	return res;
}

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int cinTemp;
	set<int> temp;
	vector< set<int> > a;
	vi values;

	int res = com(n/3, 998244353); 
	for(int i = 0; i < n; i++) {
		cin >> cinTemp;
		values.push_back(cinTemp);
		temp.insert(cinTemp);
		if((i + 1)% 3 == 0) {
			a.push_back(temp);
			temp.clear();
		}
	}

	int minmin;
	int mintemp = 0;

	for(int i = 0; i < n/3; i++) {
		if(a[i].size() == 1) {
			res = (res * 3) % 998244353;
			// cout << a[i].size() << endl;
		} else if(a[i].size() == 2) {
			// cout << a[i].size() << endl;
			minmin = min(values[3*i + 0], min(values[3*i + 1], values[3*i + 2]));
			
			if(values[3*i + 0] == minmin) mintemp += 1;
			if(values[3*i + 1] == minmin) mintemp += 1;
			if(values[3*i + 2] == minmin) mintemp += 1;
			
			if(mintemp == 2) res = (res * 2) % 998244353;
			mintemp = 0;
		} else continue;
	}

	cout << res;
}