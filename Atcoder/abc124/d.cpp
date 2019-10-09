// abc124_d
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

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<int> list_1, list_0;

    if (S[0] == '0') list_1.emplace_back(0);
    REP(i, N){

        int tmp = i;
        if (S[i] == '0'){
            while (tmp < N && S[tmp] == '0') tmp++;
            list_0.emplace_back(tmp - i);
        } else {
            while (tmp < N && S[tmp] == '1') tmp++;
            list_1.emplace_back(tmp - i);
        }
        i = tmp-1;
    }
    if (S[N-1] == '0') list_1.emplace_back(0);

//    print(list_1);
//    print(list_0);

    if (list_0.empty() || list_1.empty()){
        print(N);
        return 0;
    }

    int tmp = list_1[0];
    int ans = 0;
    REP(i, list_0.size()){
        tmp += list_1[i+1];
        tmp += list_0[i];

        if (i >= K){
            tmp -= list_1[i-K];
            tmp -= list_0[i-K];
        }
        ans = max(ans, tmp);
    }

    print(ans);

    return 0;
}
