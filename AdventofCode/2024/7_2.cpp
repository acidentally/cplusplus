/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 7.cpp
Code by : acident / lckintrovert
Created since : 07/12/2024 ~~ 14:17:41
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

int sqr(int a) {
    return a * a;
}
int modPow(int a, int k) {
    if(k == 0) return 1;
    if(k == 1) return a;
    if(k & 1) return a * sqr(modPow(a, k >> 1));
    else return sqr(modPow(a, k >> 1));
}

string toStringFromBase(int a, int base, int length) {
    if(a == 0) {
        string s = "";
        while(length--) s += '0';
        return s;
    }

    string ans = "";
    while(a) {
        char c = (a % base) + '0';
        ans = c + ans;
        a /= base;
    }
    if(length == -1) return ans;
    else {
        while(ans.size() < length) ans = '0' + ans;
        return ans;
    }
}

int append(int a, int b) {
    string b_string = toStringFromBase(b, 10, -1);
    int more_zeros = b_string.size();
    a = a * modPow(10, more_zeros);
    return a + b;
}

int toNum(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}
int compute(vector<int> a, int target) {
    if(target == -1) return 0;

    int times = modPow(3, a.size() - 1);
    for(int mask = 0; mask < times; mask++) {
        int cur = a[0];
        string mask_string = toStringFromBase(mask, 3, a.size() - 1);
        for(int pos = 0; pos < a.size() - 1; pos++) {
            if(mask_string[pos] == '0') {
                cur *= a[pos + 1];
                // cerr << " * " << a[pos + 1];
            } 
            else if(mask_string[pos] == '1') {
                cur += a[pos + 1];
                // cerr << " + " << a[pos + 1];
            } 
            else if(mask_string[pos] == '2') {
                cur = append(cur, a[pos + 1]);
                // cerr << " || " << a[pos + 1];
            }
        }
        if(cur == target) {
            // cerr << cur << endl;
            return cur;
        }
    }
    return 0;
}

string s;
inline void solve() {
    int ans = 0, target = -1;
    vector<int> a;
    while(cin >> s) {
        if(s == "end") break;
        if(s[s.size() - 1] == ':') {
            ans += compute(a, target);
            a.clear();
            s.pop_back();
            target = toNum(s);
        } else {
            a.pb(toNum(s));
        }
    }
    ans += compute(a, target);
    cout << ans << endl;

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("7.INP", "r", stdin);
    freopen("7.OUT", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/