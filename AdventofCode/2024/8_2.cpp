/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 8.cpp
Code by : acident / lckintrovert
Created since : 08/12/2024 ~~ 17:39:48
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
int X, Y;
bool isLowerCase(char c) {
    return (c >= 'a') && (c <= 'z');
}
bool isUpperCase(char c) {
    return (c >= 'A') && (c <= 'Z');
}
bool isNumber(char c) {
    return (c >= '0') && (c <= '9');
}

bool check(int x, int y) {
    return (x >= 0 && x < X) && (y >= 0 && y < Y);
}

vector<string> a;
string s;
vector<pi> antenna[100] = {};
int ans = 0;

inline void solve() {
    while(cin >> s) {
        a.pb(s);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '.') continue;
            if(isLowerCase(s[i])) {
                antenna[s[i] - 'a' + 0].pb(mp(a.size() - 1, i)); // 0 - 25
            } else if(isUpperCase(s[i])) {
                antenna[s[i] - 'A' + 26].pb(mp(a.size() - 1, i)); // 26 - 51
            } else if(isNumber(s[i])){
                antenna[s[i] - '0' + 52].pb(mp(a.size() - 1, i)); // 52 - 61
            }
        }
    }
    // cerr << a.size() << ' ' << a[0].size() << ' ' << 'Z' - 'A';
    X = a.size(), Y = a[0].size();
    bool antinode[X][Y] = {};
    for(int i = 0; i < 26 + 26 + 10; i++) {
        for(int j = 0; j < antenna[i].size(); j++) {
            for(int k = j + 1; k < antenna[i].size(); k++) {
                pi point1 = antenna[i][j];
                pi point2 = antenna[i][k];
                int dx = point2.fi - point1.fi;
                int dy = point2.se - point1.se;

                pi cur_points = point1;
                while(check(cur_points.fi, cur_points.se)) {
                    antinode[cur_points.fi][cur_points.se] = 1;
                    cur_points.fi += dx;
                    cur_points.se += dy;
                }

                dx = -dx;
                dy = -dy;
                cur_points = point2;
                while(check(cur_points.fi, cur_points.se)) {
                    antinode[cur_points.fi][cur_points.se] = 1;
                    cur_points.fi += dx;
                    cur_points.se += dy;
                }

            }
        }
    }

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            if(antinode[i][j]) ans++;
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