/*
Good luck for those who are trying your best
May the most glorious victory come
File name: racruoi.cpp
Code by : acident / lckintrovert
Created since : 28/11/2024 ~~ 14:18:00
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


struct matrix {
    int row, col, **arr;

    matrix() : row(0), col(0) {}
    matrix(int n, int m) : row(n), col(m) {
        arr = new int *[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int [col];
        }
    }

    matrix operator* (matrix b) const{
        if(col != b.row)
            return matrix(0, 0);
        matrix ans(row, b.col);
        for (int i = 0; i < ans.row; i++) {
            for (int j = 0; j < ans.col; j++) {
                int cur = 0;
                for (int k = 0; k < col; k++) {
                    cur += arr[i][k] * b.arr[k][j];
                }
                ans.arr[i][j] = cur;
            }
        }
        return ans;
    }

    friend ostream& operator<< (ostream& outs, matrix mat) {
        for (int i = 0; i < mat.row; i++) {
            for (int j = 0; j < mat.col; j++) {
                outs << mat.arr[i][j] << ' ';
            }
            outs << endl;
        }
        return outs;
    }
};


void solve() {
    // Mat_A input
    
    matrix mat_A(3, 3), mat_B(3, 1);
    for (int i = 0; i < mat_A.row; i++) {
        for (int j = 0; j < mat_A.col; j++) {
            cin >> mat_A.arr[i][j];
        }
    }

    for (int i = 0; i < mat_B.row; i++) {
        for (int j = 0; j < mat_B.col; j++) {
            cin >> mat_B.arr[i][j];
        }
    }
    cout << mat_A * mat_B;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    //File?
    solve();
}

/*A place to scribble thoughts

*/