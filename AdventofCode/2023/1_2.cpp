/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 2.cpp
Code by : acident / lckintrovert
Created since : 15/11/2024 ~~ 13:00:05
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

string num[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int check(int index, string s) {
    int ans = 0;
    for (int i = 0; i < 9; i++) { //current number check
        bool check = 1;
        for (int letter = 0; letter < num[i].size() && check; letter++) {
            if(index + letter < s.size()) {
                //index + letter is in string s
                //letter at i is in array num
                check &= s[index + letter] == num[i][letter];
            }
            else {
                check = 0;
                break;
            }
        }
        if(check) {
            ans = i + 1;
            break;
        }
    }
    return ans;
}
int ans = 0;
string s;
inline void solve() {
    while(cin >> s) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            int holder_num = check(i, s);
            if(s[i] >= '0' && s[i] <= '9') {
                num = 10 * (s[i] - '0');
                break;
            }
            else if (holder_num != 0) {
                num = 10 * holder_num;
                break;
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            int holder_num = check(i, s);
            if(s[i] >= '0' && s[i] <= '9') {
                num += s[i] - '0';
                break;
            }
            else if (holder_num != 0) {
                num += holder_num;
                break;
            }
        }
        cerr << s << ' ' << num << endl;
        ans += num;
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