/**
 * @file find_ith_pos_0_1.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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