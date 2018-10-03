class FenwickTree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * self.size

    def update(self, index, value):
        x = index
        while x < self.size:
            if self.tree[x] < value:
                self.tree[x] = value
            else:
                return
            x |= x + 1

    def maximum(self, index):
        # 半開区間[0,index)
        ret = 0
        x = index - 1
        while x >= 0:
            ret = max(ret, self.tree[x])
            x = (x & (x + 1)) - 1
        return ret