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

int const maxn = 1e6;
int n, u, s, x;
vector<bool> isPrime(1e9 + 5, 0);
vi primes;
void cinn() {
	cin >> n;
}
void eratos() {
	for(int i = 0; i <= n; i++) {
		isPrime[i] = 1;
	}
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i * i <= maxn; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j <= maxn; j += i) {
				isPrime[j] = 0;
			}
		}
	}	
	for(int i = 0; i <= n; i++) {
		if(isPrime[i]) primes.push_back(i);
	}
}
void solve() {
	cin >> x;
	set<int> a;	
	for(int i = 0; i < primes.size(); i++) {
		if(x % primes[i] == 0) {
			a.insert(primes[i]);
			while(x % primes[i] == 0) x /= primes[i];
		}
	}
	bool check = true;
	s = a.size();
	for(int i = 1; i < n && check; i++) {
		cin >> x;
		for(int j = 0; j < primes.size(); j++) {
			if(x % primes[j] == 0) {
				a.insert(primes[j]);
				while(a.size() == s && x % primes[j] == 0) x /= primes[j];
			}
		}
		if(x != 1) a.insert(x);
		if(a.size() != s) check = false;
	}

	if(check) cout << "YES";
	else cout << "NO";
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cinn();
	eratos();
	solve();
}