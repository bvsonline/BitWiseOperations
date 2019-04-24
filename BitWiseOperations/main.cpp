//
//  main.cpp
//  BitWiseOperations
//
//  Created by venkata bethamcharla on 4/18/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//
//  These programs are written
//  after reading C Programming language by Kernighan and Ritchie

#include <stdio.h>

void CountNumberOfBits(unsigned int x, unsigned int *bits_1, unsigned int *bits_0);
void CountNumberOf1s(unsigned int x, unsigned int *bits_1);
bool check_Kth_bitset(unsigned int n, unsigned int k);
unsigned int setKthbit(unsigned int n, unsigned int k);
unsigned int clearKthbit(unsigned int n, unsigned int k);
unsigned int toggleKthbit(unsigned int n, unsigned k);
unsigned int toggleRightmost1Bit(unsigned int n);
unsigned int isolateRightmostBit(unsigned int n);
unsigned int isolateRightmost0Bit(unsigned int n);
bool isNumberPowerOf2(unsigned int n);
unsigned int reverseBinaryNumber(unsigned int n);
unsigned int count1sbylut(unsigned int n);
unsigned int swapOddandEvenBits(unsigned int n);

#define dprint(x)   printf(#x": %d \n",x)

int main()
{
    
    unsigned int bit_1s = 0, bit_0s = 0;

    CountNumberOfBits(123456, &bit_1s, &bit_0s);
    printf("bit_1s: %d, bit_0s: %d \n", bit_1s, bit_0s);
    
    bit_1s = 0;
    bit_0s = 0;
    CountNumberOfBits(568908, &bit_1s, &bit_0s);
    printf("bit_1s: %d, bit_0s: %d \n", bit_1s, bit_0s);
    
    bit_1s = 0;
    CountNumberOf1s(123456, &bit_1s);
    printf("bit_1s: %d\n", bit_1s);
    
    unsigned int result = swapOddandEvenBits(2500);
    dprint(result);
    
    return 0;
}

//  Count number of 1s in given number
void CountNumberOfBits(unsigned int x, unsigned int *bits_1, unsigned int *bits_0)
{
   while (x)
   {
       if (x & 1)
           (*bits_1)++;
       else
           (*bits_0)++;
       
       x >>= 1;
   }

    return;
}

//  Faster version Count number of 1s in given number
void CountNumberOf1s(unsigned int x, unsigned int *bits_1)
{
    for (*bits_1=0; x!=0; x&=x-1)
        (*bits_1)++;
    
    return;
}

// Check if kth bit is set or not in given number
// k can be 0..31
bool check_Kth_bitset(unsigned int n, unsigned int k)
{
    return (n & (1 << k)) ? true : false;
}

// set kth bit in given number
// k can be 0..31
unsigned int setKthbit(unsigned int n, unsigned int k)
{
    return n | (1 << k);
}

// clear kth bit in given number
// k can be 0..31
unsigned int clearKthbit(unsigned int n, unsigned int k)
{
    return (n | ~(1 << k));
}

// toggling k-th bit
// k can be 0..31
unsigned int toggleKthbit(unsigned int n, unsigned k)
{
    return n ^ (1 << k);
}

// toggling right most 1 bit
unsigned int toggleRightmost1Bit(unsigned int n)
{
    return n & (n-1);
}

// isolate right most bit
unsigned int isolateRightmostBit(unsigned int n)
{
    return n & (-n);
}

// isolate right most zero bit
unsigned int isolateRightmost0Bit(unsigned int n)
{
    return ~n & (n+1);
}

// check whether the number is power of 2 or not
bool isNumberPowerOf2(unsigned int n)
{
    return ((n & (n-1)) == 0) ? true : false;
}

// reverse the binary number
unsigned int reverseBinaryNumber(unsigned int n)
{
    unsigned int reverse_number = 0;
    while (n != 0)
    {
        reverse_number |= (n & 1);
        n >>= 1;
        reverse_number <<= 1;
    }
    
    return reverse_number;
}

unsigned int LUT[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
// Count number of 1's using look up table
unsigned int count1sbylut(unsigned int n)
{
    unsigned int num_1s = 0;
    while (n)
    {
        num_1s += LUT[n&15];
        n >>= 4;
    }
    return num_1s;
}

// Swap even and odd bits in given integer
unsigned int swapOddandEvenBits(unsigned int n)
{
    return ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
}

