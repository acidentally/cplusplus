using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

signed main() {
    FAST;
    int n, m; cin >> n >> m;
    int a[n];
    int res = 0;
    int remain = 0;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
    	if(i == 0) {
    		res += min(m, a[i]);
    		//cout << min(m, a[i]) << ' ';
    		if(a[i] > m) {
    			a[i] -= m;
    		}
    		//cout << a[i] << endl;
    	}
    	else {
    		res += min(m, a[i - 1]);
    		if(m > a[i - 1]) {
    			res += min(m - a[i - 1], a[i]);
    			//cout << tfm + min(m - a[i - 1], a[i]) << ' ';
    			a[i] -= min(m - a[i - 1], a[i]);
    			//cout << a[i] << endl;
    		}
    	}		
    }
    res += min(m, a[n - 1]);
   	cout << res; 
} 