/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 3.cpp
Code by : acident / lckintrovert
Created since : 03/12/2024 ~~ 21:39:02
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

int ans = 0;
int execute(string s, int& i, bool poss) {
    if(!poss) {
        cerr << "STOPPING --> EXIT" << endl;
        return 0;
    }
    int a = 0, b = 0;

    while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
        a = a * 10 + s[i] - '0';
        i++;
    }
    
    if(s[i] != ',') {
        cerr << "NOT A , --> EXIT" << endl;
        return 0;
    }
    i++;

    while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
        b = b * 10 + s[i] - '0';
        i++;
    }
    
    if(i < s.size() && s[i] != ')') {
        cerr << "NOT A, ) --> EXIT" << endl;
        return 0;
    }
    cerr << a << ' ' << b << " YIELD " << a * b << ". Answer is now " << ans + a * b << endl;
    return a * b;
}

string s;
inline void solve() {
    bool flag = 1; //100411201
    while(getline(cin, s)) {
        // bool flag = 1; //134351324 -- too high
        //101629183
        for(int i = 0; i < s.size(); i++) {
            if(i + 4 <= s.size() && s.substr(i, 4) == "do()") {
                cerr << i << " DO" << endl;
                flag = 1;
                continue;
            }
            if(i + 7 <= s.size() && s.substr(i, 7) == "don't()") {
                cerr << i << " STOP" << endl;
                flag = 0;
                continue;
            }
            if(i + 4 <= s.size() && s.substr(i, 4) == "mul(") {    
                cerr << i - 4 << " ATTEMPT MUL: ";
                i += 4;
                ans += execute(s, i, flag);
            }
            
        }
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    solve();
}

/*A place to scribble thoughts

*/