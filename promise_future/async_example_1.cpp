/**
 * @file async_example_1.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
std::async() does following things:
-----------------------------------
1) It automatically creates a thread (Or picks from internal thread pool) and a promise object for us.
2)Then passes the std::promise object to thread function and returns the associated std::future object.
3) when our passed argument function exits then its value will be set in this promise object, 
so eventually return value will be available in std::future object.

*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
using namespace std;

int find_sumOf_oddNum_from_given_range(int range)
{
int oddSum=0;
	for (int i=0;i<range;i++)
	{
		if (i&1)
			oddSum+=i;
	}
return oddSum;

}


int main()
{

cout<<" Thread created if policy is async\n";
std::future<int> oddSumFut = std::async(std::launch::async,find_sumOf_oddNum_from_given_range,100);


cout<<" Wait for the result\n";

cout<<oddSumFut.get()<<endl;

return 0;
}







