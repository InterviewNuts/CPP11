/**
 * @file find_odd_even_number_with_xor.cpp
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

bool is_even(int num)
{

    return ((num&1) == 0) ? true:false;
}

void test_even_num()
{
    int arr[]{5,4,1,4,3,5,1,2};

    for (int i =0;i<8;i++)
    {
        if (is_even(arr[i]))
            cout<<arr[i]<<" is a Even number\n"; 
        else
            cout<<arr[i]<<" is a Odd number\n";
    }
}

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
    //test_even_num();
    know_position_of_bit_0_1(9,3);
    return 0;
}