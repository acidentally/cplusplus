/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 6.cpp
Code by : acident / lckintrovert
Created since : 06/12/2024 ~~ 14:35:47
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
const int maxn      =        5e2 + 10;
const int INF       =        1e18;

bool vis[maxn][maxn] = {};
string a[maxn] = {};
string s;

bool check(int x, int y, int cnt) {
    return (x >= 0 && x < cnt) && (y >= 0 && y < a[0].size());
}

pi dir_arr[4] = {mp(-1, 0), mp(0, 1), mp(1, 0), mp(0, -1)};
pi next(int x, int y, int &dir, int cnt) {
    for(int i = 0; i < 4; i++) {
        int exp_dir = (dir + i) % 4;
        int exp_x = x + dir_arr[exp_dir].fi;
        int exp_y = y + dir_arr[exp_dir].se;

        if(check(exp_x, exp_y, cnt) && a[exp_x][exp_y] == '#') continue;
        else {
            dir = exp_dir;
            return mp(exp_x, exp_y);
        }
    }
}

inline void solve() {
    int cnt = 0;
    int pos_x = 0, pos_y = 0;
    while(cin >> s) {
        a[cnt++] = s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '^') pos_x = cnt - 1, pos_y = i;
        }
    }
    vis[pos_x][pos_y] = 0;
    int ans = 0, dir = 0;
    while(check(pos_x, pos_y, cnt)) {
        ans += !vis[pos_x][pos_y];
        if(!vis[pos_x][pos_y]) a[pos_x][pos_y] = 'G';
        vis[pos_x][pos_y] = 1;

        pi next_pos = next(pos_x, pos_y, dir, cnt);
        pos_x = next_pos.fi;
        pos_y = next_pos.se;
    }

    // for(int i = 0; i < cnt; i++) {
    //     for(int j = 0; j < a[i].size(); j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
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