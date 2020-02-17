

def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True



import requests
pi = requests.get("https://www.angio.net/pi/digits/pi1000000.txt").content.decode()


for i in range(2, 10):
    n = int(pi[i: i+10])
    if is_prime(n):
        print(n)
        break

