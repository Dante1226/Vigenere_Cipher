//
//  main.c
//  Vigenere Cipher
//
//  Created by Steven Vargas on 5/15/15.
//  Copyright (c) 2015 Steven Vargas. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

enum flag{encrypted = 1, decrypted = 0};

void encrytion ( char* to_encrypt,char*key);

void decyption (char*to_encrypt,char*key);

void vigenere(char* to_encrypt, char* key, enum flag f ){
    
    int i;
    long k,s;
    char *si;
    k = strlen(key);
    s = strlen(to_encrypt);
    
    
    for (i = 0; i < s; i++)
    {
        if (!isupper(si[i])) continue;
        s = 'A' + ( f
                   ? si[i] - 'A' + key[i % k] - 'A'
                   : si[i] - key[i % k] + 26) % 26;
    }
    if (f==1){
        printf(" The Document was decryted using state of the art technology %s\n", si);
        decyption(si, key); }
    else
    { printf(" The Document was encrypted %s\n", si);}
    
    
    
};

void decyption (char*to_encrypt,char*key){
    
    vigenere(to_encrypt,key,decrypted);
    
};

void encrytion ( char* to_encrypt,char*key){
    
    vigenere(to_encrypt,key,encrypted);
    
    
};

void Padded ( char* to_encryted, int i, int k ){
    
    
    while ( i % k  !=0 )
    {
        
        
        strcat( to_encryted, "A" );
        
        i++;
        
    }
    
    printf(" The Documnet was padded. %s\n", to_encryted);
    
    
};

int main(){
    
    int c, m, k;
    char *n, *e;
    
    
    char to_encryted[50] =  " a" ;
    char key[20] = " CATALEPSY " ;
    char temp[20];
    
    k = strlen(to_encryted);
    c = strlen(key);
    m = c % k;
    
    if (m !=0)
    {
        Padded(to_encryted,k,c);
        
        printf(" padded output: %s\n", to_encryted);
        
    }
    
    
    n = strncpy(temp, to_encryted, 20);
    
    encrytion(n, key);
    
    
    
    
    
    return 0;
    
};