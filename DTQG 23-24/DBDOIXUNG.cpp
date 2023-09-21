/*
Good luck for those who are trying your best
May the most glorious victory come
File name: DBDOIXUNG.cpp
Code by : acident / lckintrovert
Created since : 21/09/2023 ~~ 17:11:21
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

vi ans;
void init() {
    ans.pb(0); ans.pb(1); ans.pb(3); ans.pb(5);
    ans.pb(7); ans.pb(9); ans.pb(33); ans.pb(99);
    ans.pb(313); ans.pb(585); ans.pb(717); ans.pb(7447); ans.pb(9009);
    ans.pb(15351); ans.pb(32223); ans.pb(39993); ans.pb(53235);
    ans.pb(53835); ans.pb(73737); ans.pb(585585); ans.pb(1758571);
    ans.pb(1934391); ans.pb(1979791); ans.pb(3129213); ans.pb(5071705);
    ans.pb(5259525); ans.pb(5841485); ans.pb(13500531); ans.pb(719848917);
}
string bin(int k) {
    if(k == 0) return "0";
    string s = "";
    while(k) {
        char c = (char)((k & 1) + '0');
        s = c + s;
        k >>= 1;
    }
    return s;
}
inline void solve() {
    int n; cin >> n;
    init();
    for(auto s : ans) {
        if(s > n) break;
        cout << s << ' ' << bin(s) << endl;
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