/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 4_2.cpp
Code by : acident / lckintrovert
Created since : 04/12/2024 ~~ 10:17:31
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        1e5 + 10;
const int INF       =        1e18;
const int trick = 1e6;

bool check(vector<string> a, int row, int col) {
    if(!(row - 1 >= 0 && row - 1 < a.size())) return 0;
    if(!(row + 1 >= 0 && row + 1 < a.size())) return 0;
    if(!(col - 1 >= 0 && col - 1 < a[row].size())) return 0;
    if(!(col + 1 >= 0 && col + 1 < a[row].size())) return 0;
    return 1;
}

int compute(int a, int b) {
    return (a + trick) * (b + trick);
}

int prompt(vector<string> a, int row, int col) {
    const int genius = ('M' + trick) * ('S' + trick);
    if(!check(a, row, col)) return 0;
    int diag1 = compute(a[row - 1][col - 1], a[row + 1][col + 1]);
    int diag2 = compute(a[row + 1][col - 1], a[row - 1][col + 1]);
    return diag1 == genius && diag2 == genius;
}

vector<string> a;
string s;
int ans = 0;

inline void solve() {
    while(cin >> s) {
        a.pb(s);
    }    
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == 'A') ans += prompt(a, i, j);
        }
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