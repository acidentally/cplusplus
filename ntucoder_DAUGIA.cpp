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
#define maxn 100100

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

vector<bool> isPrime(maxn, 0);

void eratos() {
	for(int i = 0; i < maxn; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i * i < maxn; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j < maxn; j += i) {
				isPrime[j] = false;
			}
		}
	}

}

bool palin(int k) {
	string s = "";
	while(k) {
		s = char((k % 10) + 48) + s;
		k /= 10;
	}
	for(int i = 0; i < s.size()/2; i++) {
		if(s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;	
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int a, b; cin >> a >> b;
	eratos();
	int ans = 0;
	for(int i = a; i <= b; i++) {
		if(isPrime[i] && palin(i)) ans++;
	}
	// cout << isPrime[2];
	cout << ans;
}