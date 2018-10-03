# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"


class Rect(object):
    def __init__(self, a, b, c, d):
        self.left = a
        self.bottom = b
        self.right = c
        self.top = d

    def area(self):
        return (self.right - self.left) * (self.top - self.bottom)


def overlap(rect1, rect2):
    l = max(rect1.left, rect2.left)
    r = min(rect1.right, rect2.right)
    b = max(rect1.bottom, rect2.bottom)
    t = min(rect1.top, rect2.top)

    if l < r and b < t:
        return (r - l) * (t - b)
    else:
        return 0


def solution(K, L, M, N, P, Q, R, S):
    # write your code in Python 2.7
    rect1 = Rect(K, L, M, N)
    rect2 = Rect(P, Q, R, S)

    S = rect1.area() + rect2.area() - overlap(rect1, rect2)

    return S


print(solution(K=-4, L=1, M=2, N=6, P=0, Q=-1, R=4, S=3))

