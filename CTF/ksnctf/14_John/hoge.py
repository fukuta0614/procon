import hashlib
import base64
import crypt

# passwordの暗号化は、ただsha512に変換してからbase64でエンコードするより色々やっているらしい
# https://stackoverflow.com/questions/34463134/sha-512-crypt-output-written-with-python-code-is-different-from-mkpasswd/34463995#34463995

# print(crypt.crypt("password", "$6$Z4xEy/1KTCW.rz$"))
# digest = hashlib.sha512("password".encode()).digest()
# print(digest)
# s = base64.b64encode(digest)
# print(s)

with open("dicti0nary_8Th64ikELWEsZFrf.txt") as f:
    words = f.read().split("\n")[:-1]

with open("shadow.txt") as f:
    users = f.read().split("\n")[:-1]

passwords = []
for user in users:
    s = user.split(':')[1].split("$")
    salt = "$".join(s[:3]) + "$"
    passwd = s[3]
    passwords.append((salt, passwd))

for salt, passwd in passwords:
    for word in words:
        tmp = crypt.crypt(word, salt).split("$")[3]
        if tmp == passwd:
            print(word)
            break

# FLAG_aSiuJHSLfzoQkszD
