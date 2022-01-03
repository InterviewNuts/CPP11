/**
 * @file Mother_son_with_laundry_with_condition_var.cpp
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

#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

enum class Laundry{CLEAN,DIRTY};
std::mutex MUT;
Laundry SONS_LAUNDRY= Laundry::CLEAN;
std::condition_variable cv;

bool is_laundry_clean()
{
    return SONS_LAUNDRY == Laundry::CLEAN;
}

bool is_laundry_dirty()
{
    return SONS_LAUNDRY == Laundry::DIRTY;
} 

void clean_laundry()
{
    /*1) We need to aquire lock to clean the laundry
      2) Once we aquired the lock,  we nee dto clean it, But before we do clean , 
      we need to we need to check , 
      3) whether it is dirty or not. 
      4) If dirty , then process further
      5) If not, then we have to release the lock & put the thread in to wait ( block it) 
    */


   std::unique_lock<mutex> lock(MUT);
   cv.wait(lock,is_laundry_dirty);
   /*
    There are two possibilities:
    1) If the condition is satisfied – the laundry is dirty – wait() returns and the program continues.
    
    2) If the condition is not satisfied – the laundry is clean – wait() unlocks the mutex and 
    puts the thread in a waiting state. 
    The thread stops waiting when a notify_one() member function of the condition variable is called. 
    When the thread stops waiting, it reacquires the lock of the mutex and checks the condition again, 
    by calling is_laundry_dirty(). 
    The wait() returns only if is_laundry_dirty() returns true, 
    otherwise wait() starts waiting again.

   */


    std::cout << "Doing the son's laundry." << std::endl;
    SONS_LAUNDRY = Laundry::CLEAN;
    lock.unlock();
    cv.notify_one();
}

void play_around()
{
    //! now let the Boy play and then make the laundry dirty.
    cout<<"SON Playing Foot ball and sweating....\n";
    {
        //! Now make the it dirty.
        std::lock_guard<mutex> guard(MUT);
        SONS_LAUNDRY=Laundry::DIRTY;
    }
    //! since I have dome my dress dirty, I need to informe my Mother that I have made my dress dirty
    //! by notift_one() her.
    cout<<" Calling mother & requesting for Laundry\n";
    cv.notify_one();

    //! Since I have requested her to clean, I need to wait for her.
    //! waiting
    {
        std::unique_lock<mutex> lock(MUT);
        cv.wait(lock,is_laundry_clean);
    }
std::cout << "Yea, I have a clean laundry! Thank you mum!" << std::endl;
}

int main()
{
    thread mother (clean_laundry);
    thread son(play_around);
    mother.join();
    son.join();

    return 0;
}