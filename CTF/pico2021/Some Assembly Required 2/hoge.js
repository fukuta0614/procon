const vals = ['copy_char', 'value', '207aLjBod', '1301420SaUSqf', '233ZRpipt', '2224QffgXU', 'check_flag', '408533hsoVYx', 'instance', '278338GVFUrH', 'Correct!', '549933ZVjkwI', 'innerHTML', 'charCodeAt', './aD8SvhyVkb', 'result', '977AzKzwq', 'Incorrect!', 'exports', 'length', 'getElementById', '1jIrMBu', 'input', '615361geljRK'];
const func = function (x, _0x4d6e6c) {
    x = x - 0xc3;
    return vals[x];
};

(function (_0x12fd07, _0x4e9d05) {
    while (!![]) {
        try {
            const _0x1bb902 = -parseInt(func(0xc8)) * -parseInt(func(0xc9)) + -parseInt(func(0xcd)) + parseInt(func(0xcf)) + parseInt(func(0xc3)) + -parseInt(func(0xc6)) * parseInt(func(0xd4)) + parseInt(func(0xcb)) + -parseInt(func(0xd9)) * parseInt(func(0xc7));
            if (_0x1bb902 === _0x4e9d05) break; else _0x12fd07['push'](_0x12fd07['shift']());
        } catch (_0x4f8a) {
            _0x12fd07['push'](_0x12fd07['shift']());
        }
    }
}(vals, 0x4bb06));


let exports;
(async () => {
    let a = await fetch("./aD8SvhyVkb"),
        b = await WebAssembly.instantiate(await a.arrayBuffer()),
        c = b.instance;
    exports = c.exports;
})();

function onButtonPress() {
    let a = document.getElementById("input").value;
    for (let i = 0x0; i < a['length']; i++) {
        exports.copy_char(a.charCodeAt(i), i);
    }
    exports.copy_char(0x0, a.length), exports.check_flag() == 0x1 ?
            document.getElementById(func(0xd3))[func(0xd0)] = func(0xce) :
            document.getElementById(func(0xd3))['innerHTML'] = func(0xd5);
}