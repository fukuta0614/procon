from collections import defaultdict, OrderedDict
from itertools import combinations
import pprint, time, os, sys, math, copy, re, random

pp = pprint.PrettyPrinter(indent=4)

alphabet = 'abcdefghijklmnopqrstuvwxyz'


# with open('') as f:
#     txt = f.read().split('\n')[:-1]

def four_to_ten(arg):
    arg = str(arg)
    i = 0
    num = 0
    while i < len(arg):
        num += int(arg[-1 * (i + 1)]) * (4 ** i)
        i += 1
    return num


def eight_ten(arg):
    trans = OrderedDict(zip(alphabet[:8], range(8)))
    arg = ''.join(map(lambda x: str(trans[x]), arg))
    i = 0
    num = 0
    while i < len(arg):
        num += int(arg[-1 * (i + 1)]) * (8 ** i)
        i += 1
    return num


def num_to_roman(arg):
    arg_temp = arg
    used_alphabets = ('I', 'V', 'X', 'L', 'C', 'D', 'M')
    used_numbers = (1, 5, 10, 50, 100, 500, 1000)
    trans = OrderedDict(zip(used_numbers, used_alphabets))
    roman = ''
    for k in reversed(used_numbers):
        digit = 0
        while arg - (digit + 1) * k >= 0:
            digit += 1
        arg -= digit * k
        if digit == 4:
            if k == 100:
                if roman.endswith('D'):
                    roman = roman[:-1] + 'CM'
                else:
                    roman += 'CD'
            if k == 10:
                if roman.endswith('L'):
                    roman = roman[:-1] + 'XC'
                else:
                    roman += 'XL'
            if k == 1:
                if roman.endswith('V'):
                    roman = roman[:-1] + 'IX'
                else:
                    roman += 'IV'
        else:
            roman += trans[k] * digit

    return roman


def roman_to_num(arg):
    used_alphabets = ('I', 'V', 'X', 'L', 'C', 'D', 'M')
    used_numbers = (1, 5, 10, 50, 100, 500, 1000)
    trans = OrderedDict(zip(used_alphabets, used_numbers))
    pattern = '^(M{0,4})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$'
    match = re.search(pattern, arg)
    num = 0
    print(match.groups())
    for group in match.groups():
        if group == 'CM':
            num += 900
        elif group == 'CD':
            num += 400
        elif group == 'XC':
            num += 90
        elif group == 'XL':
            num += 40
        elif group == 'IX':
            num += 9
        elif group == 'IV':
            num += 4
        else:
            for g in group:
                num += trans[g]

    return num


def num_to_roman_ex(arg):
    arg_first = arg
    used_alphabets = ('I', 'V', 'X', 'L', 'C', 'D', 'M')
    used_numbers = (1, 5, 10, 50, 100, 500, 1000)
    trans = OrderedDict(zip(used_numbers, used_alphabets))
    roman = ''
    moved_flag = False
    change_flag = False

    minimum = len(num_to_roman(arg))
    # print(minimum)

    for k in reversed(used_numbers):
        # print(roman,moved_flag)
        digit = 0
        while True:
            sub = arg - (digit + 1) * k
            if sub >= 0:
                digit += 1
            else:
                min_arg = None
                min_roman = None
                if not moved_flag:
                    sub = abs(sub)
                    for n in used_numbers:
                        if n >= sub:
                            roman_temp = roman + digit * trans[k] + trans[n] + trans[k]
                            arg_temp = arg - (digit + 1) * k + n
                            # print(arg_temp)
                            if len(num_to_roman(arg_temp)) + len(roman_temp) < minimum:
                                minimum = len(num_to_roman(arg_temp)) + len(roman_temp)
                                min_arg = arg_temp
                                min_roman = roman_temp
                                change_flag = True
                    if min_arg is not None and min_roman is not None:
                        arg = min_arg
                        roman = min_roman
                    break
                else:
                    break

        if change_flag:
            moved_flag = True
            change_flag = False
            continue
        arg -= digit * k
        if digit == 4:
            if k == 100:
                if roman.endswith('D'):
                    roman = roman[:-1] + 'CM'
                else:
                    roman += 'CD'
            if k == 10:
                if roman.endswith('L'):
                    roman = roman[:-1] + 'XC'
                else:
                    roman += 'XL'
            if k == 1:
                if roman.endswith('V'):
                    roman = roman[:-1] + 'IX'
                else:
                    roman += 'IV'
        else:
            roman += trans[k] * digit

    if len(roman) <= len(num_to_roman(arg_first)):
        return arg_first, roman
    else:
        return


def under_thousand(arg):
    words = ('one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten',
             'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen',
             'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety', 'hundred', 'thousand')
    numbers = (
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000)

    trans = OrderedDict(zip(words, numbers))
    num = 0
    for x in arg.split(' '):
        if x == 'and':
            continue
        if len(x) > 0:
            if x == 'hundred':
                if num == 0:
                    num = 100
                else:
                    num *= 100
            else:
                num += trans[x]

    return num


def english_to_num(arg):
    if 'thousand' in arg:
        sections = arg.split('thousand')
        return under_thousand(sections[0]) * 1000 + under_thousand(sections[1])
    else:
        return under_thousand(arg)


def kadai1():
    print(four_to_ten(323))


def kadai2():
    print(eight_ten('cahf'))


def kadai3():
    # MMXV
    pass


def kadai4():
    # print(roman_to_num('XIII'))
    # print(roman_to_num('CCVII'))
    # print(roman_to_num('MLXVI'))
    # print(roman_to_num('MCMIV'))
    print(roman_to_num('MCCCLXI'))
    print(roman_to_num('MCDLXI'))


def kadai5():
    # print(13,num_to_roman(13))
    # print(207,num_to_roman(207))
    # print(1066,num_to_roman(1066))
    # print(1904,num_to_roman(1904))
    print(num_to_roman(1361))
    print(num_to_roman(1461))


def kadai6():
    print(num_to_roman_ex(499))
    print(num_to_roman_ex(1994))
    print(num_to_roman_ex(949))
    print(num_to_roman_ex(964))
    print(num_to_roman_ex(4991))
    print(num_to_roman_ex(3949))


def kadai7():
    print(english_to_num('twenty thousand and five hundred thirteen'))
    print(english_to_num('one thousand and two hundred'))
    print(english_to_num('two thousand fifteen'))


if __name__ == '__main__':
    # print('----kadai1----')
    # kadai1()
    # print('----kadai2----')
    # kadai2()
    # print('kadai3')
    # kadai3()
    # print('----kadai4----')
    kadai4()
    # print('----kadai5----')
    # kadai5()
    # print('----kadai6----')
    # kadai6()
    # print('----kadai7----')
    # kadai7()
