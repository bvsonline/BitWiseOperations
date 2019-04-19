//
//  main.cpp
//  BitWiseOperations
//
//  Created by venkata bethamcharla on 4/18/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>

void CountNumberOfBits(unsigned int x, unsigned int *bits_1, unsigned int *bits_0);
void CountNumberOf1s(unsigned int x, unsigned int *bits_1);

int main()
{
    
    unsigned int bit_1s = 0, bit_0s = 0;

    CountNumberOfBits(123456, &bit_1s, &bit_0s);
    printf("bit_1s: %d, bit_0s: %d \n", bit_1s, bit_0s);
    
    //bit_1s = 0;
    //bit_0s = 0;
    //CountNumberOfBits(568908, &bit_1s, &bit_0s);
    //printf("bit_1s: %d, bit_0s: %d \n", bit_1s, bit_0s);
    
    bit_1s = 0;
    CountNumberOf1s(123456, &bit_1s);
    printf("bit_1s: %d\n", bit_1s);
    
    return 0;
}



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

void CountNumberOf1s(unsigned int x, unsigned int *bits_1)
{
    for (*bits_1=0; x!=0; x&=x-1)
        (*bits_1)++;
    
    return;
}
