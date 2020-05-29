
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
        -  objdump -M intel -d main

    - hexdump
    - strings
    - readelf
    - binwalk
    - steghide
    - exiftool
    - dd
    - zteg
    - stegsolve
        - https://github.com/zardus/ctf-tools/blob/master/stegsolve/install

- https://github.com/bwall/HashPump
    
- https://github.com/zardus/ctf-tools

- pwntools


- 逆コンパイラ
    - webで
        - https://retdec.com/
    - Ghidra
        - 逆アセンブル、逆コンパイルができる
    - IDA pro
        - 無償で、逆アセンブル、デバッガ
        - 有償だと、逆コンパイルもできる
    

## 全般

- タイトルはだいぶ意味がある
- よくわからない文字列出てきたら、とりあえずぐぐると、なにかのフォーマットだったりする
 
## 参考

- よさげ
    - https://wiki.mma.club.uec.ac.jp/CTF/Toolkit

- web IDE
    - https://uxmilk.jp/15406
        - まとめがある。

## Cryptpgraphy
- RSA
    - https://www.slideshare.net/sonickun/rsa-n-ssmjp
    - http://elliptic-shiho.hatenablog.com/entry/2015/11/12/182219 

## Reverse Engineering

- アセンブリ勉強
    - http://milkpot.sakura.ne.jp/note/x86.html
    - https://github.com/Dvd848/CTFs/blob/master/2019_picoCTF/asm3.md
    - https://hackmd.io/@K-atc/HkV9t7chW?type=view
    
## PWN

- まとめ記事
    - https://raintrees.net/projects/a-painter-and-a-black-cat/wiki/CTF_Pwn


        
- 関数callまとめ
    - 関数call
        - push arg
        - push ret_addr(関数callの次の命令のアドレス)
    - called関数の最初
        - push ebp
        - mov ebp esp
            - 関数コールされる前のebpを保持しておく。retされたときに元の状態に戻れるように
            - そのうえで、今の関数のebpを新しくセットする
    - called関数の最後
        - leave (= mov esp ebp; pop ebp)
            - espとebpを関数に入る前の状態に戻す
        - ret (= pop eip)
            - eip(プログラムカウンタ)
            - 関数callの次の命令アドレス(ret_addr)に飛ぶ

- 攻撃手法
    - スタックバッファオーバーフロー
        - buf[64]みたいな自動変数が合ったときに、標準入力などで64を超えてbufに入力すると、buf用に確保しているスタック上のメモリの外を書き換えることができる
        - 関数callが終わって抜けるときに、呼び出し元に戻るためにret_addrがスタック上にセットされているため、これを書き換えたら任意のとこに飛ばすことができる。
        - 32bitだと、引数もスタックに置かれるので、引数も自由に渡せる
        - ret2plt, ret2libc
            - リターンアドレスに、標準ライブラリや動的ライブラリの関数のアドレスを指定することで、system系の関数を実行することができる。
            - これで/bin/shとかを起動できて、乗っ取り完了
    - ROP (return oriented programming)
        - 飛ばしたい関数に飛ばしたあとに、さらに別の関数に飛ばしたい場合がある
        - 適切な関数callの処理を経ずに関数に飛ぶと、呼び出し元のret_addrがかかれないので、今のスタックの一個上がそれにあたる
        - つまり、最初のオーバーフローで、ret_addr1, ret_addr2と書き換えると、関数1に飛ばしたあとに、ret命令でpop eipするとret_addr2に飛ばすことができる
        - ただ、引数を渡したい場合、関数1と関数2で使う引数の領域がかぶるのでうまくできない
        - そこで、バイナリ上で、pop ~, retのように、関数の最後にスタックをpopしてからretしてくる命令片に飛ばすことができれば、
        - スタックをいい感じの操作して関数2に飛ばすことができる。
        - これでいい感じに飛ばしまくるのがROP
            - pop ~, retしてる部分のことをrop gadgetと呼び、それを見つけるツールがある
    - printf書式文字列攻撃とGOT overwrite
        - https://qiita.com/k-onishi/items/9cf7fc49107e6ff61115
        
        
- シェルコード
    - https://book.mynavi.jp/manatee/detail/id=64562
    - 一覧
        - http://shell-storm.org/shellcode/
    - x86のシェルコード
        - http://shell-storm.org/shellcode/files/shellcode-827.php

- ツール
    - rop gadget見つけるやつ
    - python2のpwntools

- malloc
    - すごい詳細
        - https://www.valinux.co.jp/technologylibrary/document/linux/malloc0001/
        - https://www.slideshare.net/kosaki55tea/glibc-malloc?ref=http://rkx1209.hatenablog.com/entry/2019/01/04/230503
    
    - 攻撃手法
        - House of Orange   

- 64bit
    - スタックのアラインメント
        - https://uchan.hateblo.jp/entry/2018/02/16/232029
    
    
## web系

- 全般
    - titleにヒントがあるかも？

- 攻撃手法

    - CVE-2012-1823
        - http://ctfq.sweetduet.info:10080/~q12/?-s とすると、コードが見れるやつ
    
    - perl open文を使ったCGIプログラムの脆弱性 
        - https://www.ipa.go.jp/security/awareness/vendor/programmingv1/a04_01.html
        - ディレクトリトラバーサル
            - $ENV{'PATH_INFO'}に、../../etc/passwdとかをいれると、問答無用で読めてしまう。
            - 今回は関係ない。
        - OSコマンドインジェクション
            - パイプ文字「|」で終了するファイルパスをopen文でオープンすると，パイプ文字を除いたファイルパス部分が指す外部プログラムが実行される
            - http://ctfq.sweetduet.info:10080/~q26/index.pl/ls|
            - とすると、lsコマンドが実行されて、その結果が出力される
        
- 認証系知識
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
                
            

## SQL

- コマンド系
    - sqlite3コマンド
        - .tables でテーブルの一覧
        - .showでdbの概要

- 攻撃手法
    - 基本的なSQLインジェクション
        - 基本
            - ' or 1=1 --
           
    - ブラインドSQLインジェクション
        - sqlを色々叩いて、ログインが成功したかどうかのレスポンスによってそのレコードが存在するかを見る
        - 叩きまくって、レコードの中身を推定する手法

## Forensic

- ~を渡されたら試して見る系
    - https://qiita.com/knqyf263/items/6ebf06e27be7c48aab2e#%E3%83%87%E3%82%A3%E3%82%B9%E3%82%AF%E3%82%A4%E3%83%A1%E3%83%BC%E3%82%B8%E3%81%8C%E6%B8%A1%E3%81%95%E3%82%8C%E3%81%9F%E5%A0%B4%E5%90%88
- バイナリファイル解析系
    - https://qiita.com/elu697/items/8b4b67fea20bd8733730
    
- zip
    - zip : unzip
    - tar.gz : tar zxvf 
    - gz : gzip -d 
    - xz : xz -d 


    
               




