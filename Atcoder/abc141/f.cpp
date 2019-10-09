// abc141_f
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


// C++ program to find
// maximum XOR subset
#include<bits/stdc++.h>
using namespace std;

// Number of bits to
// represent int
#define INT_BITS 62

// Function to return
// maximum XOR subset
// in set[]
ull maxSubarrayXOR(vector<ull> set, int n)
{
    // Initialize index of
    // chosen elements
    int index = 0;

    // Traverse through all
    // bits of integer
    // starting from the most
    // significant bit (MSB)
    for (int i = INT_BITS-1; i >= 0; i--)
    {
        // Initialize index of
        // maximum element and
        // the maximum element
        int maxInd = -1;
        for (int j = index; j < n; j++)
        {
            // If i'th bit of set[j]
            // is set and set[j] is
            // greater than max so far.
            if ( (set[j] & (1ull << i)) != 0) {
                maxInd = j;
                break;
            }
        }

        // If there was no
        // element with i'th
        // bit set, move to
        // smaller i
        if (maxInd == -1)
            continue;

        // Put maximum element
        // with i'th bit set
        // at index 'index'
        swap(set[index], set[maxInd]);

        // Update maxInd and
        // increment index
        maxInd = index;

        // Do XOR of set[maxIndex]
        // with all numbers having
        // i'th bit as set.
        for (int j=0; j<n; j++)
        {
            // XOR set[maxInd] those
            // numbers which have the
            // i'th bit set
            if (j != maxInd && (set[j] & (1ull << i)) != 0) {
                set[j] ^= set[maxInd];
            }
        }

        // Increment index of
        // chosen elements
        index++;
    }

    // Final result is
    // XOR of all elements
    ull res = 0;
    for (int i = 0; i < n; i++)
        res ^= set[i];
    return res;
}

ull maxSubarrayXOR2(vector<ull> a, int n){
    ll i, j;

    ull rank = 0;
    for (i = 59; i >= 0; i--) {
        for (j = rank; j < n; j++) {
            if (a[j] & (1LL << i)) break;
        }
        if (j == n) {
            continue;
        }

        if (j > rank) a[rank] ^= a[j];
        for (j = rank + 1; j < n; j++) {
            a[j] = min(a[j], a[j] ^ a[rank]);
        }

        rank++;
    }
    ull x = 0;
    for (i = 0; i < n; i++) {
        x ^= a[i];
//        x = max(x, x ^ a[i]);
    }

    return x;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<ull> A(N);
    REP(i, N) cin >> A[i];

    ull allxor = 0;
    REP(i, N) allxor ^= A[i];
    REP(i, N) A[i] &= ~allxor;

    ull res = allxor + 2 * maxSubarrayXOR(A, N);
    print(res);

    return 0;
}
