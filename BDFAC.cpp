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

vi primes, minPrime;
vector<bool> isPrime(1010, true);

void eratos() {
	for(int i = 0; i < 1010; i++) {
		isPrime.push_back(i);
		minPrime.push_back(i);
	}

	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i < 1010; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j < 1010; j += i) {
				isPrime[j] = false;
				if(minPrime[j] == j) minPrime[j] = i;
			}
		}
	}
	for(int i = 0; i < 1010; i++) {
		if(isPrime[i]) primes.push_back(i);
	}
}

void bdfac(int n) {
	map<int, int> _a;
	int cnt = 0;
	while(primes[cnt] <= n) {
		_a[primes[cnt++]]++;
	}
	int x;
	for(int i = 1; i <= n; i++) {
		x = i;
		while(x != 1) {
			_a[minPrime[x]]++;
			x /= minPrime[x];
		}
	}	

	for(map<int, int>::iterator i = _a.begin(); i != _a.end(); i++) cout << i -> second - 1;
	cout << endl;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

	eratos();
	// cout << primes[0] << ' ' << primes[1];
	// int tc; cin >> tc;
	int n;
	while(cin >> n) {
		bdfac(n);
	}
}