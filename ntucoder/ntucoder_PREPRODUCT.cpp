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
#define maxn 100010

/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
int n;
vector<bool> isPrime(maxn, 0);
void eratos() {
	for(int i = 0; i < maxn; i++) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < maxn; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j < maxn; j += i) {
				isPrime[j] = false;
			}
		} 
	}
}

int sqr(int a) {
	return a * a % n;
}
int modPow(int k, int hat) {
	if(hat == 0) return 1;
	else if(hat == 1) return k % n;
	else {
		if(hat % 2 == 0) {
			return sqr(modPow(k, hat/2)) % n;
		} else return k * sqr(modPow(k, hat/2)) % n;
	}
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n;
	eratos();
	if(n == 1) {
		cout << "YES" << endl << 1;
	} else if(n == 4) {
		cout << "YES" << endl << "1 3 2 4";
	} else {
		if(!isPrime[n]) cout << "NO";
		else {
			cout << "YES" << endl;
			cout << 1 << ' ';
			int a = 1;
			for(int i = 2; i <= n - 1; i++) {
				cout << (i * modPow(i - 1, n - 2)) % n << ' ';
			}
			cout << n;
		}
	}
}