/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Bai1.cpp
Code by : acident / lckintrovert
Created since : 04/09/2023 ~~ 13:41:11
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
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       50;
int const INF       =       1e18;
 
int n;
char a[maxn][maxn];
bool check(int i, int j) {
    char c = a[i][j];
    if(a[i + 1][j] == c && a[i + 2][j] == c) {
        return 1;
    }
    if(a[i][j + 1] == c && a[i][j + 2] == c) {
        return 1;
    }
    if(a[i + 1][j + 1] == c && a[i + 2][j + 2] == c) {
        return 1;
    }
    return 0;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n + 2; i++) {
        for(int j = 1; j <= n + 2; j++) {
            if(i > n || j > n) {
                a[i][j] = '.';
                continue;
            }
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] == '.') continue;
            if(check(i, j)) {
                cout << a[i][j];
                return;
            }
        }
    }
    cout << "ongoing";
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("tictac.inp", "r", stdin);
    // freopen("tictac.out", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/