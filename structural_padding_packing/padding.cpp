/**
 * @file padding.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
Structure Padding:
-------------------
The processor does not read 1 byte at a time. It reads 1 word at a time depending on the architecture ( 32 or 64).

What does the 1 word mean?

If we have a 32-bit processor, then the processor reads 4 bytes at a time, which means that 1 word is 
equal to 4 bytes.
1 word = 4 bytes  
If we have a 64-bit processor, then the processor reads 8 bytes at a time, which means that 
1 word is equal to 8 bytes.
1 word = 8 bytes 

example:
structure A
{
    char c;
    int a;
};
_______________
C|-|-|-|a|a|a|a|
_______________

so here , it reads 4 bytes to read  char c and  and to read int a , it has to read next 4 bytes .
assume that padding was not there, then  (C|a|a|a|a|), it will two cycle to read int a. So it is a optimisation.

*/
#include<iostream>

using namespace std;
//#pragma pack(1) 
int main()
{
    struct padding
    {
       int a;
       char c;
    }pd;
    cout<< sizeof(pd)<<endl;
    return 0;
}

// Here the size would be 8 as it would padd number of bytes depending the highest data type present in the 
//! structure. so int = 4 , 1 bye is char , 3 more bytes are padded.

//! if use pragma pack(1), then it will show 5 .