import re
import itertools
import functools
from collections import OrderedDict
import pprint
import regex

pp = pprint.PrettyPrinter(indent=4)
alphabet = 'abcdefghijklmnopqrstuvxyz'
alphabet_c = 'ABCDEFGHIJKLMNOPQRSTU'
pattern = r"(?<rec>\((?:[^()]+|(?&rec))*\))"

def kadai1(s):
    le = s.split('+')
    print(le)

def kadai23(s):
    v = []
    for c in alphabet:
        if c in s:
            v.append(c)
    # print(v)
    le = s.split('+')
    answer_list = []
    for product in itertools.product([0,1],repeat=len(v)):
        value_dict = OrderedDict(zip(v,product))
        print(value_dict)
        for e in le:
            # binary_value = functools.reduce(lambda a,b: a*b, map(lambda x:value_dict[x],e.split('&')))
            L = []
            for x in e.split('&'):
                if '!' in x:
                    x = 1 - value_dict[x.replace('!','')]
                else:
                    x = value_dict[x]
                L.append(x)
            binary_value = functools.reduce(lambda a,b: a*b,L)
            print(e, binary_value)
            if binary_value == 1:
                answer_list.append(value_dict)
                break

    if len(answer_list) == 0:
        print('none')
    else:
        pp.pprint(answer_list)

def kadai4(s):

    def check(s,value_dict):
        parentheses = regex.finditer(pattern, s, flags=regex.VERBOSE)
        rec = []
        for i,m in enumerate(parentheses):
            matching_pattern = m.group('rec')
            rec.append(matching_pattern)
            s = s.replace(matching_pattern,alphabet_c[i])
        le = s.split('+')
        print(le)
        for e in le:
            # binary_value = functools.reduce(lambda a,b: a*b, map(lambda x:value_dict[x],e.split('&')))
            L = []
            for x in e.split('&'):
                if '!' in x:
                    if x in alphabet_c:
                        x = re.search(r'\((.+)\)',rec[alphabet_c.find(x)]).groups()[0]
                        if check(x,value_dict):
                            x = 0
                        else:
                            x = 1
                    else:
                        x = 1 - value_dict[x.replace('!','')]
                else:
                    if x in alphabet_c:
                        x = re.search(r'\((.+)\)',rec[alphabet_c.find(x)]).groups()[0]
                        if check(x,value_dict):
                            x = 1
                        else:
                            x = 0
                    else:
                        x = value_dict[x]
                L.append(x)
            print(L)
            binary_value = functools.reduce(lambda a,b: a*b,L)
            print(e, binary_value)
            if binary_value == 1:
                return True

    v = [x for x in alphabet if x in s]
    answer_list = []
    for product in itertools.product([0,1],repeat=len(v)):
        value_dict = OrderedDict(zip(v,product))
        print(value_dict)
        if check(s,value_dict):
            answer_list.append(value_dict)

    if len(answer_list) == 0:
        print('none')
    else:
        pp.pprint(answer_list)


def kadai56(s):

    def validate(s):
        result = []
        for x in s.split('+'):
            e = set()
            for t in x.split('&'):
                if negative_dnf(t) in e:
                    e.remove(negative_dnf(t))
                else:
                    e.add(t)
            result.append('&'.join(list(e)))
        return '+'.join(result)

    def tenkai_one(a,b):
        print(a,b)
        L = b.split('+')
        l = map(lambda x:'{}&{}'.format(a,x),b.split('+'))
        return '+'.join(l)

    def negative_dnf(s):
        s = tenkai(s)
        if not '+' in s:
            if not '&' in s:
                if not '!' in s:
                    return '!' + s
                else:
                    return s.replace('!','')
            else:
                return '+'.join(map(lambda x:negative_dnf(x),s.split('&')))

        else:
            print('&'.join(map(lambda x:'({})'.format(negative_dnf(x)),s.split('+'))))
            return tenkai('&'.join(map(lambda x:'({})'.format(negative_dnf(x)),s.split('+'))))

    def cnf(s):
        return '&'.join(map(lambda x:'({})'.format(negative_dnf(x)),s.split('+')))

    def tenkai(s):

        parentheses = regex.finditer(pattern, s, flags=regex.VERBOSE)
        rec = []
        flag = 0
        for i,m in enumerate(parentheses):
            matching_pattern = m.group('rec')
            rec.append(matching_pattern)
            s = s.replace(matching_pattern,alphabet_c[i])
            flag = 1
        if flag==0:
            return s
        else:
            sections = s.split('+')
            result = []
            for section in sections:
                elements = section.split('&')
                for i in range(len(elements)):
                    if elements[i] in alphabet_c:
                        elements[i] = re.search(r'\((.+)\)',rec[alphabet_c.find(elements[i])]).groups()[0]

                    elif elements[i].replace('!','') in alphabet_c:
                        elements[i] = negative_dnf(re.search(r'\((.+)\)',rec[alphabet_c.find(elements[i].replace('!',''))]).groups()[0])

                print(elements)######
                for k in range(len(elements)):
                    elements[k]=tenkai(elements[k])
                    print(elements[k])
                for j in range(len(elements)-2,-1,-1):
                    result_section = []
                    for e in elements[j].split('+'):
                        result_section.append(tenkai_one(e,elements[-1]))
                    elements[-1] = '+'.join(result_section)
                    print(elements)######
                result.append(elements[-1])
            result = '+'.join(result)

            return validate(result)

    s = (tenkai(s))
    print(s)
    print(cnf(s))



if __name__ == '__main__':
    with open('sample.txt') as f:
        s = f.read()
    s = 'b&a+b&c+a&b&c'
    s = '!a&b&!c+a&d!'
    # s = 'b&(a+b&c)+a&b&c'
    s = 'b&!((!a+b)&c+d)+a&b&!(c+d)'
    # s = '(a+b)&(c+d)+a&(a+b+c)'
    # s = 'a&b&(c+d)'
    kadai56(s)