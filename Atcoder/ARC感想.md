

## Atcoder Regular Contest


## Atcoder Grand Contest

### agc014

- B : Unplanned Queries
    - 概要
        - 木のa-bのパスの辺に+1する、という操作をいくつかする
        - 全ての辺が偶数となるように木を構築できるか
    - 解法
        - クエリ a-b　は、根をrとすると r-a と r-b　に分解できる。
            - a-b = a-lca + lca-b 
            - r-a + r-b =  a-lca + lca-r + r-lca + lca-b = a-lca + lca-b
        - よって、r-vのパスに+1するという操作 f(v) が2M回行われるということ
        - 全クエリ中で、f(v)のvとして現れる回数が奇数だったら、絶対に奇数の辺ができる。
        - ので、結局、a-bとして現れる頂点の回数を数えて遇数のみならYes、そうでないならNO