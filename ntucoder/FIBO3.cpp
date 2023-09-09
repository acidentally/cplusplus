/*
Good luck for those who are trying your best
May the most glorious victory come
File name: FIBO3.cpp
Code by : acident / lckintrovert
Created since : 08/09/2023 ~~ 15:54:08
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
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
 
typedef vector<int>         vi;
typedef vector<vi>          vii;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       111539786;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
struct matrix {
    vii a = {{1, 1}, {1, 0}};
    matrix() = default;
} Id;
matrix mul(matrix x, matrix y) {
    matrix ans;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ans.a[i][j] = 0ll;
            for(int k = 0; k < 2; k++) {
                (ans.a[i][j] += x.a[i][k] * y.a[k][j] % mod) %= mod;
            }
        }
    }
    return ans;
}
matrix exp(int k, matrix x) {
    if(k <= 0) return Id;
    if(k == 1) return x;
    if(k & 1) {
        return mul(x, exp(k >> 1, mul(x, x)));
    }
    else return exp(k >> 1, mul(x, x));
}
int n;
void solve() {
    Id.a[0][0] = Id.a[1][1] = 1;
    Id.a[1][0] = Id.a[0][1] = 0;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl; return;
    }
    if(n == 2) {
        cout << 2 << endl; return;
    }

    matrix A;
    A = exp(n - 1, A);
    cout << (A.a[0][0] + A.a[0][1]) % mod << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--)     solve();
}

/*A place to scribble thoughts
*/