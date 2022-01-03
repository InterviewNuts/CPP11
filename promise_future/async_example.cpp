/**
 * @file async_example.cpp
 * @author Haramohan Sahu (hara.sahu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
1) std::async() is a function template that accepts a callback(i.e. function or function object) as an argument 
and potentially executes them asynchronously.

So async() takes function or function object as an argument then asycc() execute that function or function object
and stores the value inside that function or function object.

That is why std::async returns a std::future<T>, that stores the value returned by function object 
executed by std::async().

Where to use STD::ASYNC()?
=========================
Suppose we have to fetch some data (string) from DB and some from files in file-system. 
Then I need to merge both the strings and print.
*/


/*
As both the functions fetchDataFromDB() & fetchDataFromFile() takes 5 seconds each and are running in a 
single thread so, total time consumed will be 10 seconds.

Now as fetching data from DB and file are independent of each other and also time consuming. 
So, we can run them in parallel.
One way to do is create a new thread pass a promise as an argument to thread function and 
fetch data from associated std::future object in calling thread.


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
using namespace std::chrono;
std::string fetchDataFromDB(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like creating DB Connection and fetching Data
    return "DB_" + recvdData;
}
std::string fetchDataFromFile(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like fetching Data File
    return "File_" + recvdData;
}

//!  programm running on sindgle thread, which takes 10 secons. Now we can comment it out
//! create with async(), which eventulay creats a thread and runn it.
/*int main()
{
    // Get Start Time
    system_clock::time_point start = system_clock::now();
    //Fetch Data from DB
    std::string dbData = fetchDataFromDB("Data");
    //Fetch Data from File
    std::string fileData = fetchDataFromFile("Data");
    // Get End Time
    auto end = system_clock::now();
    auto diff = duration_cast < std::chrono::seconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
    //Combine The Data
    std::string data = dbData + " :: " + fileData;
    //Printing the combined Data
    std::cout << "Data = " << data << std::endl;
    return 0;
}
*/

//! with std::asyc()
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
using namespace std::chrono;
using namespace  std;

int main()
{
    //! so here main function is thread one and async() will create an thread , lets considere it as thread2 
    //! now we will start running async () another thread and main thread parallely , so time will be very less,
    //! as compared to the previous example.

    //!  curr time started.
    system_clock::time_point start = system_clock::now();

    //! create an thread by using std::async(), this below stment will create a new thread
    std::future<std::string> resultFromDB = std::async(std::launch::async,fetchDataFromDB,"DB DATA");
    
    //! fetch the File Data from the file from main thread.
    string fileData= fetchDataFromFile(" File Data");

    //! Now we have to collect all the data from DB as well for merging.
    //! This is a blocking call.
    //! Will block till data is available in future<std::string> object. 
    string dbData = resultFromDB.get();


    //!  Now end the Timer.
    system_clock::time_point end=  system_clock::now();

    auto diffTime= duration_cast<chrono::seconds>(end-start).count();
    std::cout << "Total Time Taken(async) = " << diffTime << " Seconds" << std::endl;
    
    //Combine The Data
    std::string data = dbData + " :: " + fileData;
    //Printing the combined Data
    std::cout << "Data = " << data << std::endl;

    return 0;
    }