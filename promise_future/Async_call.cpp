// std::async can be seen as a high level interface to std::threads.Let’s see a simplified example of async usage :

#include <future>
#include <iostream>

void called_from_async()
{
    std::cout << "Async call" << std::endl;
}

int main()
{
    // called_from_async launched in a separate thread if possible
    std::future<void> result(std::async(called_from_async));

    std::cout << "Message from main." << std::endl;

    // ensure that called_from_async is launched synchronously
    // if it wasn't already launched
    result.get();

    return 0;
}