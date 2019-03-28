
S = [int(_) for _ in list(input())]
print(len(S) - abs(2 * sum(S) - len(S)))

# import numpy as np
# S = np.random.randint(0, 2, size=100)
#
#
#
# S = ''.join([str(x) for x in S])
#
#
#
# # s = sum(S)
# # s = s if s > len(S) / 2 else len(S) - s
# #
# # print(2 * s - len(S))
#
#
# print(S)
# a = len(S)
# s = ''
# while s != S:
#     s = S
#     S = S.replace("01", "")
#     S = S.replace("10", "")
#
#     print(s, S)
#
# print(S)
#
# print(a - len(S))
