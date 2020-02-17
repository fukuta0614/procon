

s = "EBG KVVV vf n fvzcyr yrggre fhofgvghgvba pvcure gung ercynprf n yrggre jvgu gur yrggre KVVV yrggref nsgre vg va gur nycunorg. EBG KVVV vf na rknzcyr bs gur Pnrfne pvcure, qrirybcrq va napvrag Ebzr. Synt vf SYNTFjmtkOWFNZdjkkNH. Vafreg na haqrefpber vzzrqvngryl nsgre SYNT."

for offset in range(1, 26):

    tmp = ""
    for c in s:
        if c.islower():
            # print('lower', c, chr((ord(c) - ord('a') + offset) % 26 + ord('a')))
            tmp += chr((ord(c) - ord('a') + offset) % 26 + ord('a'))
        elif c.isupper():
            # print('upper', c, chr((ord(c) - ord('A') + offset) % 26 + ord('A')))
            tmp += chr((ord(c) - ord('A') + offset) % 26 + ord('A'))
        else:
            tmp += c
    print(tmp)