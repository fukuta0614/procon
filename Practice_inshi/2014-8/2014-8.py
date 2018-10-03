from collections import OrderedDict

def kadai1():
    with open('main.cpp') as f:
        txt = f.read().split('\n')

    count = 0
    for line in txt:
        if ';' in line:
            count += 1
    print(count)

def kadai2():
    with open('main.cpp') as f:
        txt = f.read().split('\n')

    for i,line in enumerate(txt):
        print(i,line)

def kadai3():
    with open('main.cpp') as f:
        txt = f.read().split('\n')

    previous = ''
    for i,line in enumerate(txt):
        # print(previous,line)
        if line == previous:
            print(line)
        previous = line

def kadai4():
    with open('main.cpp') as f:
        txt = f.read().split('\n')

    lines = []
    repetition = set()

    for i,line in enumerate(txt):
        if not line in lines:
            lines.append(line)
        else:
            repetition.add(line)

    for line in lines:
        if line in repetition:
            print(line)

def similarity(s1,s2):
    if len(s1) > len(s2):
        s2 = s2 + ' '*(len(s1)-len(s2))
    if len(s1) < len(s2):
        s1 = s1 + ' '*(len(s2)-len(s1))

    # print(s1+'!')
    # print(s2+'!')
    count = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            count += 1
    return count


def kadai5():
    with open('sampe.txt') as f:
        txt = f.read().split('\n')

    over_20 = []
    for line in txt:
        if len(line) >= 20:
            over_20.append(line)

    for i in range(len(over_20)):
        for j in range(i+1, len(over_20)):
            k = similarity(over_20[i],over_20[j])
            if 0 < k < 5:
                print(over_20[i],over_20[j])

def levenshtein_distance(x,y):

    distance = [ [ 0 for _ in range(len(x)+1)] for _ in range(len(y) + 1) ]

    for i in range(len(x)+1):
        distance[0][i] = i
    for i in range(len(y)+1):
        distance[i][0] = i

    for i in range(len(y)):
        for j in range(len(x)):

            if x[j] == y[i]:
                a = 0
            else:
                a = 1
            distance[i+1][j+1] = min( distance[i][j+1]+1, distance[i+1][j]+1, distance[i][j]+a)

    print('      {}  {}  {}  {} '.format(x[0],x[1],x[2],x[3]))
    for i,t in enumerate(distance):
        if i > 0:
            print(y[i-1],t)
        else:
            print(' ',t)

    return distance[-1][-1]

def kadai6():
    with open('sampe.txt') as f:
        txt = f.read().split('\n')

    over_20 = []
    for line in txt:
        if len(line) >= 20:
            over_20.append(line)

    for i in range(len(over_20)):
        for j in range(i+1, len(over_20)):
            k = levenshtein_distance(over_20[i],over_20[j])
            if 0 < k < 4:
                print(over_20[i],over_20[j])

def kadai7():
    with open('sampe.txt') as f:
        txt = f.read().split('\n')

    temp = ''
    count = 1

    for line in txt:
        if line == temp:
            count += 1
        else:
            if count >= 4:
                print('             ' + temp)
            temp = line
            count = 1
        print(count,line)


if __name__ == '__main__':
    # kadai1()
    # kadai2()
    # kadai3()
    # kadai4()
    # kadai5()
    # kadai6()
    # kadai7()
    from bs4 import BeautifulSoup
    import requests,os,urllib
    os.chdir('/Users/fukuta0614/Documents/Program/python/Document/2')
    url = 'http://www.geocities.jp/m_hiroi/light/'
    soup = BeautifulSoup(requests.get(url).content)
    for x in soup.find_all('a'):
        try:
            if '#' in x['href'] or '/' in x['href']:
                continue
            page_url = urllib.parse.urljoin(url,x['href'])
            s = BeautifulSoup(requests.get(page_url).content)
            with open('{}.html'.format(x.text),'w') as f:
            # with open('百五減算.html','w') as f:
                f.write(str(s))
        except:
            pass
