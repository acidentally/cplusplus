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

void ins(vector< set<int> >& a, string s) {
    int node1 = 0, node2 = 0, i;
    for(i = 0; s[i] != '|'; i++) {
        (node1 *= 10) += s[i] - '0';
    }
    for(++i; i < s.size(); i++) {
        (node2 *= 10) += s[i] - '0';
    }
    // cerr << s << ' ' << node1 << ' ' << node2 << endl;
    a[node1].insert(node2);
    return;
}

int compute_part_two(vi arr, vector< set<int> > a) {

    int in[110] = {};
    vector<int> g[110] = {};
    vector<int> topo;
    queue<int> waitList;

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(a[arr[i]].find(arr[j]) != a[arr[i]].end()) {
                g[arr[i]].pb(arr[j]);
                in[arr[j]]++;
            } else if(a[arr[j]].find(arr[i]) != a[arr[j]].end()) {
                g[arr[j]].pb(arr[i]);
                in[arr[i]]++;
            }
        }
    }

    for(auto s : arr) {
        if(in[s] == 0) {
            waitList.push(s);
        }
    }
    while(!waitList.empty()) {
        int u = waitList.front();
        waitList.pop();
        topo.pb(u);
        for(auto child : g[u]) {
            if(--in[child] == 0) waitList.push(child);
        }
    }
    // cerr << topo[topo.size() / 2] << endl;
    return topo[topo.size() / 2];
}

string s;
vector< set<int> > a(110, set<int> {});
int ans = 0;

inline void solve() {
    while(cin >> s) {
        if(s.find(',') < s.size()) {
            ans += compute(s, a);
            break;
        }
        ins(a, s);
    }
    while(cin >> s) {
        ans += compute(s, a);
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