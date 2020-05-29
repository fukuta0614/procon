// past03_l
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    vector<deque<int>> T(N);
    REP(i, N){
        int k; cin >> k;
        REP(j, k){
            int t; cin >> t;
            T[i].emplace_back(t);
        }
    }

    int M;
    cin >> M;
    vector<int> A(M);
    REP(i, M) cin >> A[i];

    set<P> st1;
    set<P> st2;

    REP(i, N){
        if (T[i].size() >= 1){
            st1.insert(P(T[i].front(), i));
            st2.insert(P(T[i].front(), i));
            T[i].pop_front();
        }

        if (T[i].size() >= 1) {
            st2.insert(P(T[i].front(), i));
        }
    }

//    print(st1);
//    print(st2);

    REP(i, M){
        if (A[i] == 1){
            P p = *st1.rbegin();
            print(p.first);

            st1.erase(p);
            st2.erase(p);

            int idx = p.second;
            if (T[idx].size() >= 1){
                st1.insert(P(T[idx].front(), idx));
                T[idx].pop_front();
            }

            if (T[idx].size() >= 1){
                st2.insert(P(T[idx].front(), idx));
            }

        } else {
            P p = *st2.rbegin();
            print(p.first);

            int idx = p.second;

            if (T[idx].size() == 0){
                st1.erase(p);
                st2.erase(p);
            } else {

                if (p.first == T[idx].front()){ // 最大が2番目
                    st2.erase(p);
                    T[idx].pop_front();
                    if (T[idx].size() >= 1){
                        st2.insert(P(T[idx].front(), idx));
                    }
                } else { // 最大が先頭
                    st1.erase(p);
                    st2.erase(p);
                    st1.insert(P(T[idx].front(), idx));
                    T[idx].pop_front();

                    if (T[idx].size() >= 1){
                        st2.insert(P(T[idx].front(), idx));
                    }
                }
            }
        }
//        print(st1);
//        print(st2);

    }

    return 0;
}
