/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 9.cpp
Code by : acident / lckintrovert
Created since : 09/12/2024 ~~ 13:06:53
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

string input_string;
vector<pi> a;
vi  empty_spot;
inline void solve() {
    cin >> input_string;
    bool flip = false;
    for(int i = 0, cur = 0; i < input_string.size(); i++) {
        int cur_num = input_string[i] - '0';
        if(!flip) {
            a.pb(mp(cur_num, cur++));
        }
        else if(flip) {
            empty_spot.pb(a.size());
            a.pb(mp(cur_num, -1));
        }
        flip = !flip;
    }

    for(int i = a.size() - 1; i >= 0; i--) {
        for(int emp = 0; emp < empty_spot.size(); emp++) {
            if(empty_spot[emp] > i) {
                
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