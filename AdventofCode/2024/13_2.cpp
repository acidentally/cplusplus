/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 13.cpp
Code by : acident / lckintrovert
Created since : 16/12/2024 ~~ 14:25:49
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

struct compare {
    bool operator() (const pi a, const pi b) {
        return 3 * a.fi + a.se > 3 * b.fi +  b.se;
    }
};

int compute(string A, string B, string X) {
    pi a, b, p;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == 'X') {
            i += 2;
            a.fi = 0;
            while(A[i] != ',') {
                a.fi = a.fi * 10 + A[i] - '0';
                i++;
            }
        }
        if(A[i] == 'Y') {
            i += 2;
            a.se = 0;
            while(i < A.size() && A[i] != ',') {
                a.se = a.se * 10 + A[i] - '0';
                i++;
            }         
        }
    }
    for(int i = 0; i < A.size(); i++) {
        if(B[i] == 'X') {
            i += 2;
            b.fi = 0;
            while(B[i] != ',') {
                b.fi = b.fi * 10 + B[i] - '0';
                i++;
            }
        }
        if(B[i] == 'Y') {
            i += 2;
            b.se = 0;
            while(i < B.size() && B[i] != ',') {
                b.se = b.se * 10 + B[i] - '0';
                i++;
            }         
        }
    }
    for(int i = 0; i < A.size(); i++) {
        if(X[i] == 'X') {
            i += 2;
            p.fi = 0;
            while(X[i] != ',') {
                p.fi = p.fi * 10 + X[i] - '0';
                i++;
            }
        }
        if(X[i] == 'Y') {
            i += 2;
            p.se = 0;
            while(i < X.size() && X[i] != ',') {
                p.se = p.se * 10 + X[i] - '0';
                i++;
            }         
        }
    }

    p.fi += 10000000000000;
    p.se += 10000000000000;

    // Find pair (i, j) s.t : 
    // a.fi * i + b.fi * j = p.fi
    // a.se * i + b.se * j = p.se
    // aka 
    // |a.fi  b.fi|  |i|      |p.fi|
    // |a.se  b.se|  |j|  --> |p.se|
    // or M . |i, j| --> N 
    // or |i, j| = M^(-1) * N =  adj(M) * M / det(M) * N

    // adj(M) = b.se -b.fi  |p.fi|
    //          -a.se a.fi  |p.se|
    // detM = a.fi * b.se - a.se * b.fi;
    // N * adjM = 


    cerr << "Savepoint 1" << endl;
    int detM = a.fi * b.se - a.se * b.fi;
    if(detM == 0) return 0;

    cerr << "Savepoint 2" << endl;
    int i = b.se * p.fi - b.fi * p.se;
    int j = a.fi * p.se - a.se * p.fi;
    if(i % detM != 0 || j % detM != 0) return 0;
    
    cerr << "Savepoint 3" << endl;
    return 3 * (i / detM) + (j / detM);
}

int ans = 0;
string A, B, X;
inline void solve() {
    while(getline(cin, A)) {
        getline(cin, B);
        getline(cin, X);
        ans += compute(A, B, X);
        getline(cin, A);
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