/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1859C.cpp
Code by : acident / lckintrovert
Created since : 12/08/2023 ~~ 22:30:00
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
int const maxn      =       1000;
int const INF       =       1e18;
 
int n;
void solve() {
    cin >> n;
    if(n == 2) cout << 2;
    else if(n == 3) cout << 7;
    else if(n == 4) cout << 17;
    else {
        int ans = 0;
        for(int i = 1; i <= n - 3; i++) ans += i * i;
        ans += (n - 1) * (n - 1) + n * (n - 2);
        cout << ans;
    }
    cout << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}