/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

vector<bool> isPrime(maxn, 1);
/*vi primes;
//This is optional whether you need a primes vector
*/
void eratos() {
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i * i <= maxn; i++) {
		if(isPrime[i]) {
			for(int j = i * i; j <= maxn; j += i) {
				isPrime[j] = 0;
			}
		}
	}
/*
//This is optional whether you need a primes vector
	for(int i = 2; i <= maxn; i++) if(isPrime[i]) primes.pb(i);
*/
}

void solve() {

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	eratos();
 	solve();
}