// you want a base class for inheritance/polymorphism but don't want the base class to be
// instantiateable.

// That way, giving it a pure virtual function makes it an abstract class.
//  However, you must implement that destructor somewhere, as the compiler will call it when a
//  derived class’ destructor is called.

class Base
{
public:
    // void do()
    // {
    // }
    virtual ~Base() = 0;
};
