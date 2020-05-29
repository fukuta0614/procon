// Round641_d
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

random_device rd;
mt19937 mt(rd());


struct BIT {
    int sz;
    vector<int> tree;

    BIT(int n) {
        sz = n;
        tree.resize(n+1);
    }

    ll sum(int i){
        ll sm = 0;
        while (i > 0){
            sm += tree[i];
            i -= i & -i;
        }
        return sm;
    }

    void add(int i, int x){
        while (i <= sz){
            tree[i] += x;
            i += i & -i;
        }
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int T;
    cin >> T;

    REP(_, T){
        ll N, K;
        cin >> N >> K;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        // 一個しかないときは何もできない
        if (N == 1){
            if (A[0] == K){
                print("yes");
            } else {
                print("no");
            }
            continue;
        }

        // Kがなかったら無理
        if (find(ALL(A), K) == A.end()){
            print("no");
            continue;
        }

        // Kがあるなら、
        // K以上のmedianが作れれば、Kの横までそれで埋めて、そこから全部Kにできる

        vector<int> B(N);
        REP(i, N) {
            B[i] = (A[i] >= K) ? 1 : -1;
        }

        vector<int> cumsum(N+1);
        REP(i, N){
            cumsum[i+1] = cumsum[i] + B[i];
        }

//        print(A);
//        print(B);
//        print(cumsum);

        int mn = *min_element(ALL(cumsum));
        REP(i, N+1){
            cumsum[i] += abs(mn) + 1; // bitが1-indexなので最小値が1になるように
        }

//        print(cumsum);

        int mx = *max_element(ALL(cumsum));
        BIT bit(mx);

        // cumsum[i]より大きいものが、i-2以下の場所に、1つ以上あればOK
        bool exists = false;
        REPN(i, 1, N+1){
            if (bit.sum(cumsum[i]-1) > 0){
                exists = true;
                break;
            }
            bit.add(cumsum[i-1], 1);
        }

        if (exists){
            print("yes");
        } else {
            print("no");
        }
    }


    return 0;
}
