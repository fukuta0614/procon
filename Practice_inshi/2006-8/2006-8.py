
alphabet = 'abcdefghijklmnopqrstuvwxyz'
ALPHABET = alphabet.upper()

def kadai1():
    with open('q1.txt') as f:
        txt= f.read()

    for k in range(1,26):
        print(k)
        new_txt = ''
        for s in txt:
            if s.isupper():
                try:
                    new_txt += ALPHABET[ALPHABET.index(s)+k]
                except:
                    new_txt += ALPHABET[ALPHABET.index(s)+k - 26]
            elif s.islower():
                try:
                    new_txt += alphabet[alphabet.index(s)+k]
                except:
                    new_txt += alphabet[alphabet.index(s)+k - 26]
            else:
                new_txt += s
        print(new_txt)
if __name__ == '__main__':
    kadai1()