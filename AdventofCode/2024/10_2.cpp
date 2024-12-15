/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 10.cpp
Code by : acident / lckintrovert
Created since : 15/12/2024 ~~ 21:50:36
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
const int maxn      =        1e2 + 10;
const int INF       =        1e18;


int width = 0, height = 0;
pi dir[4] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};
vector<bool> vis[maxn] = {};
vector<int> a[maxn] = {};
vector<pi> curPair = {};

bool check(int i, int j) {
    return (i >= 0 && i < width) && (j >= 0 && j < height);
}

int findE(int i, int j, int val) {
    if(val == 9) {
        return 1;
    }
    int ans = 0;
    for(int d = 0; d < 4; d++) {
        int nex_i = i + dir[d].fi;
        int nex_j = j + dir[d].se;

        if(check(nex_i, nex_j) && a[nex_i][nex_j] == val + 1) {
            ans += findE(nex_i, nex_j, val + 1);
        }
    }
    return ans;
}

string s;
int ans = 0;

inline void solve() {
    int cur = 0;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            a[cur].pb(s[i] - '0');
            vis[cur].pb(0);
        }
        cur++;
    }
    
    width = a[0].size();
    height = cur;

    for(int i = 0; i < cur; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == 0) {
                // for(auto coords : curPair) {
                //     vis[coords.fi][coords.se] = 0;
                // }
                // curPair.clear();
                ans += findE(i, j, 0);
            }
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