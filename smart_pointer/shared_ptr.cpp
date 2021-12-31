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
    ~Dog()
    {
        cout << " Dog Dotr called \n";
    }

    void DogName()
    {
        cout << " Dog Name = " << name << "\n";
    }

};


int main()
{
    Dog dd;
    shared_ptr<Dog>p(new Dog("puppy"));
    p->DogName();
    std::cout << sizeof(dd) << " :\n  ";
    std::cout << sizeof(p) <<" :  "<< sizeof(*p) << endl;

    return 0;
}