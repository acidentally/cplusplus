/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 2.cpp
Code by : acident / lckintrovert
Created since : 15/11/2024 ~~ 13:17:03
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


struct game {
    map<char, int> color;
    game() {
        color['r'] = 0;
        color['g'] = 0;
        color['b'] = 0;
    }
};

bool process(string s) {
    game new_game;
    for (int i = 0, cur_num = 0; i < s.size(); i++) {
        // cerr << i << ' ' << s[i] << endl;
        if(s[i] >= '0' && s[i] <= '9') {
            cur_num = cur_num * 10 + s[i] - '0';
        } 
        else if(s[i] == ' ')
            continue;
        else {
            new_game.color[s[i]] = cur_num;
            while(i < s.size() && s[i] != ',') {
                i++;
            }
            cur_num = 0;
        }
    }
    bool poss = bool(new_game.color['r'] <= 12 & new_game.color['g'] <= 13 & new_game.color['b'] <= 14);
    cerr << "CURRENT GAME: " << s << endl;
    cerr << "BLUE: " << new_game.color['b'] << " <= 14" << endl
            << "GREEN: " << new_game.color['g'] << " <= 13" << endl
            << "RED: " << new_game.color['r'] << " <= 12" << endl;
    cerr << "POSS: " << poss << endl
         << endl;
    return poss;
}

vector<game> all_games;
string s;
inline void solve() {
    int cur_id = 1, ans = 0;
    while(getline(cin, s)) {
        int start_index = 0;
        for (start_index = 0; s[start_index] != ':'; ++start_index){}
        start_index++;

        string cur_string = "";
        bool poss = 1;
        cerr << "GAME ID: " << cur_id << endl;
        while (start_index < s.size()) {
            if (s[start_index] == ';') {
                poss &= process(cur_string);
                cur_string = "";
                start_index++;
                continue;
            }
            cur_string = cur_string + s[start_index];
            // cerr << cur_string << endl;
            start_index++;
        }
        poss &= process(cur_string);
        if(poss) ans += cur_id;
        cur_id++;
        // cerr << "ANS: " << ans << endl;
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