//  g++ -O2 -o encrypt.exe encrypt.cpp mt19937ar.cpp

#include <stdio.h>
#include <stdlib.h>
#include "mt19937ar.h"

typedef unsigned long dword;

void initialize(const char *seed);
void encrypt(const char *plain, const char *crypt, const char *key);
void decrypt(const char *plain, const char *crypt, const char *key);
int min(int a, int b) { return a<b ? a : b; }

int main()
{
    initialize("seed");
    
    encrypt("encrypt.cpp", "encrypt.enc", "encrypt.key");
    encrypt("flag.jpg", "flag.enc", "flag.key");
    
    //  decrypt("encrypt_dec.cpp", "encrypt.enc", "encrypt.key");
    //  decrypt("flag_dec.jpg", "flag.enc", "flag.key");
}

void initialize(const char *seed)
{
    const int N = 1024;
    
    FILE *f = fopen(seed, "rb");
    if (f==NULL)
    {
        printf("Failed to open %s\n", seed);
        exit(-1);
    }
    
    dword buf[N];
    fread(buf, sizeof (dword), N, f);
    
    fclose(f);
    
    init_by_array(buf, N);
}

void encrypt(const char *plain, const char *crypt, const char *key)
{
    FILE *fp = fopen(plain, "rb");
    if (fp==NULL)
    {
        printf("Failed to open %s\n", plain);
        exit(-1);
    }
    FILE *fc = fopen(crypt, "wb");
    if (fc==NULL)
    {
        printf("Failed to open %s\n", crypt);
        exit(-1);
    }
    FILE *fk = fopen(key, "wb");
    if (fk==NULL)
    {
        printf("Failed to open %s\n", key);
        exit(-1);
    }
    
    fseek(fp, 0, SEEK_END);
    dword length = (dword)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    fwrite(&length, 4, 1, fc);
    
    for (int i=0; i<length; i+=4)
    {
        dword p;
        fread(&p, 4, 1, fp);
        dword k = genrand_int32();
        dword c = p^k;
        
        fwrite(&c, 4, 1, fc);
        fwrite(&k, 4, 1, fk);
    }
    
    fclose(fp);
    fclose(fc);
    fclose(fk);
}

void decrypt(const char *plain, const char *crypt, const char *key)
{
    FILE *fp = fopen(plain, "wb");
    if (fp==NULL)
    {
        printf("Failed to open %s\n", plain);
        exit(-1);
    }
    FILE *fc = fopen(crypt, "rb");
    if (fc==NULL)
    {
        printf("Failed to open %s\n", crypt);
        exit(-1);
    }
    FILE *fk = fopen(key, "rb");
    if (fk==NULL)
    {
        printf("Failed to open %s\n", key);
        exit(-1);
    }
    
    dword length;
    fread(&length, 4, 1, fc);
    
    for (int i=0; i<length; i+=4)
    {
        dword c;
        fread(&c, 4, 1, fc);
        dword k;
        fread(&k, 4, 1, fk);
        dword p = c^k;
        
        fwrite(&p, min(4,length-i), 1, fp);
    }
    
    fclose(fp);
    fclose(fc);
    fclose(fk);
}
