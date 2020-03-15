# import untwister
import struct

with open('encrypt.key', 'rb') as f:
    data = f.read()

with open("nums.txt", 'w') as f:
    for i in range(len(data)//4):
        n = struct.unpack('<I', data[4*i:4*i+4])[0]
        f.write(str(int(n)) + '\n')
# sample = [int(x) for x in data]
# results = untwister.bruteforce(untwister.MT19937, sample, threads=4)
# print(results)
