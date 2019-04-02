// aribon2-2_k
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define ALL(x) x.begin(), x.end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define CHAR2INT(c) (c - '0')
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

int mod_pow(ll a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[8]={ 1, 0, -1, 0, -1, 1, -1, 1};
int dy[8]={ 0, 1, 0, -1, -1, -1, 1, 1};

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int T, N;
    cin >> T >> N;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    int M;
    cin >> M;
    vector<int> B(M);
    REP(i, M) cin >> B[i];

    int idx = 0;
    REP(i, M){
        while (idx < N){
            if (B[i] < A[idx]) {
                COUT("no");
                return 0;
            }
            if (B[i] - A[idx] <= T) break;
            idx++;
        }
        if (idx == N){
            COUT("no");
            return 0;
        }
        idx++;
    }
    COUT("yes");

    return 0;
}
