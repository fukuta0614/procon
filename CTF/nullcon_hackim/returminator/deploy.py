import subprocess
import sys

o = [296, 272, 272, 272, 296, 360, 272, 424, 272, 208, 120, 120, 120, 96, 120, 120, 120, 120, 120, 120, 120, 208, 120, 120, 208, 208, 208, 208, 208, 272, 120, 208, 208]
r = [208, 225, 237, 20, 214, 183, 79, 105, 207, 217, 125, 66, 123, 104, 97, 99, 107 , 105, 109, 50, 48, 202, 111, 111, 29, 63, 223, 36, 0, 124, 100, 219, 32]

#
flag = bytearray(len(r))

for loop in range(len(r)):

    for x in range(255):
        flag[loop] = x
        with open('flag', 'wb') as f:
            f.write(flag)

        cmd = ['./main']
        rets = []

        with open('blob', 'rb') as f:
            for offset in o:
                data = f.read(offset)
                # with open('flag', 'ab') as f2:
                #     f2.write(data + b'\n')
                p = subprocess.Popen(cmd, stdin=subprocess.PIPE)
                p.stdin.write(data)
                p.communicate()
                rets.append(p.returncode)

        try:
            print(x, rets, flag.decode(), file=sys.stderr)
        except:
            print(x, rets, file=sys.stderr)

        if rets[loop] == r[loop]:
            break

        if all([rets[i] == r[i] for i in range(len(r))]):
            print('Yes!')
        else:
            print('No!')
