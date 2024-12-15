/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 11.cpp
Code by : acident / lckintrovert
Created since : 15/12/2024 ~~ 23:43:25
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

map<int, pi> m;
map<int, bool> check;
map<int, int> pre, cur;
int n;

int to_num(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        ans = ans * 10 + s[i] - '0';
    } return ans;
}

pi compute(int k) {
    if(k == 0) return mp(1, -1);

    string s;
    int val = k;
    while(val) {
        s = char(val % 10 + '0') + s;
        val /= 10;
    }
    if(s.size() % 2 == 0) {
        string s2 = "";
        int stopIdx = s.size() / 2;
        for(int i = s.size() - 1; i >= stopIdx; i--) {
            s2 = s.back() + s2;
            s.pop_back();
        }
        return mp(to_num(s), to_num(s2));
    }

    return mp(k * 2024, -1);
}

inline void solve() {
    int repeat = 75;
    while(cin >> n) {
        pre[n] += 1;
    }

    for(int i = 0; i < repeat; i++) {
        for(map<int, int>::iterator it = pre.begin(); it != pre.end(); it++) {
            if(!check[it -> fi]) {
                check[it -> fi] = true;
                m[it -> fi] = compute(it -> fi);
            }
            int a = m[it -> fi].fi;
            int b = m[it -> fi].se;
            cur[a] += it -> se;
            if(b != -1) cur[b] += it -> se;
        } 
        pre = cur;
        cur.clear();
    }

    int ans = 0;
    for(map<int, int>::iterator it = pre.begin(); it != pre.end(); it++) {
        ans += it -> se;
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