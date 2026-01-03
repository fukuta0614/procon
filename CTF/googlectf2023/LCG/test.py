from math import gcd
import numpy as np

# Short way for calculating the determinant of a 3*3 matrix
def calc_det(val1, val2, val3, val4):
    return abs(val1 * val3 - val1 * val4 + val2 * val3 - val2 * val2 + val2 * val4 - val3 * val3)


# Just to remove a few factors, the modulus might still multiplied by a small factor, like 2 or 10
def factor(value):
    sprimes = [0x02, 0x03, 0x05, 0x07, 0x0B, 0x0D, 0x11, 0x13,
               0x17, 0x1D, 0x1F, 0x25, 0x29, 0x2B, 0x2F, 0x35]
    counter = 0
    while counter < len(sprimes):
        if value % sprimes[counter] == 0:
            value //= sprimes[counter]
        else:
            counter += 1
    return value


# Should do the trick to calculate the different GCDs of the determinants
def get_modulus(detlist):
    tempGCD = detlist.copy()
    length = len(detlist)
    for k in range(1, length):
        for i in range(length - k):
            tempGCD[i] = gcd(tempGCD[i], tempGCD[i + 1])
    return factor(tempGCD[0])


def extgcd(a, b):
    if b == 0:
        return 1, 0
    x, y = extgcd(b, a % b)
    return y, x - (a // b) * y


def mod_inverse(a, m):
    x, y = extgcd(a, m)
    return (m + x % m) % m

# Short way to solve the 2 equations
def lin_solve(val1, val2, val3, modulus):
    temp1 = val1 % modulus
    temp2 = val2 % modulus
    temp3 = val3 % modulus
    retval1 = ((modulus + temp2 - temp3) * mod_inverse(modulus + temp1 - temp2, modulus)) % modulus
    retval2 = (temp2 - (retval1 * temp1)) % modulus
    return retval1, retval2


# This code calculates the Seed of the LCG if nth number is known. Just a cheap reversal of the LCG
def calc_seed(a, k, m, nr, nth):
    retval = nr % m
    for i in range(nth - 1, -1, -1):
        retval = (retval - k) % m
        retval = retval * mod_inverse(a, m) % m
    return retval


def main():
    # outputcount = 8
    # detlistlength = outputcount - 3
    # lcgoutput = np.zeros(outputcount, dtype=int)
    # detlist = np.zeros(detlistlength, dtype=int)
    # result = 12345
    # print("Using the LCG values: ")
    # for i in range(8):
    #     result = (16807 * result + 78125) % 2147483647
    #     lcgoutput[i] = result
    #     print(result, end=" ")
    # print()

    lcgoutput = [
        # 211286818345627549183608678726370412218029639873054513839005340650674982169404937862395980568550063504804783328450267566224937880641772833325018028629959635,
        2166771675595184069339107365908377157701164485820981409993925279512199123418374034275465590004848135946671454084220731645099286746251308323653144363063385,
        6729272950467625456298454678219613090467254824679318993052294587570153424935267364971827277137521929202783621553421958533761123653824135472378133765236115,
        2230396903302352921484704122705539403201050490164649102182798059926343096511158288867301614648471516723052092761312105117735046752506523136197227936190287,
        4578847787736143756850823407168519112175260092601476810539830792656568747136604250146858111418705054138266193348169239751046779010474924367072989895377792,
        7578332979479086546637469036948482551151240099803812235949997147892871097982293017256475189504447955147399405791875395450814297264039908361472603256921612,
        2550420443270381003007873520763042837493244197616666667768397146110589301602119884836605418664463550865399026934848289084292975494312467018767881691302197
    ]
    outputcount = len(lcgoutput)

    # detlist = []
    # for i in range(len(lcgoutput)-3):
    #     detlist.append(calc_det(lcgoutput[i], lcgoutput[i + 1], lcgoutput[i + 2], lcgoutput[i + 3]))
    # modulus = get_modulus(detlist)

    modulus = 8311271273016946265169120092240227882013893131681882078655426814178920681968884651437107918874328518499850252591810409558783335118823692585959490215446923

    for i in range(len(lcgoutput)):
        if modulus < lcgoutput[i]:
            print("Modulus is too small (" + str(modulus) + "), probably no LCG")
            return
    a, k = lin_solve(lcgoutput[0], lcgoutput[1], lcgoutput[2], modulus)
    print(f"The LCG function is : x[n] = ( {a}*x[n-1] + {k} ) % {modulus}")

    seed = calc_seed(a, k, modulus, lcgoutput[outputcount - 1], outputcount)
    print(f"The Seed used was: {seed}")

    print("config_m=", a)
    print("config_c=", k)
    print("config_n=", modulus)

if __name__ == "__main__":
    main()
