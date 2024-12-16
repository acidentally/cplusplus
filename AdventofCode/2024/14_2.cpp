/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 14.cpp
Code by : acident / lckintrovert
Created since : 16/12/2024 ~~ 15:26:44
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

pi compute(string user_inp) {
    pi ans = mp(0, 0);
    int i, neg;
    for(i = 2, neg = 0; user_inp[i] != ','; i++) {
        if(user_inp[i] == '-') {
            neg = 1;
            continue;
        }
        ans.fi = ans.fi * 10 + (neg ? -1 : 1) * (user_inp[i] - '0');
    } i++;
    for(bool neg = 0; i < user_inp.size(); i++) {
        if(user_inp[i] == '-') {
            neg = 1;
            continue;
        }
        ans.se = ans.se * 10 + (neg ? -1 : 1) * (user_inp[i] - '0');
    }
    return ans;

}

string p, v;
int a[200][200] = {};
bool vis[200][200] = {};
int WIDTH = 0, HEIGHT = 0;
pi dir[4] = {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)};
bool check(int i, int j) {
    return (i >= 0 && i < WIDTH) && (j >= 0 && j < HEIGHT);
}
int val = 0;
void find(int i, int j) {
    vis[i][j] = 1;
    val++;
    for(int d = 0; d < 4; d++) {
        int u = i + dir[d].fi;
        int v = j + dir[d].se;
        if(check(u, v) && !vis[u][v] && a[u][v]) {
            find(u, v);
        }
    }
}

vector<pair<pi, pi>> holder;
inline void solve() {
    // int sec = 1000;
    WIDTH = 101; HEIGHT = 103;
    while(cin >> p) {
        if(p == "EXIT") break;
        cin >> v;

        pi pos, velo;
        pos = compute(p);
        velo = compute(v);
        holder.pb(mp(pos, velo));
    }
    for(int sec = 0; sec < 50000; sec++) {
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        cout << "AT " << sec << " SECOND:" << endl;
        for(auto pos_velo : holder) {
            pi pos = pos_velo.fi;
            pi velo = pos_velo.se;

            pos.fi = ((pos.fi + sec * velo.fi) % WIDTH + 3 * WIDTH) % WIDTH;
            pos.se = ((pos.se + sec * velo.se) % HEIGHT + 3 * HEIGHT) % HEIGHT;
            a[pos.fi][pos.se] = 1;
        }
        int valTOTAL = 0;
        for(int i = 0; i < HEIGHT; i++) {
            for(int j = 0; j < WIDTH; j++) {
                if(a[i][j] && !vis[i][j]) {
                    val = 0;
                    find(i, j);
                    maximize(valTOTAL, val);
                }
            }
        } 
        if(valTOTAL > holder.size() / 4) {
            for(int i = 0; i < HEIGHT; i++) {
                for(int j = 0; j < WIDTH; j++) {
                    if(a[j][i]) cout << '#';
                    else cout << '.';
                } cout << endl;
            } cout << endl << endl;
        }
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    freopen("CHRISTMAS.OUT", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/