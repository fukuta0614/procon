// arc104_c
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


int N;


void ng(){
    print("No");
    exit(0);
}


bool kakutei(vector<int>& X, vector<int>& A, vector<int>& B){

    REP(i, 2*N){

        int idx = X[i];
        if (idx < N && B[idx] != -1){

            int c = B[idx] - A[idx];
            while (i < B[idx]){

                int idx2 = X[i];
                if (idx2 < N){
                    int b = i + c;

                    if (not (B[idx2] == -1 || B[idx2] == b)) return false;
                    if (not (X[b] == -1 || X[b] == idx2)) return false;
                    B[idx2] = b;
                    X[b] = idx2;
                } else {
                    idx2 -= N;
                    int a = i - c;

                    if (not (A[idx2] == -1 || A[idx2] == a)) return false;
                    if (not (X[a] == -1 || X[a] == idx2 + N)) return false;
                    A[idx2] = a;
                    X[a] = idx2 + N;
                }
            }
        }
    }
    return true;
}


bool dfs(vector<int> X, vector<int> A, vector<int> B){

    bool ret = kakutei(X, A, B);
    if (not ret) return false;

    REP(i, 2*N){

        if (X[i] != -1){
            if (X[i] < N){
                int idx = X[i];
                if (B[idx] != -1) continue;

                REPN(j, i+1, 2*N){
                    if (X[j] == -1){
                        X[j] = idx + N;
                        B[idx] = j;
                        ret = dfs(X, A, B);
                        if (ret) break;
                        X[j] = -1;
                        B[idx] = -1;
                    }
                }
            } else {
                int idx = X[i] - N;
                if (A[idx] != -1) continue;

                REPN_REV(j, 0, i){
                    if (X[j] == -1){
                        X[j] = idx;
                        A[idx] = j;
                        ret = dfs(X, A, B);
                        if (ret) break;
                        X[j] = -1;
                        A[idx] = -1;
                    }
                }
            }
        }
        if (ret) break;
    }

}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    cin >> N;

    vector<int> X(2*N, -1);
    vector<int> A(N), B(N);
    int unknown = 0;
    REP(i, N) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        if (A[i] != -1){
            X[A[i]] = i;
        } else {
            unknown++;
        }

        if (B[i] != -1){
            X[B[i]] = N + i;
        } else {
            unknown++;
        }
    }

    bool ret = kakutei(X, A, B);
    if (not ret){
        print("No");
        return 0;
    }

    print(A);
    print(B);

    ret = false;
    REP(i, 2*N){

        if (X[i] != -1){
            if (X[i] < N){
                int idx = X[i];
                REPN(j, i+1, 2*N){
                    if (X[j] == -1){
                        X[j] = idx + N;
                        B[idx] = j;
                        ret = dfs(X, A, B);
                        if (ret) break;
                        X[j] = -1;
                        B[idx] = -1;
                    }
                }
            } else {
                int idx = X[i] - N;
                REPN_REV(j, 0, i){
                    if (X[j] == -1){
                        X[j] = idx;
                        A[idx] = j;
                        ret = dfs(X, A, B);
                        if (ret) break;
                        X[j] = -1;
                        A[idx] = -1;
                    }
                }
            }
        }
        if (ret) break;
    }

    if (ret){
        print("Yes");
    } else {
        print("No");
    }





    return 0;
}
