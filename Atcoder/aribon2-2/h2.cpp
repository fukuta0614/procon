// aribon2-2_h
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
#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define ALL(x) x.begin(), x.end()
#define COUT(x) cout << x << endl
#define COUT_2DARR(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int N, K;
string S;

string asdf;

void solve3(){
    string minS = S;
    string T = S;

    sort(ALL(minS));
    REP(i, N){
        int x = 0;
        REPN_REV(j, i, N) {
            if (T[j] == minS[i]) { swap(T[i], T[j]); x = j; break; }
        }

        int sm = 0;
        REP(j, N){
            if (T[j] != S[j]) sm++;
        }

        COUT(i << " " << T << " " << sm);


        if (sm > K){
            swap(T[i], T[x]); //戻す

            string ans = T;
            REPN(j, i, N){
                swap(T[i], T[j]);
                sm = 0;
                REP(k, N){ if (T[k] != S[k]) sm++; }
                if (sm <= K && T < ans) ans = T;
                swap(T[i], T[j]);
            }

            vector<int> mismatch;
            REPN(j, i, N){
                if (ans[j] != S[j]) mismatch.emplace_back(j);
            }

            string s;
            for (auto idx: mismatch) s += ans[idx];
            sort(ALL(s));

            REP(j, s.size()){
                ans[mismatch[j]] = s[j];
            }
            COUT(ans); asdf = ans;
            return;
        }
    }
    COUT(T); asdf = T;

}

void solve(){
    string unused = S;
    sort(ALL(unused));

    int cur_mismatch = 0;
    string T = "";
    string tmp;
    REP(i, N){
        REP(j, unused.size()){
            tmp = T + unused[j];
            int tmp_mismatch = cur_mismatch + ((unused[j] != S[i]) ? 1 : 0);
            string x = S.substr(i+1); sort(ALL(x));
            string unused_tmp = unused; unused_tmp.erase(j,1);
            vector<int> v(x.size());
            auto it = set_intersection(ALL(x), ALL(unused_tmp), v.begin());
            int mismatch =  tmp_mismatch + (N-i-1 - distance(v.begin(), it));
            if (mismatch <= K){
                cur_mismatch = tmp_mismatch;
                T = tmp;
                unused = unused_tmp; sort(ALL(unused));
                break;
            }
        }
    }
    COUT(T); asdf = T;
}

void solve2(){

    string T = S;
    sort(ALL(T));
    string ans = S;
    do {
        int sm = 0;
        REP(i, N) sm += (T[i] != S[i]) ? 1 : 0;
        if (sm <= K && T < ans){
            ans = T;
        }
    } while (next_permutation(ALL(T)));

    if (asdf != ans){
        COUT("***********************");
    }
    COUT(ans);
}


void solve4(){
    string minS = S;
    string T = S;

    string ans = S;
    REP(i, N){
        REPN(j, i, N) {
            swap(T[i], T[j]);
            int sm = 0;
            REP(k, N) { if (T[k] != S[k]) sm++; }
            if (sm <= K && T < ans) ans = T;
            swap(T[i], T[j]);

        }
        T = ans;
    }
    COUT(ans); asdf = ans;
}

void solve6(){
    string T = S;
    string ans = S;
    REP(i, N){
        int minSm = INF;
        REPN(j, i, N) {
            string tmp = T;
            swap(tmp[i], tmp[j]);
            int sm = 0;
            REP(k, N) { if (tmp[k] != S[k]) sm++; }
//            COUT(i << " " << j << " " << tmp << " " << sm << " " << minSm);
            if (sm <= K && (tmp.substr(0,i+1) < ans.substr(0,i+1) || (tmp.substr(0,i+1) == ans.substr(0,i+1) && sm < minSm))){
                ans = tmp;
                minSm = sm;
            }
        }
//        COUT(i << " " << ans);
        T = ans;
    }
    COUT(ans); asdf = ans;
}

void solve5(){
    int n, k;
    string s, t, u;
    s = S;n = N; k = K;
    t = s;
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = i+1; j < n; j++) {
            if (t[x] > t[j]) {
                u = t;
                swap(u[i], u[j]);
                int cnt = 0;
                for (int l = 0; l < n; l++) if (s[l] != u[l]) cnt++;
                if (cnt <= k) x = j;
            }
        }
        swap(t[i], t[x]);
    }
    cout << t << endl;
}

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

//    cin >> N >> K;
//    cin >> S;
//    COUT(S << endl);
////    solve();
//    solve2();
////    solve4();
////    solve5();
//    solve6();

    REP(i, 100){
        S = "";
        random_device rd;
        mt19937 mt(rd());

        N = mt() % 10 + 1;
        K = mt() % N + 1;

        std::uniform_int_distribution<int> dist(0, 25);
        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        REP(j, N){ S += alphabets[dist(mt)];}

        COUT(N << " " << K);
        COUT(S);

        solve6();
        solve2();
    }


    return 0;
}
