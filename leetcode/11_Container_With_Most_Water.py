class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height)-1
        mx = 0
        while i < j:
            a = min(height[i], height[j]) * (j - i)
            mx = max(mx, a)

            if height[i] < height[j]:
                k = i
                i += 1
                while i < j and height[i] <= height[k]:
                    i += 1
            else:
                k = j
                j -= 1
                while i < j and height[j] <= height[k]:
                    j -= 1

        return mx


if __name__ == '__main__':

    solution = Solution()

    height = [1, 2, 3, 4, 5]

    print(solution.maxArea(height))