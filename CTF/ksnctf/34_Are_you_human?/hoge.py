

with open("flag.jpg", 'wb') as f:
    x = bytearray(64)
    for i in range(64):
        x[i] = i
    f.write(x)