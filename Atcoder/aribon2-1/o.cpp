// asdf_o
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define ALL(x) x.begin(), x.end()
#define COUT(x) cout << x << endl

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    sort(ALL(A)); sort(ALL(B));

    double trial = 0;
    double vic = 0;
    do {
        do {
            int count = 0;
            REP(i, N) {if (A[i] > B[i]) count++;}
            if (2 * count > N) vic++;
            trial++;
        } while( next_permutation(ALL(B)));
    } while( next_permutation(ALL(A)));

    COUT(vic / trial);

    return 0;
}
