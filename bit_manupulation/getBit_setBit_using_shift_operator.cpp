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

void clearBit(int num, int pos)
{
    cout<<" The original number = "<<num<<"\n";
    cout<<" 0 1 0 1 ( after clear the 3rd bit \n";
    cout<<" 0 0 0 1 (so the value will turned to be 1) \n";

    num=num&(~(1<<pos));

    cout<<" The original number afetr bit cleared  = "<<num<<"\n";

}

void updateBit(int num, int pos)
{
    cout<<" The original number = "<<num<<"\n";
    cout<<" 0 1 0 1 ( after clear the 2nd bit \n";
    cout<<" 0 1 1 1 (so the value will turned to be 1) \n";

    int mask=~(1<<pos);
    num=num&(mask);
    num=num|(1<<pos);

    cout<<" The original number afetr bit cleared  = "<<num<<"\n";
}

void updateBitWithUserGivenValue(int num, int pos,int value)
{
    cout<<" The original number = "<<num<<"\n";
    cout<<" 0 1 0 1 ( after clear the 2nd bit \n";
    cout<<" 0 1 1 1 (so the value will turned to be 1) \n";

    int mask=~(1<<pos);
    cout<<" Mask = "<<mask<<"\n";
    num=num&(mask);
    cout<<" num = "<<num<<"\n";
    cout<<" value = "<<value<<pos<<"\n";
    num=num|(value<<pos);
    cout<<" num2 = "<<num<<"\n";
    cout<<" The original number afetr bit updated  = "<<num<<"\n";
}





int main()
{
    cout<<getBit(4,2)<<"\n";
    cout<<setBit(5,1)<<"\n";

    clearBit(5,2);
    updateBit(5,1);
    updateBitWithUserGivenValue(4,2,0);
}

