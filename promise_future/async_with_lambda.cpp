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

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>

using namespace std::chrono;
using namespace std;



std::string fetchDataFromFile(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like fetching Data File
    return "File_" + recvdData;
}

int main()
{
    system_clock::time_point start = system_clock::now();

    std::future<string> resFromDB= std::async(std::launch::deferred,
    [](string recvdData)
    {
      std::this_thread::sleep_for(seconds(5));
      return "DB_" + recvdData; 

    }," Data From DB");

     //! fetch the File Data from the file from main thread.
    string fileData= fetchDataFromFile(" File Data");

    system_clock::time_point end= system_clock::now();
    //! Now we have to collect all the data from DB as well for merging.
    //! This is a blocking call.
    //! Will block till data is available in future<std::string> object. 
    string dbData = resFromDB.get();

    auto diff = duration_cast<chrono::seconds>(end-start).count();
    std::cout << "Total Time Taken ( Lmbda Funtion) = " << diff << " Seconds" << std::endl;

    //Combine The Data
    std::string data = dbData + " :: " + fileData;
    //Printing the combined Data
    std::cout << "Data = " << data << std::endl;

    return 0;
}