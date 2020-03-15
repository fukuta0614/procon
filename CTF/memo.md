
## 必要ソフトまとめ

- wireshark

- sqlite3

- burpsuite
    - postとかを見れる？
    
- 今はいってないやつ
    - john the ripper
    - pkcrack

- python-stepic

- The Sleuth Kit (ファイルシステム解析？）

- fidller
    - HTTPデバッガ
    
- コマンド系
    - xdd
    - objdump
    - hexdump
    - strings
    - readelf
    - binwalk
    - steghide
    - exiftool
    - dd
    - 

- https://github.com/bwall/HashPump
    
- https://github.com/zardus/ctf-tools

## 全般

- タイトルはだいぶ意味がある
- よくわからない文字列出てきたら、とりあえずぐぐると、なにかのフォーマットだったりする
 
## 参考
- ~を渡されたら試して見る系
    - https://qiita.com/knqyf263/items/6ebf06e27be7c48aab2e#%E3%83%87%E3%82%A3%E3%82%B9%E3%82%AF%E3%82%A4%E3%83%A1%E3%83%BC%E3%82%B8%E3%81%8C%E6%B8%A1%E3%81%95%E3%82%8C%E3%81%9F%E5%A0%B4%E5%90%88
- バイナリファイル解析系
    - https://qiita.com/elu697/items/8b4b67fea20bd8733730
- よさげ
    - https://wiki.mma.club.uec.ac.jp/CTF/Toolkit

- web IDE
    - https://uxmilk.jp/15406
        - まとめがある。

## web系

- titleにヒントがあるかも？


## SQL``

- 一般
    - sqlite3コマンド
        - .tables でテーブルの一覧
        - .showでdbの概要

## zip

- zip : unzip
- tar.gz : tar zxvf 
- gz : gzip -d 
- xz : xz -d 


## 認証系

- basic認証
    - base64でユーザ名、アカウントをencodeして送る
    - base64
        - アルファベット(a~z, A~z)と数字(0~9)、記号(+,/)
        - パディングのための(=)も使う
        - URLようには +, /のかわりに-, _なども
        - データ列を6bitずつ取り出して、上記の割当で変更する
    - base64は超簡単にdecodeできるので、通信ログをみたら即バレる。
- Digest認証
    - ブラウザの挙動としては、
        1. まず普通にアクセスしに行く
        2. 401で弾かれて、以下のようなレスポンスがある
            - WWW-Authenticate: Digest realm="secret", nonce="bbKtsfbABAA=5dad3cce7a7dd2c3335c9b400a19d6ad02df299b", algorithm=MD5, qop="auth"\r\n
                - realmはサーバ側で設定した認証が必要なエリアの名前。
                - nonceはサーバ側が生成したランダムな文字列
                - algorithmはハッシュに使う関数
                    - 基本的にmd5が使われる
                - qopは「Quality of protection」
                    - authかauth-initが入る。digestを作る際にbodyを含めるかどうか。
        3. HTTPヘッダにアカウント情報を付与してもっかい送る
            - Authorization: Digest username="q9", realm="secret", nonce="bbKtsfbABAA=5dad3cce7a7dd2c3335c9b400a19d6ad02df299b", uri="/~q9/", algorithm=MD5, response="c3077454ecf09ecef1d6c1201038cfaf", qop=auth, nc=00000001, cnonce="9691c24
                ```sh
                A1 = ユーザ名 ":" realm ":" パスワード
                A2 = HTTPのメソッド ":" コンテンツのURI
                response = MD5( MD5(A1) ":" nonce ":" nc ":" cnonce ":" qop ":" MD5(A2) )
                ```
            - md5は、以下のサイトでよくある文字列に対する逆変換ができる
                - https://hashtoolkit.com/decrypt-hash/?hash=31e101310bcd7fae974b921eb148099c                   