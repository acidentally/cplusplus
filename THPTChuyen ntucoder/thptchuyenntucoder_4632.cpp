/*
Good luck for those who are trying your best
May the most glorious victory come
File name: thptchuyenntucoder_4632.cpp
Code by : acident / lckintrovert
Created since : 01/09/2023 ~~ 17:08:49
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
int const maxn      =       1e5 + 10;
int const INF       =       -1e15;
 
int n, a, b, c, ans = INF;
void solve() {
    cin >> n;
    n -= 2;
    cin >> a >> b;
    pi cur = mp(max(a, b), min(a, b));
    while(n--) {
        cin >> c;
        ans = max(ans, cur.fi + cur.se - c);
        cur.se = max(cur.se, c);
        if(cur.se > cur.fi) swap(cur.se, cur.fi);
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/