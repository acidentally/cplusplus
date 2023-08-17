/*
Good luck for those who are trying your best
May the most glorious victory come
File name: tsnt.cpp
Code by : acident / lckintrovert
Created since : 15/08/2023 ~~ 14:11:46
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
int const maxn      =       5e5 + 10;
int const INF       =       1e18;
int const intLim    =       1e6 + 10;
 
vi minPrime(intLim + 10, 0);
void eratos() {
    minPrime[0] = minPrime[1] = 1;
    for(int i = 2; i * i <= intLim; i++) {
        if(minPrime[i] == 0) {
            for(int j = i * i; j <= intLim; j += i) {
                if(minPrime[j] == 0) minPrime[j] = i;
            }
        }
    }
    for(int i = 1; i <= intLim; i++) {
        if(minPrime[i] == 0) minPrime[i] = i;
    }
}
int n, x;
void solve() {
    cin >> n;
    int ans = 0, maxi = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        int cur = 0;
        while(x > 1) {
            x /= minPrime[x];
            cur++;
        }
        ans += cur;
        maxi = max(maxi, cur);
    }
    cout << ans - maxi;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    eratos();
    solve();
}