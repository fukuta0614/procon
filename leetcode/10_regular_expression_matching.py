class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """

        self.s = s
        self.p = p
        self.dp = {}

        return self.func(0, 0)

    def func(self, i, j):
        if (i, j) in self.dp:
            return self.dp[(i, j)]

        ret = False
        if i == len(self.p) and j == len(self.s):
            ret = True

        elif i >= len(self.p):
            ret =  False

        elif self.p[i:i + 2] == '.*':
            for k in range(j, len(self.s) + 1):
                if self.func(i + 2, k):
                    ret = True
                    break

        elif self.p[i + 1:i + 2] == '*':
            for k in range(j, len(self.s) + 1):
                if k == j or self.p[i] == self.s[k - 1]:
                    if self.func(i + 2, k):
                        ret = True
                        break
                else:
                    break

        elif j >= len(self.s):
            ret = False

        elif self.p[i] == '.':
            ret = self.func(i + 1, j + 1)

        else:
            if self.p[i] == self.s[j]:
                ret = self.func(i + 1, j + 1)

        self.dp[(i, j)] = ret
        return ret


if __name__ == '__main__':
    solution = Solution()

    s = "aaaaaaaaaaaaaaaaaaab"
    p = "a*a*a*a*a*a*a*a*a*a*"

    print(solution.isMatch(s, p))
