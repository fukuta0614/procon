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

// 区間add, 区間sum
template<typename T>
struct LazySegmentTree{
    int n;
    vector<T> val;
    vector<T> lazy;
    vector<int> width;

    explicit LazySegmentTree(int n_){
        n = 1;
        while (n < n_) n <<= 1;

        val = vector<T>(n<<1, 0);
        lazy = vector<T>(n<<1, 0);
        width = vector<int>(n<<1, 1);
        for (int i = n-2; i >= 0; i--) {
            width[i] = width[i*2+1] + width[i*2+2];
        }
    }
    void lazy_propagate(int k) {
        val[k] += lazy[k] * width[k];
        if (k < n-1) {
            lazy[k*2+1] += lazy[k];
            lazy[k*2+2] += lazy[k];
        }
        lazy[k] = 0;
    }
    void add(int a, int b, int k, int l, int r, int x) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x;
            lazy_propagate(k);
            return;
        }
        int mid = (l+r)/2;
        add(a, b, k*2+1, l, mid, x);
        add(a, b, k*2+2, mid, r, x);
        val[k] = val[k*2+1] + val[k*2+2];
    }

    void add(int a, int b, int x) {
        add(a, b, 0, 0, n, x);
    }

    T get_sum(int a, int b, int k, int l, int r) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return val[k];
        }
        int mid = (l+r)/2;
        T sl = get_sum(a, b, k*2+1, l, mid);
        T sr = get_sum(a, b, k*2+2, mid, r);
        return sl + sr;
    }

    T get_sum(int a, int b) {
        return get_sum(a, b, 0, 0, n);
    }
};


// starry sky
template<typename T>
struct LazySegmentTree{ // 区間add, 区間min
    int n;
    vector<T> val;
    vector<T> lazy;

    explicit LazySegmentTree(int n_){
        n = 1;
        while (n < n_) n <<= 1;

        val = vector<T>(n<<1, 0); // TODO 初期値セット
        lazy = vector<T>(n<<1, 0);
    }
    void lazy_propagate(int k) {
        val[k] += lazy[k];
        if (k < n-1) {
            lazy[k*2+1] += lazy[k];
            lazy[k*2+2] += lazy[k];
        }
        lazy[k] = 0;
    }
    void add(int a, int b, int k, int l, int r, int x) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x;
            lazy_propagate(k);
            return;
        }
        int mid = (l+r)/2;
        add(a, b, k*2+1, l, mid, x);
        add(a, b, k*2+2, mid, r, x);
        val[k] = min(val[k*2+1], val[k*2+2]);
    }

    void add(int a, int b, int x) {
        add(a, b, 0, 0, n, x);
    }

    T get_min(int a, int b, int k, int l, int r) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return INF;
        }
        if (a <= l && r <= b) {
            return val[k];
        }
        int mid = (l+r)/2;
        T sl = get_min(a, b, k*2+1, l, mid);
        T sr = get_min(a, b, k*2+2, mid, r);
        return min(sl, sr);
    }

    T get_min(int a, int b) {
        return get_min(a, b, 0, 0, n);
    }
};

// 区間update, 区間min
template<typename T>
struct LazySegmentTree{
    int n;
    vector<T> val;
    vector<T> lazy;

    explicit LazySegmentTree(int n_){
        n = 1;
        while (n < n_) n <<= 1;

        val = vector<T>(n<<1, INF); // TODO 初期値セット
        lazy = vector<T>(n<<1, -1);
    }
    void lazy_propagate(int k) {
        if (lazy[k] == -1) return;

        val[k] = lazy[k];
        if (k < n-1) {
            lazy[k*2+1] = lazy[k];
            lazy[k*2+2] = lazy[k];
        }
        lazy[k] = -1;
    }
    void update(int a, int b, int k, int l, int r, int x) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] = x;
            lazy_propagate(k);
            return;
        }
        int mid = (l+r)/2;
        update(a, b, k*2+1, l, mid, x);
        update(a, b, k*2+2, mid, r, x);
        val[k] = min(val[k*2+1], val[k*2+2]);
    }

    void update(int a, int b, int x) {
        update(a, b, 0, 0, n, x);
    }

    T get_min(int a, int b, int k, int l, int r) {
        lazy_propagate(k);

        if (b <= l || r <= a) {
            return INF;
        }
        if (a <= l && r <= b) {
            return val[k];
        }
        int mid = (l+r)/2;
        T sl = get_min(a, b, k*2+1, l, mid);
        T sr = get_min(a, b, k*2+2, mid, r);
        return min(sl, sr);
    }

    T get_min(int a, int b) {
        return get_min(a, b, 0, 0, n);
    }
};