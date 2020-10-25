// arc105_c
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
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    vector<int> W(N);
    REP(i, N) cin >> W[i];
    vector<P> LV(M);
    int mn = INF;
    REP(i, M) {
        cin >> LV[i].first >> LV[i].second;
        mn = min(mn, LV[i].second);
    }

    REP(i, N){
        if (W[i] > mn){
            print(-1);
            return 0;
        }
    }

    sort(ALL(LV), [](const P& a, const P& b){
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    });

    int mx = 0;
    vector<P> v{{-1,0}};
    REP(i, M){
        if (LV[i].first > mx){
            mx = LV[i].first;
            v.emplace_back(LV[i].second, mx);
        }
    }

//    vector<int> asdf{-1, 4, 5, 8};
//    auto it = lower_bound(ALL(asdf), 5);
//    it--;
//    int x = it - asdf.begin();
//    print(x);
//    return 0;

    vector<int> perm(N);
    iota(ALL(perm), 0);
    int ans = INF;
    do {
//        vector<int> interval(N-1);
//        REPN(sz, 2, N+1){
//
//            REP(i, N-sz+1){
//                int sm = 0;
//                REP(k, sz) sm += W[perm[i+k]];
//                int interval_sm = 0;
//                REP(k, sz-1) interval_sm += interval[i+k];
//
//                auto it = lower_bound(ALL(v), P(sm, 0));
//                if (it == v.begin()){
//                    continue;
//                }
//                it--;
//                int x = it->second;
//                if (x > interval_sm){
//                    int idx = 0;
//                    REPN(k, i, i+sz-1){
//                        if (abs(k-N/2) < abs(idx-N/2)){
//                            idx = k;
//                        }
//                    }
//                    interval[idx] += x - interval_sm;
////                    interval[i+sz-1-1] += x - interval_sm;
//                }
//            }
////            print(interval);
//        }
//
//        int tmp = 0;
//        REP(i, N-1){
//            tmp += interval[i];
//        }

        vector<vector<int>> edges(N, vector<int>(N));
        REP(i, N) {
            int sm = W[perm[i]];
            REPN(j, i+1, N){
                sm += W[perm[j]];
                auto it = lower_bound(ALL(v), P(sm, 0));
                int interval = 0;
                if (it == v.begin()){
                    interval = 0;
                } else {
                    it--;
                    interval = it->second;
                }
                edges[i][j] = interval;
            }
        }

//        print(edges);
        vector<int> dist(N, 0);
        REP(i, N){
            REP(j, i){
                dist[i] = max(dist[i], dist[j] + edges[j][i]);
            }
        }
        ans = min(ans, dist[N-1]);
//    } while (0);
    } while (next_permutation(ALL(perm)));

    print(ans);


    return 0;
}
