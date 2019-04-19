//
//  main.cpp
//  BitWiseOperations
//
//  Created by venkata bethamcharla on 4/18/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>

void CountNumberOfBits(unsigned int x, unsigned int *bits_1, unsigned int *bits_0);

int main()
{
    
    
    
    return 0;
}



void CountNumberOfBits(unsigned int x, unsigned int *bits_1, unsigned int *bits_0)
{
   while (x)
   {
       if (x & 1)
           bits_1++;
       else
           bits_0++;
       
       x >>= 1;
   }

    return;
}
