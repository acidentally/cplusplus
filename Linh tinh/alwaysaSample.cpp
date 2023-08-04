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

vi a;
int const maxn = 1e6;
vi minPrime(maxn + 100);

int cinn() {
	int n; cin >> n; return n;
}

void eratos() {
	for(int i = 0; i <= maxn; i++) {
		minPrime[i] = i;
	}
	for(int i = 2; i * i <= maxn; i++) {
		if(minPrime[i] == i) {
			// minPrime[i] = i;
			for(int j = i * i; j <= maxn; j += i) {
				if(minPrime[j] == j)
				minPrime[j] = i;
			}
		}
	}
	return;
}

bool have[maxn + 9] = {};

void solve(int x) {
	vi prime; int tam = x;
	if(x <= 3) {
		cout << "NO"; return;
	}
	while(x != 1) {
		if(prime.size() == 0) prime.push_back(minPrime[x]);
		else if(minPrime[x] > prime[prime.size() - 1]) {
			prime.push_back(minPrime[x]);
		}
		// cout << minPrime[x] << ' ';
		x /= minPrime[x];
		
	}
	int temp, i;

	for(i = 0; i < (int)prime.size(); i++) {
		for(int j = i; j < prime.size(); j++) {
			if(tam % (prime[i] * prime[j]) == 0) {
				temp = tam / prime[i] / prime[j];

				if(have[temp]) {
					// cout << prime[i] << ' ' << prime[j] << ' ';
					cout << "YES"; 
					return;
				}

			}
		}
	}
	cout << "NO";
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);

	int n, q, x;
	cin >> n >> q;

	eratos();

	fr(i,0,n) {
		cin >> x;
		if(x == 1) continue;
		int oi = x;
		while(oi <= maxn) {
			have[oi] = true;
			oi *= x;
		}

	}
	
	have[1] = true;

	fr(i,0,q) {
		cin >> x;
		solve(x);
		cout << endl;
	}

	// cout << minPrime[];
	// cout << minPrime[4];

}