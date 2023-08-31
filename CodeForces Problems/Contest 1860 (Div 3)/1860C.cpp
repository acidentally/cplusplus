/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1860C.cpp
Code by : acident / lckintrovert
Created since : 24/08/2023 ~~ 21:50:14
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
int a[maxn] = {};
vi s;
void solve() {
    cin >> n;
    s.clear();
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(a[1] != n) {
        NO
        return;
    }
    int h = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] == a[i - 1]) {
            h++;
            continue;
        }
        else {
            int reCur = a[i - 1] - a[i];
            // cout << reCur << endl;
            while(reCur--) s.pb(h);
            h++;
        }
    }
    s.pb(h);
    int id = n;
    for(auto u : s) {
        if(u != a[id]) {
            NO
            return;
        }
        id--;
    }
    YES
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}