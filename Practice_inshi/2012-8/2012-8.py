import re

reg = re.compile(r'(\w{3}) (-?\w+) (-?\w+)')


def kadai1(text):

    for line in text.split('\n'):
        print(reg.search(line).groups()[1])

def kadai3456(text):

    order = text.split('\n')
    sub_i = []
    func_i = []
    i = 0
    variables = [{}]

    while i < len(order):
        print(variables)
        op1,op2,op3 = reg.search(order[i]).groups()
        print(i+1,op1,op2,op3)
        if op1 == 'SET':
            try:
                op3 = int(op3)
            except:
                op3 = variables[len(func_i)][op3]
            variables[len(func_i)][op2] = op3
            i += 1
            continue

        elif op1 == 'ADD':
            try:
                op2 = int(op2)
            except:
                op2 = variables[len(func_i)][op2]
            variables[len(func_i)][op3] += op2
            i += 1
            continue

        elif op1 == 'PRN':
            print(variables[len(func_i)][op2],variables[len(func_i)][op3])
            break

        elif op1 == 'JMP':
            i += int(op2)
            continue

        elif op1 == 'CMP':
            try:
                op2 = int(op2)
            except:
                op2 = variables[len(func_i)][op2]
            try:
                op3 = int(op3)
            except:
                op3 = variables[len(func_i)][op3]

            if op2 == op3:
                i += 2
                continue
            else:
                i += 1
                continue

        elif op1 == 'SUB':
            sub_i.append(i)
            i += int(op2)
            continue

        elif op1 == 'BAK':
            i = sub_i.pop() + 1
            continue

        elif op1 == 'CAL':
            try:
                op3 = int(op3)
            except:
                op3 = variables[len(func_i)][op3]
            variables.append({'in':op3})
            func_i.append(i)
            i += int(op2)
            continue

        elif op1 == 'RET':
            try:
                op2 = int(op2)
            except:
                op2 = variables[len(func_i)][op2]
            i = func_i.pop() + 1
            variables[len(func_i)]['out'] = op2
            variables.pop()

def fib(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)


if __name__ == '__main__':
    with open('sample2.txt') as f:
        text = f.read()

    # kadai1(text)
    kadai3456(text)
    # print(fib(10))