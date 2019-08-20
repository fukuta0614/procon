
import numpy as np

with open("arg.txt", "w") as f:
    N = 5000
    M = 5000
    f.write("{} {}\n".format(N, M))

    for i in range(N):
        f.write("{}\n".format(np.random.randint(1, M)))