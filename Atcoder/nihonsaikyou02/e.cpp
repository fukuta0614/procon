// nihonsaikyou02_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int K;
    cin >> K;
    string S;
    cin >> S;

    int N = S.size();
    int a = N / pow(2, K);

    bool b1 = a >= 2;
    bool b2 = pow(2, K-1) <= N && N < pow(2, K);

    if (not (b1 || b2)){
        print("impossible");
        return 0;
    }

    int r = b1 ?
            N % int(pow(2, K)) :
            N % int(pow(2, K-1));

//    print(r);
    vector<string> T{S};
    vector<vector<string>> cand_list;
    REP(i, int(b1 ? K : K-1)) {

        auto tmp = T;
        T.clear();

        vector<string> cands;
        for (auto& t: tmp){
            int n = t.size();

            if (r % 2 == 1){
                T.emplace_back(t.substr(0, n/2));
                T.emplace_back(t.substr(n/2+1, n/2));

                cands.emplace_back(t.substr(n/2, 1));
            } else {
                T.emplace_back(t.substr(0, n/2));
                T.emplace_back(t.substr(n/2, n/2));
            }
            auto& s = T.back();
            reverse(ALL(s));
        }
        cand_list.emplace_back(cands);
        r >>= 1;
    }

    cand_list.emplace_back(T);

//    print(cand_list);

    int ans = 0;
    REP(i, cand_list.size()){
        auto& cands = cand_list[i];
        if (cands.empty()) continue;

        int sz = cands[0].size();

        if (sz == 1){
            map<char, int> mp;
            for (auto& s: cands){
                mp[s[0]]++;
            }
            int mx = 0;
            for (auto& [c, n]: mp){
                mx = max(mx, n);
            }
            ans += cands.size() - mx;

        } else {

            vector<map<char, int>> mp(sz);
            vector<vector<pair<int, char>>> ord(sz);

            REP(j, sz){
                for (auto& s: cands){
                    mp[j][s[j]]++;
                }
                for (auto& [c, n]: mp[j]){
                    ord[j].emplace_back(n, c);
                }
                sort(ALL(ord[j]), greater());
            }

            int tmp = 0;
            REP(j, sz){
                tmp += cands.size() - ord[j][0].first;
            }
//            print(ord);

            string s1, s2;
            REP(j, sz/2){
                s1 += ord[j][0].second;
                s2 += ord[sz-1-j][0].second;
            }
//            print(s1, s2, tmp);

            if (s1 != s2){
                ans += tmp;
            } else {
                int diff = INF;
                REP(j, sz){
                    if (sz % 2 == 1 && j == sz/2) continue;

                    if (ord[j].size() == 1) {
                        diff = min(diff, (int)cands.size());
                    } else {
                        diff = min(diff, ord[j][0].first - ord[j][1].first);
                    }
                }
                ans += tmp + diff;
            }
        }
    }

    print(ans);



    return 0;
}
