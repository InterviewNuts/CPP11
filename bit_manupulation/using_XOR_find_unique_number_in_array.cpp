#include<iostream>
using namespace std;
/*

	1 0 0
&	0 0 1
==============
	0 0 0

*/




int get_unique_number_from_array()
{
     int arr[]{5,4,1,4,3,5,1};
     int res=0;
     for (int i =0; i<8;i++)
        {
            res=(res^arr[i]);
            //cout<<res<<endl;
        }
    return res;
}

int main()
{
    cout<<" Unique Num = "<<get_unique_number_from_array()<<"\n";
    //get_unique_number_from_array();
    return 0;
}