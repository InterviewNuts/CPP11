//! This program will tell the bit position  and also set the bit position.
#include<iostream>
using namespace std;


int getBit(int num, int pos)
{
    return (num&(1<<pos)) !=0;
}


int  setBit(int num, int pos)
{
    num=num|(1<<pos);
    return num;
    
}


int main()
{
    cout<<getBit(4,2)<<"\n";
    cout<<setBit(5,1)<<"\n";
}

