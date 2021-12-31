// cpp11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<memory>
#include<string>
#include<iostream>
using namespace std;


class Dog
{
private:
    string name = "Tommy";
public:
    Dog() = default;
    Dog(string n) :name(n) {
        cout << "Dog Cort called \n";
    }


    void DogName()
    {
        cout << " Dog Name = " << name << "\n";
    }

    ~Dog()
    {
        cout << " Dog Dotr called \n";
    }
};

/*
1) A shared_ptr wraps a reference counting mechanism around a raw pointer. So for each instance of the shared_ptr the reference count is increased by one. 
2) If two share_ptr objects refer the eachother they will never get deleted because they will never end up with a reference count of zero.
3) weak_ptr points to a shared_ptr but does not increase its reference count.
4) This means that the underying object can still be deleted even though there is a weak_ptr reference to it.

5) The way that this works is that the weak_ptr can be use to create a shared_ptr for whenever one wants to use the underlying object.
6) If however the object has already been deleted then an empty instance of a shared_ptr is returned. Since the reference count on the underlying object 
is not increased with a weak_ptr reference, a circular reference will not result in the underlying object not being deleted.

7) Weak pointers just "observe" the managed object; they don't "keep it alive" or affect its lifetime. 
8) Unlike shared_ptr, when the last weak_ptr goes out of scope or disappears, the pointed-to object can still exist, 
because the weak_ptr does not affect the lifetime of the object - it has no ownership rights. 
10) The weak_ptr can be used to determine whether the object exists, and to provide a shared_ptr that can be used to refer to it.
11) The definition of weak_ptr is designed to make it relatively fool proof, so as a result there is very little you can do directly with a weak_ptr. 

For example, you can't dereference it; neither operator* nor operator-> is defined for a weak_ptr. 
You can't access the pointer to the object with it - there is no get() function. 
There is a comparison function defined so that you can store weak_ptrs in an ordered container, but that's all.


*/

int main()
{
    
    shared_ptr<Dog>p(new Dog("puppy"));
    cout << " shared ptr count = " << p.use_count() << endl;
    weak_ptr<Dog>wp=p;
    cout << " Weak ptr count = " << p.use_count() << endl;

    
    std::cout << sizeof(wp) <<" :  "<< sizeof(p) << endl;

    return 0;
}