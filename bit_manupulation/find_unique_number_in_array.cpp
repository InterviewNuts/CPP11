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
     int arr[]{5,4,1,1,4,3,5,3,8};
     int res=0,sz;


     sz=sizeof(arr)/sizeof(arr[0]);
     int arrSize = *(&arr + 1) - arr;
     for (int i =0; i<sz;i++)
        {
            res=(res^arr[i]);
            //cout<<res<<endl;
        }
    return res;
}

int main()
{   
    int t= get_unique_number_from_array();
    if (t!=0)
        cout<<" Unique Num = "<<t<<"\n";
    else
        cout<<" there is no unique no\n";
    //get_unique_number_from_array();
    return 0;
}