/*
Good luck for those who are trying your best
May the most glorious victory come
File name: DAYNGO3.cpp
Code by : acident / lckintrovert
Created since : 07/09/2023 ~~ 11:55:12
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
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define ins                 insert
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef pair<int, int>      pi;
int const maxn      =       2e5 + 10;

pi BIT[maxn] = {};
pi query(int k) {
    pi res = {0, 0};
    while(k > 0) {
        res.fi += BIT[k].fi;
        res.se += BIT[k].se;
        k -= k & -k;
    }
    return res;
}
void upd(int k) {
    int p = k;
    while(k <= maxn) {
        BIT[k].fi++;
        BIT[k].se += p;
        k += k & -k;
    }
}
int d = (int)1e5 + 5, ans;
char c;
pi cur;
void solve() {
    cin >> ans;
    ans = 0;
    upd(d);
    while(cin >> c) {
        if(c == '(') d++;
        else d--;

        cur = query(d - 1);
        ans += cur.fi * d - cur.se;
        upd(d);
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