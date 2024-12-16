/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 12.cpp
Code by : acident / lckintrovert
Created since : 16/12/2024 ~~ 00:07:54
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
const int maxn      =        1e3 + 10;
const int INF       =        1e18;

int width = 0, height = 1;
string a[maxn] = {};
bool vis[maxn][maxn] = {};
bool check(int i, int j) {
    return (i >= 0 && i < height) && (j >= 0 && j < width);
}
vector<pi> region;
pi dir[4] = {mp(-1, 0), mp(1, 0), mp(0, 1), mp(0, -1)};
void find_path(int i, int j, char cur) {
    region.pb(mp(i, j));
    vis[i][j] = 1;
    for(int d = 0; d < 4; d++) {
        int u = i + dir[d].fi;
        int v = j + dir[d].se;

        if(check(u, v) && !vis[u][v] && a[u][v] == cur) {
            find_path(u, v, cur);
        }
    }
}

int compute() {
    int area = region.size();
    int edge = 0;
    bool internalCheck[maxn][maxn] = {};
    for(auto block : region) {
        int x = block.fi, y = block.se;
        internalCheck[x][y] = 1;
    }
    for(int col = 0; col < width; col++)
    {   
        for(int row = 0, cnt1 = 0, cnt2 = 0; row < height; row++) 
        {
            // Check left border - Right facing edge
            if(col != 0 && (internalCheck[row][col] || !internalCheck[row][col - 1])) {
                edge += (cnt1 > 0);
                cnt1 = 0;
            } else cnt1++;

            // Check right border - Left facing edge
            if(col != width - 1 && (internalCheck[row][col] || !internalCheck[row][col + 1])) {
                edge += (cnt2 > 0);
                cnt2 = 0;
            } else cnt2++;
        }
    }
    for(int row = 0; row < height; row++) 
    {
        for(int col = 0, cnt1 = 0, cnt2 = 0; col < width; col++)
        {
            if(row != 0 && (internalCheck[row][col] || !internalCheck[row - 1][col])) {
                edge += (cnt1 > 0);
                cnt1 = 0;
            } else cnt1++;

            if(row != height - 1 && (internalCheck[row][col] || !internalCheck[row + 1][col])) {
                edge += (cnt2 > 0);
                cnt2 = 0;
            } else cnt2++;
        }
    }
    // cerr << a[region[0].fi][region[0].se] << ' ' << area << ' ' << edge << endl;
    return area * edge;
}

string s;
inline void solve() {
    while(cin >> s) {
        s = ' ' + s + ' ';
        a[height++] = s;
    }
    string temp = "";
    for(int i = 0; i < s.size() + 2; i++) {
        temp = temp + ' ';
    } a[0] = a[height++] = temp;
    width = s.size();
    int ans = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(!vis[i][j]) {
                if(a[i][j] == ' ') continue;
                region.clear();
                find_path(i, j, a[i][j]);
                // cerr << a[i][j] << ' ';
                ans += compute();
            }
        }
    }

/*     for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << a[i][j];
        } cout << endl;
    } */
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