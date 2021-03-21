const vals = ['value', '2wfTpTR', 'instantiate', '275341bEPcme', 'innerHTML', '1195047NznhZg', '1qfevql', 'input', '1699808QuoWhA', 'Correct!', 'check_flag', 'Incorrect!', './JIFxzHyW8W', '23SMpAuA', '802698XOMSrr', 'charCodeAt', '474547vVoGDO', 'getElementById', 'instance', 'copy_char', '43591XxcWUl', '504454llVtzW', 'arrayBuffer', '2NIQmVj', 'result'];
const func = function (x, _0x53c021) {
    x = x - 0x1d6;
    return vals[x];
};
(function (vals_tmp, y) {
    const func2 = func;
    while (!![]) {
        try {
            const z = -parseInt(func2(0x1eb)) + parseInt(func2(0x1ed)) + -parseInt(func2(0x1db)) * -parseInt(func2(0x1d9)) + -parseInt(func2(0x1e2)) * -parseInt(func2(0x1e3)) + -parseInt(func2(0x1de)) * parseInt(func2(0x1e0)) + parseInt(func2(0x1d8)) * parseInt(func2(0x1ea)) + -parseInt(func2(0x1e5));
            if (z === y) break; else vals_tmp['push'](vals_tmp['shift']());
        } catch (_0x41d31a) {
            vals_tmp['push'](vals_tmp['shift']());
        }
    }
}(vals, 0x994c3));


let exports;

(async () => {
    let res = await fetch('./JIFxzHyW8W'),
        res2 = await WebAssembly.instantiate(await res.arrayBuffer()),
        res3 = res2.instance;
    exports = res3['exports'];
})();

function onButtonPress() {
    const func = func;
    let val = document['getElementById']('input')['value'];

    for (let i = 0x0; i < val['length']; i++) {
        exports.copy_char(val.charCodeAt(i), i);
    }
    exports.copy_char(0x0,
        val['length']),
        exports.check_flag() == 0x1 ?
            document.getElementById("result").innerHTML = func(0x1e6) :
            document.getElementById("result").innerHTML = func(0x1e8);
}

