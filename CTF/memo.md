
## 必要ソフトまとめ

- wireshark

- sqlite3


## 参考
- KSNCTF
    - http://gky360.hatenablog.com/entry/2019/04/16/094409
    - http://gky360.hatenablog.com/entry/2019/04/25/230015
    -

## SQL

- 一般
    - sqlite3コマンド
        - .tables でテーブルの一覧
        - .showでdbの概要


- ksnctf 32 simple auth
    - 参考
        - https://qiita.com/CTFman/items/9224b86a5cbf757ed85e
    - phpのstrcasecmpには脆弱性があるらしい。
    - strcasecmp($_POST['password'], $password) == 0)
    - postクエリのpasswordが、配列だと問答無用で返り値が0になるらしい。
    - <input type="password" name="password[]"> nameの中身に[]をつけると、配列として送信できるらしい。
    - htmlをこんな漢字にいじって、適当に0とか入れて送信すると通った。


- ksnctf 35 simple auth 2
    $db = new PDO('sqlite:database.db');
    $s = $db->prepare('SELECT * FROM user WHERE id=? AND password=?');
    $s->execute(array($_POST['id'], $_POST['password']));

    - id=? というのは、あとからparameterをもらって実行できるようにするための文法らしい。
    - id=' + s + ' みたいにやると、悪意あるユーザに変なsql実行されちゃうらしい。
    - この問題では、database.dbの場所がまずくて、普通に相対パスでこのphpと同じ場所にdatabase.dbがあるのでダウンロードできる。
    - file コマンドで見ると sqlite3 とわかるので、userを見るとroot, flag~とパスワードが見える

## web

- ksnctf 08 basic is secure
    - basic認証サイトにアクセスしたときのpcapログ
    - 色々見てたらpasswordがあった。それがflagだった。