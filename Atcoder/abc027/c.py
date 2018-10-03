N = int(input())

if N == 1:
    print('Aoki')
    exit()

i = 0
while 2**(i+1) <= N:
    i += 1

if i % 2 == 1:
    x = 1
    while True:
        x = 2 * x
        if x > N:
            print('Aoki')
            exit()
        x = 2 * x + 1
        if x > N:
            print('Takahashi')
            exit()

else:
    x = 1
    while True:
        x = 2 * x + 1
        if x > N:
            print('Aoki')
            exit()
        x = 2 * x
        if x > N:
            print('Takahashi')
            exit()
