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
int WIDTH = 0, HEIGHT = 0;
inline void solve() {
    int sec = 100;
    WIDTH = 101; HEIGHT = 103;
    while(cin >> p) {
        cin >> v;
        pi pos, velo;
        pos = compute(p);
        velo = compute(v);
        pos.fi = ((pos.fi + sec * velo.fi) % WIDTH + 3 * WIDTH) % WIDTH;
        pos.se = ((pos.se + sec * velo.se) % HEIGHT + 3 * HEIGHT) % HEIGHT;
        a[pos.fi][pos.se]++;
    }

    pi quad[4] = {
                mp(0, 0), 
                mp(WIDTH / 2 + 1, 0), 
                mp(0, HEIGHT / 2 + 1), 
                mp(WIDTH / 2 + 1, HEIGHT / 2 + 1)
                };
    int num_quad[4] = {};
    for(int i = 0; i < WIDTH / 2; i++) {
        for(int j = 0; j < HEIGHT / 2; j++) {
            for(int q = 0; q < 4; q++) {
                num_quad[q] += (a[i + quad[q].fi][j + quad[q].se]);
            }
        }   
    }
    int ans = 1;
    for(int q = 0; q < 4; q++) {
        ans *= num_quad[q];
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