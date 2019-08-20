//
// Created by 福田圭佑 on 2019/08/18.
//


template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    F f;
    T ti;
    vector<T> dat;
    SegmentTree(F f, T ti, int n_) : f(f), ti(ti) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }
    void update(int k, T x) {
        k += n - 1;
        dat[k] = x;
        while (k > 0){
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        // [a, b)と[l, r)が交差しなければ単位元を返す
        if (r <= a || b <= l) return ti;

        // [a, b)が[l, r)を完全に含んでいればその節点の値
        if (a <= l && r <= b) return dat[k];

        int m = (l + r) / 2;
        T vl = query(a, b, k*2+1, l, m);
        T vr = query(a, b, k*2+2, m, r);
        return f(vl, vr);
    }
    T query(int a, int b) { // wrapper
        return query(a, b, 0, 0, n);
    }
};