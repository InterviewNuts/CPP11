#include<iostream>
#include<string>
using namespace std;
/*

	1 0 0
&	0 0 1
==============
	0 0 0

*/

bool is_odd(int num)
{

    return ((num&1) == 1) ? true:false;
}

bool is_even(int num)
{

    return ((num&1) == 0) ? true:false;
}

int get_unique_number_from_array(int arr[])
{
     
     int res=0;
     for (int i =0; i<8;i++)
        {
            res=(res^arr[i]);
           
        }
    return res;
}

void  get_first_unique_number_from_array(int arr[],int res)
{

    int first=0,second=0,temp=res;
     for (int i =0; i<8;i++)
     {
         if (is_odd(arr[i]))
            res=(res^arr[i]);
     }
     first=res;   
     cout<<" First unique = "<<first<<endl;
     second=first^temp;
     cout<<" Second unique = "<<second<<endl;
}
int main()
{
    int arr[]{5,4,1,4,3,5,1,2};
    //! with this we will get 3^2 ( that is 1) , this is as unique 2 num, but we will get as xor of 3^2 not the number
    int res=get_unique_number_from_array(arr);
    //! here try to get those numbers from the array, which are ending with 1 that is whose 0th element is 1
    //! so I used the logic of odd numbers , which are ending with 1
    //! the I have xored these odd numbers from the arra with res that (3^2) that is 1;
    //! (3^2)^(5,1,3,5,1)--> 2, we will get 2 as  5 3,1 will be canceld out.
    //!  now I got 2 which is of the Unique  number, now I have to get another one , so I need to xor 2 with res ( 3^2)
    //! 2^3^2, 2 will be canceled out and 3 remains, which is the second answer.
    get_first_unique_number_from_array(arr, res);



    return 0;
}