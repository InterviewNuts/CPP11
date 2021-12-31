#include<iostream>
using namespace std;
/*

	1 0 0
&	0 0 1
==============
	0 0 0

*/

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

int main()
{
    test_even_num();
    return 0;
}