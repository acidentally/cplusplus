/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 11.cpp
Code by : acident / lckintrovert
Created since : 15/12/2024 ~~ 22:23:08
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

struct node {
    node *pre, *next;
    int val;
    node(): pre(nullptr), next(nullptr), val(0) {}
    node(int val_): val(val_), next(nullptr), pre(nullptr) {}
    node(int val_, node *pre_, node *next_): val(val_), pre(pre_), next(next_) {}
} *StartNode, *EndNode;


int to_num(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

bool compute(node *Node) {
    int val = Node -> val;
    int val_ = val;
    string s;
    while(val_) {
        s = char(val_ % 10 + '0') + s;
        val_ /= 10;
    }

    if( val == 0 ) {
        Node -> val = 1; 
        return false;
    }
    // First case

    // Second case
    else if(s.size() % 2 == 0) {
        string s2 = "";
        int stop_idx = s.size() / 2;
        for(int i = s.size() - 1; i >= stop_idx; i--) {
            s2 = s.back() + s2;
            s.pop_back();
        }

        // Node -> ** insNode ** -> nex

        node *nex = Node -> next;
        node *insNode = new node(to_num(s2), Node, nex);

        Node -> next = insNode;
        if(nex != nullptr) nex -> pre = insNode;

        Node -> val = to_num(s);    
        return true;    
    }

    // Third case
    else Node -> val = (Node -> val) * 2024;
    return false;
}

int n;
inline void solve() {
    int repeat = 3;

    cin >> n;
    StartNode = new node(n);
    EndNode = StartNode;

    while(cin >> n) {
        node *curNode = new node(n, EndNode, nullptr);
        EndNode -> next = curNode;

        EndNode = curNode;
    }

    for(int i = 0; i < repeat; i++) {
        for(node *start = StartNode; start != nullptr; start = start -> next) 
        {
            // cerr << start -> val << ' ';
            bool check = compute(start);
            if(check) start = start -> next;
        }
        // cerr << endl;
    }

    int ans = 0;
    for(node *i = StartNode; i != nullptr; i = i -> next) ans++;
    cout << ans << endl;

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/