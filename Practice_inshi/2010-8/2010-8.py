

def compress_ex(s):
    if len(s) > 1000:
        result = ''
        part = len(s) // 1000
        for p in range(part+1):
            r = compress(s[p*1000:(p+1)*1000])
            if p == 13:
                print(r)
            result += r
        return result


def compress(s):

    d = {}
    for i in range(len(s)-5):
        c = s[i:i+6]
        if c in d:
            # print(d[c])
            pass
        else:
            d[c] = '{:03d}'.format(i)

    j = 0
    temp_list = []
    while j < len(s) - 5:
        c = s[j:j+6]

        if c in d:

            if c in temp_list:
                for k in range(1,6):
                    c_prime = s[j+k:j+k+6]
                    if c_prime in d:
                        temp_list.append(c_prime)

                if j > 1600 and j < 1800:
                    print(c, d[c])
                    print(s[1500:1800])
                s = s[0:j] + d[c] + s[j+6:]
                j += 3
            else:
                temp_list.append(c)
                j+=1

        else:
            j += 1
    return s

def tenkai_ex(s):

    i = 0
    result = ''
    loop = 1
    while i < len(s):
        # print(i)
        # print(s[:i+100])
        if s[i].isdigit():
            try:
                num = int(s[i:i+3])
            except:
                print(s[:i+200])
                print(loop)
                exit()
            c = s[num:num+6]
            for k in range(len(c)):
                if c[k].isdigit():
                    c = s[num:i]
                    break
            while len(c) < 6:
                c = s[num:i] + c
            c = c[:6]
            s = s[0:i] + c + s[i+3:]

        i += 1
        if i >= 1000:
            result+=s[:1000]
            s = s[1000:]
            i = 0
            loop += 1
    result += s
    return result

def tenkai(s):
    d = {}
    i = 0
    while i < len(s):
        # print(i)
        # print(s[:i+100])
        if s[i].isdigit():
            print(s)
            num = int(s[i:i+3])
            c = s[num:num+6]
            print('start:' + c)
            print('start:',num,i)
            for k in range(len(c)):
                if c[k].isdigit():
                    print(num,k)
                    # c = c[:k] + c[:k]
                    # c =
                    print('1:'+c)
                    break
            while len(c) < 6:
                c = s[num:i] + c
                print('2:' + c)
            c = c[:6]


            if i > 3050 and i < 3140:
                print(c)
                print(s[3050:3150])
            s = s[0:i] + c + s[i+3:]

        i += 1

    return s

def compress_tenkai(s):
    s2 = compress(s)
    # print('\ncompress  :' + s2)
    s3 = tenkai(s2)
    print('\ntenkai    :' + s3)


def compress_tenkai_ex(s):
    s2 = compress_ex(s)
    # print('\ncompress  :' + s2)
    s3 = tenkai_ex(s2)
    print('\ntenkai    :' + s3)
    print(origin == s3)

if __name__ == '__main__':
    global origin
    with open('2010_8_ci_practice_data/s3.txt') as f:
        origin = f.read()
    # compress_tenkai(origin)
    compress_tenkai_ex(origin)
    # origin = ' .001001001..... build it up'
    # print(tenkai(origin))