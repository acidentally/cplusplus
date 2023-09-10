/*
Good luck for those who are trying your best
May the most glorious victory come
File name: CF_977F.cpp
Code by : acident / lckintrovert
Created since : 31/08/2023 ~~ 14:45:31
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n, x;
map<int, int> m, idx, pre;
deque<int> q;
void solve() {
    cin >> n;
    pi ans = {0, 0};
    for(int i = 1; i <= n; i++) {
        cin >> x;
        idx[x] = i;
        if(m[x] != 0) m[x] = 1;
        if(m[x - 1] + 1 > m[x]) {
            m[x] = m[x - 1] + 1;
            pre[i] = idx[x - 1];
        }
        ans = max(ans, mp(m[x], i));
    }
    cout << ans.fi << endl;
    int st = ans.se;
    while(ans.fi--) {
        q.push_back(st);
        st = pre[st];
    }
    while(!q.empty()) {
        cout << q.back() << ' ';
        q.pop_back();
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/