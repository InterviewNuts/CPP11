#include<iostream>
using namespace std;

void know_position_of_bit_0_1(int num,int pos)
{

    int r=1<<pos;
    cout<<r<<"\n";
    if (  ((num)&(1<<pos)) == 0)
    {
        cout<< " Bit is 0 \n";
    }
    
    else 
    {
        cout<< " Bit is 1 \n";          
    }
    
}
int main()
{
    know_position_of_bit_0_1(9,3);
    return 0;
}