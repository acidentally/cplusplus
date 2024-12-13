/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 2_2_bitch.cpp
Code by : acident / lckintrovert
Created since : 02/12/2024 ~~ 11:14:57
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

bool get1(vector<int> a) {
    bool inc = ((a[1] - a[0]) > 0);
    for(int i = 1; i < a.size(); i++) {
        int dif = a[i] - a[i - 1];
        if((dif > 0) != inc || abs(dif) < 1 || abs(dif) > 3) return false;
    }
    return true;
}

bool get(string s) {
    vector<int> a;
    for(int i = 0, cur = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            a.pb(cur);
            cur = 0;
        } else cur = cur * 10 + s[i] - '0';

        if(i == s.size() - 1 && s[i] != ' ') a.pb(cur);
    }

    bool ans = 0;
    for(int i = 0; i < a.size(); i++) {
        vector<int> test;
        for(int j = 0; j < a.size(); j++) {
            if(i == j) continue;
            test.pb(a[j]);
        }
        ans |= get1(test);
        if(ans == 1) return ans;
    }
    return ans;
}

string s;
inline void solve() {
    int ans = 0;
    while(getline(cin, s)) {
        cerr << get(s) << endl;
        ans += get(s);
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