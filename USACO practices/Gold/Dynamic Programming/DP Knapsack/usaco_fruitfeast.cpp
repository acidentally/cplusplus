/*
Good luck for those who are trying your best
May the most glorious victory come
File name: usaco_fruitfeast.cpp
Code by : acident / lckintrovert
Created since : 23/08/2023 ~~ 15:07:50
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
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       5e6 + 10;
int const INF       =       1e18;
 
int T, A, B, ans = 0;
bool poss[maxn] = {};
vi a;
void solve() {
    cin >> T >> A >> B;
    poss[A] = 1;
    poss[B] = 1;
    for(int i = 1; i <= T; i++) {
        if(poss[i]) {
            a.pb(i);
            ans = i;
            if(i + A <= T) poss[i + A] = 1;
            if(i + B <= T) poss[i + B] = 1;
        }
    }
    for(auto s : a) {
        vi::iterator ptr = lower_bound(all(a), T - s/2);
        if(ptr == a.begin() && s/2 + *ptr > T) continue;
        if(s/2 + *ptr > T || ptr == a.end()) ptr--;
        ans = max(ans, s/2 + *ptr);
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/