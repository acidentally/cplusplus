/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 4.cpp
Code by : acident / lckintrovert
Created since : 04/12/2024 ~~ 10:01:00
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



int search(vector<string> a, int row, int col) {
    int total = 0;
    for(int dir_x = -1; dir_x <= 1; dir_x++) {
        for(int dir_y = -1; dir_y <= 1; dir_y++) {
            if(dir_x == 0 && dir_y == 0) continue;
            string cur_string = "X";
            int cur_row = row, cur_col = col;
            for(int cnt = 0; cnt < 3; cnt++) {
                cur_row += dir_x;
                cur_col += dir_y;
                if(cur_row > a.size() || cur_col > a[cur_row].size()) break;
                cur_string = cur_string + a[cur_row][cur_col];
            }
            if(cur_string == "XMAS") total++;
        }
    }
    return total;
}

vector<string> a;
string s;
int ans = 0;

inline void solve() {
    while(cin >> s) {
        a.pb(s);
    }
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == 'X') {
                ans += search(a, i, j);
                
            }
        }
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