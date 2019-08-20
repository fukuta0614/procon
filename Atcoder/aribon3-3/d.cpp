// aribon3-3_d
// C - データ構造
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
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


struct Bucket {

    int bsize, bcnt;
    vector<vector<int>> dat;
    vector<int> sums;

    Bucket(int bsize_): bsize(bsize_), bcnt(bsize_) {
        dat.assign(bcnt, vector<int>(bsize, 0));
        sums.assign(bcnt, 0);
    }

    void add(int x){

        int bidx = x / bsize;
        int idx = x % bsize;

        dat[bidx][idx]++;
        sums[bidx]++;
    }

    // x番目に小さい数を探す
    int count(int x){
        int sm = 0;
        int idx = 0;
        REP(i, bcnt){
            if (sm + sums[i] >= x){
                idx = i;
                break;
            }
            sm += sums[i];
        }

        REP(j, bsize) {
            if (sm + dat[idx][j] == x) {
                dat[idx][j]--;
                sums[idx]--;
                return bsize * idx + j;
            }
            sm += dat[idx][j];
        }

        assert(false);
        return -1;
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int Q;
    cin >> Q;

    const int bsize = 500;
    auto bucket = Bucket(bsize);

    REP(i, Q){
        int t, x;
        cin >> t >> x;

        if (t == 1){
            bucket.add(x);
        } else {
            int num = bucket.count(x);
            print(num);
        }
    }

    return 0;
}
