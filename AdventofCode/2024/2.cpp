/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 2.cpp
Code by : acident / lckintrovert
Created since : 02/12/2024 ~~ 09:21:37
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

int mabs(int num) {
    return max(num, -num);
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

    bool inc = ((a[1] - a[0]) > 0);
    for(int i = 1; i < a.size(); i++) {
        int dif = a[i] - a[i - 1];
        if((dif > 0) != inc || mabs(dif) < 1 || mabs(dif) > 3) return false;
    }
    return true;
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