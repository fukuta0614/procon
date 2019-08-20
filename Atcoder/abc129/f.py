

import os
import numpy as np


for i in range(1000):
    a = np.random.randint(0, 1000000000000000000)
    b = np.random.randint(0, 1000000000000000000)
    m = np.random.randint(0, 1000000000)
    l = np.random.randint(0, max(10, (1000000000000000000-a)//b))

    if (a + b * (l-1) > 1000000000000000000):
        continue

    print(l, a, b, m)
    with open("../arg.txt", "w") as f:
        f.write("{} {} {} {}".format(l, a, b, m))

    os.system("cmake-build-debug/abc129_f")
    os.system("cmake-build-debug/abc129_f2")

