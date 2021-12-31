#include<iostream>
#include<memory>
#include<vector>
#include <algorithm>
#include<functional>




using namespace std;

/*
Constructor — can be default or templated.
constexpr default_delete() noexcept = default; // default
template <class U>
default_delete( const default_delete<U>& d ) noexcept; // templated
// Constructs a std::default_delete object from another.
// Overload resolution if U* is implicitly convertible to T*.

Example 1:
{
    std::unique_ptr<int> ptr(new int(5));
}   
// unique_ptr<int> uses default_delete<int>
====================================================================
Example 2:
{
   std::unique_ptr<int[]> ptr(new int[10]);
}  
// unique_ptr<int[]> uses default_delete<int[]>


When you use a custom deleter it won’t affect the size of your shared_ptr type. 
If you remember, shared_ptr size should be roughly 2 x sizeof(ptr) so where does this deleter hide?
As we know, shared_ptr consists of two things: pointer to the object and pointer to the control block
(that contains ref count). Inside the control block structure of shared_ptr,
there is a space for custom deleter and allocator.

The size of weak_ptr is the same as that of shared_ptr. Weak pointer points to the same control block as it’s 
shared pointer. When a weak_ptr is created, destroyed, or copied a second reference count 
(weak pointer reference count) is manipulated. Weak count is connected with object storage deallocation



we can not use custome deleter with make_shared() or make_unique();

*/

void f()
{

// default_delete can be used anywhere a delete functor is needed
std::vector<int*> v;
for(int n = 0; n < 100; ++n)
   v.push_back(new int(n));
std::for_each(v.begin(), v.end(), std::default_delete<int>());
// Constructing the function object to be called

    //std::unique_ptr<int[]> ptr(new int[10]);
    std::shared_ptr<int> ptr(new int[10]);

    std::shared_ptr<int> shared_bad(new int[10],default_delete<int[]>()); 

}

//Ways to specify custom deleters

//Using custom deleter with shared_ptr
//! 1 Use a proper functor,  declare the function object

template<typename T>
class array_deleter
{
public:
   void operator ()(T const *p)
   {
       delete []p;
       cout<<" Operator DELETE is called for (array_deleter class )\n";
   }
};

void function_object_deleter()
{
    // and use shared_ptr as follows by constructing function object
    std::shared_ptr<int> sp(new int[10], array_deleter<int>());
}

//! 2. Use a plain lambda

class Dog
{
public:
Dog()
{
    cout<<" DOG COTR Called\n";
}
~Dog()
{
    cout<<" DOG Dotr called \n";
}
/*
void operator()(Dog*p)
{
    cout<<" Custome deleter with Unique pointer called inside Dog \n";
    delete p;
}*/
};


void lambada_deleter()
{
    // and use shared_ptr as follows by constructing function object
    std::shared_ptr<Dog> sp(new Dog[10], [](Dog*p) {cout<<" Dog lambda deleter called \n"; delete []p;});
}

//Using custom deleter with unique_ptr




void deleter(Dog* p) {
    cout<<" Custome deleter with Unique pointer called\n";
    delete p;
}


void deleter_array(Dog* p) {
    cout<<" Custome deleter array  with Unique pointer called\n";
    delete []p;
}

void custome_deleter_with_unique_ptr()
{
    // 1. std::function 
    //std::unique_ptr<Dog, std::function<void (Dog*)>> u1(new Dog(),[](Dog* b){ deleter(b);});

    //! std: bind example
    //std::unique_ptr<Dog, std::function<void(Dog*)>> bar(new Dog(), std::bind(&deleter,std::placeholders::_1));



    unique_ptr<Dog,std::function<void (Dog*p)>>dg(new Dog[2],[](Dog*p){deleter_array(p);});
}



int main()
{
    
    //function_object_deleter();
    //lambada_deleter();

    custome_deleter_with_unique_ptr();

    return 0;
}