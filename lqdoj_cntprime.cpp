	/*Good luck for those who are trying your best
	May the most glorious victory come*/

	#include <bits/stdc++.h>
	using namespace std;

	#define int long long
	#define fi first
	#define se second
	#define vi vector<int>
	#define vvi vector< vector<int> >
	#define endl '\n'

	int const maxn = 2e8 + 10;
	bitset<maxn> isPrime;
	vector<int> primes;
	int q, a, b;
	void sieve() {
		int sqrtn = sqrt(maxn);
		for(int i = 2; i <= maxn; i += 2) {
			isPrime[i] = 1;
		}
		primes.push_back(2);
		for(int i = 3; i <= maxn; i++) {
			if(!isPrime[i]) {
				primes.push_back(i);
				for(int j = i * i; j <= maxn; j += 2 * i) {
					isPrime[j] = true;
				}
			}
		}
		for(int i = primes.back() + 1; i <= maxn; i++) {
			if(!isPrime[i]) primes.push_back(i);
		}
	}
	void solve() {
		cin >> q;
		sieve();
		while(q--) {
			cin >> a >> b;
			if(a > b) {
				cout << 0 << endl;
				continue;
			}
			int p1 = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
	        int p2 = upper_bound(primes.begin(), primes.end(), b) - primes.begin();
	        cout << p2 - p1 << endl;
		}
	}
	signed main() {
		ios_base:: sync_with_stdio(0);
		cin.tie(NULL); cout.tie(NULL);
		solve();
		cout << *lower_bound(primes.begin(), primes.end(), 4194320);
	}