/*
Good luck for those who are trying your best
May the most glorious victory come
File name: tc.cpp
Code by : acident / lckintrovert
Created since : 17/08/2023 ~~ 14:02:40
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 

vi minPrime(maxn, 0), primes;
void eratos() {
    minPrime[0] = minPrime[1] = 1;
    for(int i = 2; i * i <= maxn; i++) {
        if(minPrime[i] == 0) {
            for(int j = i * i; j <= maxn; j += i) {
                if(minPrime[j] == 0) minPrime[j] = i;
            }
        }
    }
    for(int i = 2; i <= maxn; i++) {
        if(minPrime[i] == 0) {
            primes.pb(i);
            minPrime[i] = i;
        }
    }
}
int sqr(int k) {
    return (k * k) % 10;
}
int modPow(int a, int k) {
    if(k <= 0) return 1;
    if(k == 1) return a;
    if(k & 1) return (a * sqr(modPow(a, k >> 1))) % 10;
    return sqr(modPow(a, k >> 1));
}
int n;
int primeCount[maxn] = {};
int F[maxn] = {};
map<int, int> m;
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    eratos();
    int ans = 1;
    F[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        m.clear();
        int cur = i;
        while (cur > 1)
        {
            m[minPrime[cur]]++;
            cur /= minPrime[cur];
        }
        for (auto s : m)
        {
            if(s.fi != 2 && s.fi != 5) ans = (ans * modPow(s.fi, s.se - primeCount[s.fi])) % 10;
            primeCount[s.fi] = max(primeCount[s.fi], s.se);
        }
        cur = ans;
        cur = cur * modPow(2, primeCount[2] - primeCount[5]) * modPow(5, primeCount[5] - primeCount[2]) % 10;
        F[i] = cur;
    }

    while(cin >> n) cout << F[n] << endl;
}