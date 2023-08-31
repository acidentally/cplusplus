/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1860A.cpp
Code by : acident / lckintrovert
Created since : 24/08/2023 ~~ 21:35:30
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
int const maxn      =       100;
int const INF       =       1e18;
 
int n, m;
char x;
void solve() {
    cin >> n >> m;
    bool col[30][26] = {};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> x;
            col[j][x - 'a'] = true;
        }
    }
    int id = 3;
    char com[4] = {'v', 'i', 'k', 'a'};
    for(int j = m; j >= 1 && id >= 0; j--) {
        if(col[j][com[id] - 'a']) id--;
    }
    // cerr << id << endl;
    if(id < 0) YES
    else NO
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}