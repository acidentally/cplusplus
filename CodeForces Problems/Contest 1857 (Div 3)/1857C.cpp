/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1857C.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 12:16:35
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
int const maxn      =       1e3 + 10;
int const INF       =       1e9 + 10;
 
int n, x;
void solve() {
    cin >> n;
    map<int, int> m;
    int k = n * (n - 1) / 2;
    int b[k + 10] = {}, maxi = -INF;
    vi check(n, -INF);
    for(int i = 1; i <= k; i++) {
        cin >> b[i];
        maxi = max(maxi, b[i]);
        m[b[i]]++;
    }
    priority_queue<pi> q;
    for(auto s : m) {
        // if(s.se <= n - 1 && check[s.se] == -INF) {check[s.se] = s.fi; continue;}
        q.push(mp(~s.fi, s.se));        
    }  
    while(!q.empty()) {
        int num = ~q.top().fi, cnt = q.top().se;
        // cerr << num << endl;
        q.pop();
        if(cnt <= n - 1 && check[cnt] == -INF) {
            check[cnt] = num;
        } else {
            for(int i = min(cnt, n - 1); i >= 1; i--) {
                if(check[i] == -INF) {
                    check[i] = num;
                    if(cnt - i > 0) q.push(mp(~num, cnt - i));
                    break;
                }
            }
        }
    }
    for(int i = n - 1; i >= 1; i--) cout << check[i] << ' ';
    cout << maxi << endl;
}   
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}