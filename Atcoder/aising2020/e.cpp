// aising2020_e
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


// 1-index
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
    while (T--){
        int N;
        cin >> N;
        vector<pair<int, int>> inp(N);

        ll ans = 0;
        REP(i, N){
            int k, l, r;
            cin >> k >> l >> r;
            ans += r;
            inp[i] = P(k, l-r);
        }

        sort(ALL(inp), [](P& a, P& b){
            return abs(a.second) > abs(b.second);
        });

        BIT bit1(N);
        BIT bit2(N);
        vector<int> undefined;
//        print(ans);

        int max_k=1, max_k2=1;
        REP(i, N){
            int k = inp[i].first;
            ll score = inp[i].second;

            if (score >= 0){
//                print(k, bit1.sum(k), bit1.sum(max_k));
                if (bit1.sum(k) < k && bit1.sum(max_k) < max_k){
                    max_k = max(max_k, k);
                    bit1.add(k, 1);
                    ans += score;
                } else {
//                    undefined.emplace_back(i);
                }

            } else {
                int k2 = N-k;
//                print(k2, bit2.sum(k2), bit2.sum(max_k2));
                if (bit2.sum(k2) < k2 && bit2.sum(max_k2) < max_k2){
                    max_k2 = max(max_k2, k2);
                    bit2.add(k2, 1);
                    ans += 0;
                } else {
//                    undefined.emplace_back(i);
                    ans += score;
                }
            }
//            print(i, inp[i], ans);
        }
        print(ans);


    }


    return 0;
}
