/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 5.cpp
Code by : acident / lckintrovert
Created since : 05/12/2024 ~~ 14:05:59
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

bool a[110][110] = {};
void ins(string s) {
    int node1 = 0, node2 = 0, i;
    for(i = 0; s[i] != '|'; i++) {
        (node1 *= 10) += s[i] - '0';
    }
    for(++i; i < s.size(); i++) {
        (node2 *= 10) += s[i] - '0';
    }
    // cerr << s << ' ' << node1 << ' ' << node2 << endl;
    a[node1][node2] = 1;
    return;
}

int compute(string s) {
    int i = 0, num = 0;
    vi arr;
    for(; i < s.size(); i++) {
        if(s[i] == ',') {
            arr.pb(num);
            num = 0;
            continue;
        }
        (num *= 10) += s[i] - '0';
        if(i == s.size() - 1) arr.pb(num);
    }

    for(int i = 1; i < arr.size(); i++) {
        for(int j = i - 1; j < i; j++) {
            //j -- i
            if(a[arr[i]][arr[j]]) return 0;
        }
    }
    return arr[arr.size() / 2];
}

string s;
int ans = 0;

inline void solve() {
    while(cin >> s) {
        if(s.find(',') < s.size()) {
            ans += compute(s);
            break;
        }
        ins(s);
    }
    while(cin >> s) {
        ans += compute(s);
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