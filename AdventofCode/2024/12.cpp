/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 12.cpp
Code by : acident / lckintrovert
Created since : 16/12/2024 ~~ 00:07:54
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
const int maxn      =        1e3 + 10;
const int INF       =        1e18;

int width = 0, height = 0;
bool check(int i, int j) {
    return (i >= 0 && i < height) && (j >= 0 && j < width);
}
int compute(int i, int j) {
    
}

string s;
string a[maxn] = {};
bool vis[maxn][maxn] = {};
inline void solve() {
    while(cin >> s) {
        a[height++] = s;
    }
    width = s.size();
    int ans = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(!vis[i][j]) {
                vis[i][j] = true;
                ans += compute(i, j);
            }
        }
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