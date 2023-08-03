/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int const maxn = 4194319;
bitset<maxn> isPrime;
vi primes;
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
int n, tc, k;
void solve() {
	cin >> n >> k;
	int curSum = 1;
	for(int i = 0; i < k; i++) {
		curSum *= primes[i];
	}
	if(curSum > n) {
		cout << -1 << endl;
		return;
	}
	int l = 0, r = k, preSum = curSum;
	while(curSum <=  n) {
		preSum = curSum;
		if(curSum / primes[l] * primes[r] > curSum) 
			curSum = curSum / primes[l] * primes[r];
		else break;
		l++; r++;
	}
	cout << preSum << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	sieve();
	cin >> tc; 
	while(tc--) solve();
}