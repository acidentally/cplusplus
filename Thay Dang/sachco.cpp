/*
Good luck for those who are trying your best
May the most glorious victory come
File name: sachco.cpp
Code by : acident / lckintrovert
Created since : 18/09/2023 ~~ 14:09:24
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;

int n, k, smallest = 100;
char x;
vi og;
bool check[30] = {};
inline void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        check[x - 'a'] = 1;
        og.pb(x - 'a');
        minimize(smallest, x - 'a');
    }
    cin >> k;
    if(k > n) {
        for(int i = 0; i < n; i++) cout << (char)(og[i] + 'a');
        for(int i = n; i < k; i++) cout << (char)(smallest + 'a');
        return;
    }
    int change = k - 1;
    bool cur = 1;
    for(int i = k - 1; i >= 0 && cur; i--) {
        for(int j = og[i] + 1; j < 26; j++) {
            if(check[j]) {
                change = i;
                cur = 0;
            }
        }
    }
    for(int i = 0; i < change; i++) {
        cout << (char)(og[i] + 'a');
    }
    for(int j = 0; j < 26; j++) {
        if(j > og[change] && check[j]) {
            cout << (char)(j + 'a');
            break;
        }
    }
    for(int i = change + 1; i < k; i++) cout << char(smallest + 'a');
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/