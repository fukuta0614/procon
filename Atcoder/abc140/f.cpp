// abc138_f
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    int n = 1 << N;
    vector<int> S(n);
    REP(i, n) cin >> S[i];

    multiset<int> T(ALL(S));

    multiset<int> gen;

    auto last = prev(T.end());
    gen.insert(*last);
    T.erase(last);

    REP(i, N){
        auto tmp = gen;
        for (auto gen_it = tmp.rbegin(); gen_it != tmp.rend(); gen_it++){
            int s = *gen_it;
            auto it = T.lower_bound(s);
            if (it == T.begin()) {
                print("No");
                return 0;
            }
            it--;
            gen.insert(*it);
            T.erase(it);
        }
    }

    print("Yes");

    return 0;
}
