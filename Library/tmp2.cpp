#include <bits/stdc++.h>
using namespace std;

const long long INF = 1001001001001001001ll;

int size;
vector<long long> val;
vector<long long> lazy;

void lazy_propagate(int p) {
    if (lazy[p] != -1) {
        val[p] = lazy[p];
        if (p < size-1) {
            lazy[p*2+1] = lazy[p];
            lazy[p*2+2] = lazy[p];
        }
        lazy[p] = -1;
    }
}

void update(int wishl, int wishr, int watchl, int watchr, int k, int x) {
    if (wishr <= watchl || watchr <= wishl) {
        lazy_propagate(k);
        return;
    }
    if (wishl <= watchl && watchr <= wishr) {
        lazy[k] = x;
        lazy_propagate(k);
        return;
    }
    int mid = (watchl+watchr)/2;
    lazy_propagate(k);
    update(wishl, wishr, watchl, mid, k*2+1, x);
    update(wishl, wishr, mid, watchr, k*2+2, x);
    val[k] = min(val[k*2+1], val[k*2+2]);
}
void update(int wishl, int wishr, int x) {
    update(wishl, wishr, 0, size, 0, x);
}

long long getmin(int wishl, int wishr, int watchl, int watchr, int k) {
    if (wishr <= watchl || watchr <= wishl) {
        return INF;
    }
    if (wishl <= watchl && watchr <= wishr) {
        lazy_propagate(k);
        return val[k];
    }
    int mid = (watchl+watchr)/2;
    lazy_propagate(k);
    long long ml = getmin(wishl, wishr, watchl, mid, k*2+1);
    long long mr = getmin(wishl, wishr, mid, watchr, k*2+2);
    return min(ml, mr);
}
long long getmin(int wishl, int wishr) {
    return getmin(wishl, wishr, 0, size, 0);
}

signed main() {
    int n, q;
    cin >> n >> q;
    size = 1;
    while (size < n) size <<= 1;
    val = vector<long long>(size*2, (1ll<<31)-1);
    lazy = vector<long long>(size*2, -1);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 0) {
            int x;
            cin >> x;
            update(l, r+1, x);
        } else {
            cout << getmin(l, r+1) << endl;
        }
    }
    return 0;
}