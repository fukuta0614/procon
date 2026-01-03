/*
Short way for calculating the determinant of a 3*3 matrix
*/
ZZ calcDet(ZZ val1, ZZ val2, ZZ val3, ZZ val4)
{
    return abs(val1*val3 - val1*val4 + val2*val3 - val2*val2 + val2*val4 - val3*val3);
}
/*
Just to remove a few factors, the modulus might still
multiplied by a small factor, like 2 or 10
*/
ZZ factor(ZZ value)
{
    unsigned int sprimes[16] = {0x02,0x03,0x05,0x07,0x0B,0x0D,0x11,0x13,
                                0x17,0x1D,0x1F,0x25,0x29,0x2B,0x2F,0x35};
    int counter = 0;
    while(counter < 16)
    {
        if(value % sprimes[counter] == 0) value /= sprimes[counter];
        else counter++;
    }
    return value;
}
/*
Should do the trick to calculate the different GCDs of the determinants
*/
ZZ getModulus(ZZ * detlist, int length)
{
    ZZ * tempGCD = new ZZ[length];
    for(int i = 0;i<length;i++)
    {
        tempGCD[i] = detlist[i];
    }
    for(int k = 1;k<length;k++)
    {
        for(int i = 0;i<length-k;i++)
            2
        {
            tempGCD[i] = GCD(tempGCD[i],tempGCD[i+1]);
        }
    }
    return factor(tempGCD[0]);
}
/*
Short way to solve the 2 equations
*/
void linsolve(ZZ val1, ZZ val2, ZZ val3, ZZ modulus, ZZ &retval1, ZZ &retval2)
{
    ZZ_p::init(modulus);
    ZZ_p temp1 = to_ZZ_p(val1);
    ZZ_p temp2 = to_ZZ_p(val2);
    ZZ_p temp3 = to_ZZ_p(val3);
    retval1 = rep((temp2-temp3)/(temp1-temp2));
    retval2 = rep(temp2-(to_ZZ_p(retval1)*temp1));
}
/*
This code calculates the Seed of the LCG if nth number is known
Just a cheap reversal of the LCG
*/
ZZ calcSeed(ZZ a, ZZ k, ZZ m, ZZ nr, int nth)
{
    ZZ_p::init(m);
    ZZ_p retval;
    retval = to_ZZ_p(nr);
    for(int i = nth-1;i>=0;i--)
    {
        retval -= to_ZZ_p(k);
        retval /= to_ZZ_p(a);
    }
    return rep(retval);
}
int main()
{
    int outputcount = 8;
    int detlistlength = outputcount - 3;
    ZZ * lcgoutput = new ZZ[outputcount]; // lcgoutput contains
// the collected consecutive lcg output values
    ZZ * detlist = new ZZ[detlistlength];
    ZZ modulus;
    ZZ a,k,seed;
    cout << "Using the LCG values: " << endl;
/* Basic Linear Congruential Generator */
    3
    __int64 result = 12345;
    for(int i = 0;i<8;i++)
    {
        result = 16807*result+78125;
        result %= 2147483647;
        lcgoutput[i] = result;
        cout << result << " ";
    }
/* ------------------------------------*/
    cout << endl;
    for(int i = 0;i<detlistlength;i++)
    {
        detlist[i] = calcDet(lcgoutput[i],lcgoutput[i+1],lcgoutput[i+2],lcgoutput[i+3]);
    }
    modulus = getModulus(detlist,detlistlength);
    for(int i = 0;i<outputcount;i++)
    {
        if(modulus < lcgoutput[i])
        {
            cout << "Modulus is too small (" << modulus <<"), probably no LCG" << endl;
            exit(-1);
        }
    }
    linsolve(lcgoutput[0],lcgoutput[1],lcgoutput[2],modulus,a,k);
    cout << "The LCG function is : x[n] = ( " << a;
    cout << "*x[n-1] + " << k << " ) % " << modulus << endl;
    seed = calcSeed(a,k,modulus,to_ZZ(lcgoutput[outputcount-1]),outputcount);
    cout << "The Seed used was: " << seed << endl;
    return 0;
}