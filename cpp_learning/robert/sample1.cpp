//
// Created by Fukuta Keisuke on 1/21/18.
//

#include <bits/stdc++.h>

using namespace std;

# define debug(x) cerr <<  #x << ": " << x << endl;

double average_stddev(double *data, int count) {
    double sum, square_sum, ave, var, std_dev;
    int i;
    // 総和と二乗の総和を計算
    sum = square_sum = 0.0;
    for (i = 0; i < count; i++) {
        sum += data[i];
        square_sum += data[i] * data[i];
    }
    // 標準偏差の計算
    ave = var = std_dev = 0.0;
    if (count > 0) {
        ave = sum / (double) count;
        // (分散) = (二乗の平均) - (平均)^2
        var = square_sum / (double) count - ave * ave;
        std_dev = sqrt(var);
    }
    return std_dev;
}

int main() {
    //　今回用いるデータは0.2 0.2 0.2 の配列で、標準偏差は0になるはずである。
    double data[] = {0.2, 0.2, 0.2};
    printf("std_dev: %f", average_stddev(data, 3));
    return 0;
}