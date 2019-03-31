import numpy as np

n = np.random.randint(100,200)
x = np.random.randint(1, 100000)
with open("./arg.txt", "w") as f:
    f.write("{} {}\n".format(n, x))
    for i in range(n):
        f.write("{} ".format(np.random.randint(1, 100000)))
    f.write("\n")
