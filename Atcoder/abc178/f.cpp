// abc178_f
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
//struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

random_device rd;
mt19937 mt(rd());

// だめでした。

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];

//    int N = 20;
//    vector<int> A(N), B(N);
//    REP(i, N) A[i] = mt() % N;
//    REP(i, N) B[i] = mt() % N;
//    sort(ALL(A));
//    sort(ALL(B));
//    print(A);
//    print(B);

//    vector<int> st;
//    set_intersection(ALL(A), ALL(B), back_inserter(st));
//    print(st);
    vector<vector<int>> mpA(N+1);
    REP(i, N) mpA[A[i]].emplace_back(i);

    vector<vector<int>> mpB(N+1);
    REP(i, N) mpB[B[i]].emplace_back(i);

    auto cmpA = [](P a, P b) { return a.first == b.first ? a.second > b.second : a.first > b.first; };
    set<P, decltype(cmpA)> pqA(cmpA);

    auto cmpB = [](P a, P b) { return a.first == b.first ? a.second < b.second : a.first > b.first; };
    set<P, decltype(cmpB)> pqB(cmpB);

    REP(i, N+1) if (not mpA[i].empty()) pqA.emplace(mpA[i].size(), i);
    REP(i, N+1) if (not mpB[i].empty()) pqB.emplace(mpB[i].size(), i);

//    print(pqA, pqB);

    int i = 0;
    vector<int> ans(N);
    while (not pqA.empty()){

        int numA = pqA.begin()->first;
        int a = pqA.begin()->second;

        while (numA > 0) {
            auto it = pqB.begin();
//            print(A);
//            print(ans);
//            print(pqA);
//            print(pqB);
            while (it != pqB.end() && a == it->second){
                it++;
//            print("an", *it);
            }
            if (it == pqB.end()){
                print("No");
                return 0;
            }
            int numB = it->first;
            int b = it->second;

//            print(a, b);

            if (numA <= numB){
                REP(j, numA){
                    int idx = mpA[a].back();
                    mpA[a].pop_back();

                    ans[idx] = b;
                }
                pqB.erase(it);
                if (numA != numB) pqB.emplace(numB-numA, b);

                numA = 0;

            } else {
                REP(j, numB){
                    int idx = mpA[a].back();
                    mpA[a].pop_back();
                    ans[idx] = b;
                }
                pqB.erase(it);

                numA -= numB;
            }
        }

        pqA.erase(pqA.begin());

    }

    print("Yes");
    print_line(ans, N);

//    bool valid = true;
//    print(A);
//    print(ans);
//    REP(i, N) if (A[i] == ans[i]) valid = false;
//    print(B);
//    sort(ALL(ans));
//    print(ans);
//    REP(i, N) if (ans[i] != B[i]) valid = false;
//    print(valid);


    return 0;
}
