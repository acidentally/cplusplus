/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1133D.cpp
Code by : acident / lckintrovert
Created since : 18/08/2023 ~~ 17:05:14
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n;
map<pi, int> mNeg, mPos;
pi compute(int b, int a) {
    a = max(a, -a); b = max(b, -b);
    //d == b / a
    int k = __gcd(a, b);
    return mp(b/k, a/k);
}
int a[maxn] = {}, b[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int k = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0 && b[i] != 0) continue;
        if(a[i] == 0 && b[i] == 0) k++;
        else if(a[i] * b[i] >= 0) mPos[compute(b[i], a[i])]++;
        else mNeg[compute(b[i], a[i])]++;
    }
    int ans = 0;
    for(auto s : mPos) ans = max(ans, s.se);
    for(auto s : mNeg) ans = max(ans, s.se);
    cout << ans + k;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}