// var v = ['9f266}', '_again_1', 'this', 'Password\x20Verified', 'Incorrect\x20password', 'getElementById', 'value', 'substring', 'picoCTF{', 'not_this'];


// (function (a, b) {
//     var c = function (x) {
//         while (--x) {
//             a['push'](a['shift']());
//         }
//     };
//     c(++b);
// }(v, 0x1b3));

var func = function (a, _0x4b81bb) {
    a = a - 0x0;
    var b = v[a];
    return b;
};

var v = ["getElementById", "value", "substring", "picoCTF{", "not_this", "9f266}", "_again_1", "this", "Password Verified", "Incorrect password"];

flag = "picoCTF{not_this_again_19f266}";

function verify() {
    checkpass = document[func('0x0')]('pass')[func('0x1')];
    split = 0x4;
    if (checkpass[func('0x2')](0x0, split * 0x2) == func('0x3')) {
        if (checkpass[func('0x2')](0x7, 0x9) == '{n') {
            if (checkpass[func('0x2')](split * 0x2, split * 0x2 * 0x2) == func('0x4')) {
                if (checkpass[func('0x2')](0x3, 0x6) == 'oCT') {
                    if (checkpass[func('0x2')](split * 0x3 * 0x2, split * 0x4 * 0x2) == func('0x5')) {
                        if (checkpass['substring'](0x6, 0xb) == 'F{not') {
                            if (checkpass[func('0x2')](split * 0x2 * 0x2, split * 0x3 * 0x2) == func('0x6')) {
                                if (checkpass[func('0x2')](0xc, 0x10) == func('0x7')) {
                                    alert(func('0x8'));
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        alert(func('0x9'));
    }
}