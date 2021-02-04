//
// Created by 福田圭佑 on 2019/08/18.
//

// 0-index
struct BIT {
    int sz;
    vector<int> tree;

    BIT(int n) {
        sz = n;
        tree.resize(n+1);
    }

    ll sum(int i){
        i++;
        ll sm = 0;
        while (i > 0){
            sm += tree[i];
            i -= i & -i;
        }
        return sm;
    }

    void add(int i, int x){
        i++;
        while (i <= sz){
            tree[i] += x;
            i += i & -i;
        }
    }
};