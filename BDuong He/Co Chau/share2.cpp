/*
Good luck for those who are trying your best
May the most glorious victory come
File name: share2.cpp
Code by : acident / lckintrovert
Created since : 18/08/2023 ~~ 10:23:17
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
int const maxn      =       200 + 10;
int const INF       =       1e18;
 
int n, sum = 0, x;
vector<pi> settings;
void solve() {
    cin >> n;
    settings.pb(mp(0,0));
    for(int i = 0;i < n; i++) {
        cin >> x;
        sum += x;
        for(int j = settings.size() - 1; j >= 0; j--) {
            settings.pb(mp(settings[j].fi + x, (settings[j].se | (1 << i))));
        }
    }
    int ans = sum;
    for(auto ptr1 : settings) {
        if(ptr1.fi < (sum + 2)/3 || ptr1.fi >= ans) continue;
        for(auto ptr2 : settings) {
            if(ptr2.fi <= ptr1.fi && (ptr2.fi) >= (sum - ptr1.fi+1)/2 && !(ptr1.se & ptr2.se)) ans = ptr1.fi;
        }
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("share.INP", "r", stdin);
    freopen("share.OUT", "w", stdout);
    solve();
}