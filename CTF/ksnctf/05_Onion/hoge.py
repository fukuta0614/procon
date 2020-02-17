import base64

with open('bin.txt') as f:
    s = f.read()


for i in range(20):
    try:
        s = base64.b64decode(s)
    except:
        pass
    print(s)


print(len(s))