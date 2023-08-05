/*
Good luck for those who are trying your best
May the most glorious victory come
File name: xepbi.cpp
Code by : acident / lckintrovert
Created since : 05/08/2023 ~~ 09:45:58
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, x;
vi a;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        a.pb(x);
    }
    sort(all(a));
    int minans = INF, maxans = n - 1;
    vi::iterator ptr;
    for(int i = 0; i < n; i++) {
        int cur = a[i];
        ptr = lower_bound(all(a), cur + n - 1);
        if(ptr == a.end()) ptr--;
        if(*ptr > cur + n - 1) ptr--;
        int len = ptr - a.begin() - i + 1;
        minans = min(minans, n - len);
    }
    cout << minans << endl << maxans;
    return;
}   
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}