//
// Created by 福田圭佑 on 2021/02/23.
//

struct Cumsum2D{

    int H, W;
    vector<vector<ll>> cumsum;

    Cumsum2D(int H, int W, const vector<vector<ll>>& v) : H(H), W(W), cumsum(H+1, vector<ll>(W+1, 0)) {

        assert(static_cast<int>(v.size()) == H);
        assert(static_cast<int>(v[0].size()) == W);

        REP(i, H) {
            ll tmp = 0;
            REP(j, W){
                tmp += v[i][j];
                cumsum[i+1][j+1] = cumsum[i][j+1] + tmp;
            }
        }
    }

    // (i,j) -> (x,y)の合計 (i,j,x,yを含む）
    ll sum(int i, int j, int x, int y){
        if (i < 0 || j < 0) return 0;
        if (x >= H || y >= W) return 0;
        if (i > x || j > y) return 0;
        return cumsum[x+1][y+1] - cumsum[x+1][j] - cumsum[i][y+1] + cumsum[i][j];
    }

};
