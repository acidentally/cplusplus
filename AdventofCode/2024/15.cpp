/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 15.cpp
Code by : acident / lckintrovert
Created since : 16/12/2024 ~~ 17:00:03
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

int WIDTH, HEIGHT = 0;
int pos_x, pos_y;

string a[maxn] = {};
void process(pi dir) {
    int cur_x = pos_x;
    int cur_y = pos_y;
    pi stop_point;
    for(int i = 1;; i++) {
        int u = cur_x + i * dir.fi;
        int v = cur_y + i * dir.se;
        if(a[u][v] == '#') return;
        if(a[u][v] == '.') {
            stop_point = mp(u, v);
            break;
        }
    }

    dir.fi = -dir.fi;
    dir.se = -dir.se;

    for(;;) {
        int u = stop_point.fi;
        int v = stop_point.se;
        a[u][v] = a[u + dir.fi][v + dir.se];
        a[u + dir.fi][v + dir.se] = '.';
        if(a[u][v] == '@') {
            pos_x = u;
            pos_y = v;
            return;
        }

        stop_point.fi = u + dir.fi;
        stop_point.se = v + dir.se;
    }
}

string s;
inline void solve() {

    map<char, pi> m;
    m['>'] = mp(0, 1);
    m['<'] = mp(0, -1);
    m['^'] = mp(-1, 0);
    m['v'] = mp(1, 0);
    // a[row][col]
    while(getline(cin, s)) {
        a[HEIGHT++] = s;
        if(s[0] != '#') break;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '@') {
                pos_x = HEIGHT - 1;
                pos_y = i;                
            }
        }
    } WIDTH = a[0].size();

    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            process(m[s[i]]);
        }
    }

    int ans = 0;
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            if(a[row][col] == 'O') {
                ans += 100 * row + col;
            }
        }
    }
    cout << WIDTH << " " << HEIGHT << endl;
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