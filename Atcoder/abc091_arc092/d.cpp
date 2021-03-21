// abc091_d
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
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

string to_bin(int n){ std::stringstream ss; ss << std::bitset<4>(n); return ss.str(); }


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];

    int ans = 0;
    REP(d, 30){
        vector<int> a(N), b(N);
        REP(i, N){
            a[i] = A[i] & ((1<<(d+1))-1);
            b[i] = B[i] & ((1<<(d+1))-1);
        }

        int c = 0;
        sort(ALL(b));
        REP(i, N){
            int x = (a[i] & ((1 << d)-1));
            int n = lower_bound(ALL(b), (1 << d) - x) - b.begin();
            int m = lower_bound(ALL(b), (1 << (d+1)) - x) - b.begin();

            int tmp = ((a[i] >> d) & 1) ? N - (m - n) : m - n;
            c += tmp;

//            print(d, i, 'a', to_bin(a[i]));
//            int tmp2 = 0;
//            REP(j, N) {
//                if (((a[i] + b[j]) >> d) & 1) tmp2 ++;
//                print(d, i, j, "b", b[j], to_bin(b[j]), "a+b", to_bin(a[i] + b[j]));
//            }
//            print(d, i, "num", (1 << d) - x, (1 << (d+1)) - x, n, m, tmp, tmp2);

        }
        if (c & 1){
            ans += 1 << d;
        }
    }

    print(ans);

    return 0;
}
