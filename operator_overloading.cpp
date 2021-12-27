#include<iostream>
using namespace std;

class MyInt
{
    private:
    int*ptr;
    public:
    explicit MyInt(int*p=nullptr):ptr(p){}
    int& operator*()
    {
        return *ptr;
    }

};


int main()
{
    int *p = new int[10];
    *p=900;
    MyInt myintObj(p);
    cout<<"myintObj = "<<*myintObj<<endl;

}
