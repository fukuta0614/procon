// aribon4-4_c
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;



template<typename T>
struct ConvecHullTrick {
    // 直線群(配列)
    deque<pair<T, T>> lines;
    // 最小値(最大値)を求めるxが単調であるか
    bool isMonotonicX;
    // 最小/最大を判断する関数
    function<bool(T l, T r)> comp;

    // コンストラクタ ( クエリが単調であった場合はisMonotonicX = trueとする )
    ConvecHullTrick(bool isMonotonicX, function<bool(T l, T r)> compFunc)
            :isMonotonicX(isMonotonicX), comp(compFunc)  {}

    // 直線l1, l2, l3のうちl2が不必要であるかどうか
    bool check(pair<T, T> l1, pair<T, T> l2, pair<T, T> l3) {
        if (l1 < l3) swap(l1, l3);
        return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
    }

    // 直線y=ax+bを追加する (追加されるaが単調であることを仮定)
    void add(T a, T b) {
        pair<T, T> line(a, b);
        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line)) {
            lines.pop_back();
        }
        lines.emplace_back(line);
    }

    // i番目の直線f_i(x)に対するxの時の値を返す
    T f(int i, T x) {
        return lines[i].first * x + lines[i].second;
    }

    // f(x)に対するxの時の値を返す
    T f(pair<T, T> line, T x) {
        return line.first * x + line.second;
    }

    // 直線群の中でxの時に最小(最大)となる値を返す
    T get(T x) {
        // 最小値(最大値)クエリにおけるxが単調
        if (isMonotonicX) {
            static int head = 0;
            while (lines.size() - head >= 2 && comp(f(head, x), f(head + 1, x))){
                ++head;
            }
            return f(head, x);
        }
        else {
            int low = -1, high = lines.size() - 1;
            while (high - low > 1) {
                int mid = (high + low) / 2;
                (comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;
            }
            return f(high, x);
        }
    }
};

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];

    ConvecHullTrick<ll> cht(true, greater<ll>());
    REPN(j, 1, N+1){
        cht.add(-2 * j, A[j-1] + j * j);
    }

    REPN(i, 1, N+1){
        ll ans = cht.get(i) + i*i;
        print(ans);
    }


    return 0;
}
