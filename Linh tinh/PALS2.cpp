#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<int, int>
#define endl '\n'
#define fi first
#define se second
#define pub push_back
#define pob pop_back
#define vi vector<int>
#define vii vector< vector<int> >
#define st stack<int>
#define prqueue priority_queue
#define emb emplace_back

int dp[1 << 10];

signed main() {

	ios_base:: sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	// freopen("pals.inp", "r", stdin);
	// freopen("pals.out", "w", stdout);
	int n;
	cin >> n;
	vector <int> ls;
	for (int i = 1; i <= n; i++){
		int mask = 0;
		int x;
		cin >> x;
		while(x){
			mask = mask | (1 << (x % 10));
			x /= 10;
		}
		ls.push_back(mask);
		dp[mask]++;
	}

	for (int i = 0; i < 10; i++){
		for (int mask = 0; mask < (1 << 10); mask++){
			if (mask & (1 << i)){
				dp[mask] += dp[mask xor (1 << i)];
			}
		}
	}

	int res = n * (n - 1);

	for (auto i: ls){
		int mask = (1 << 10) - 1;
		mask = mask xor i;
		res -= dp[mask];
	}

	cout << res / 2 << endl;
}

/*
1010
11
13
33

*/