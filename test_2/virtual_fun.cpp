#include<iostream>
using namespace std;

class A
{
public:

    //普通虚函数
    virtual int fun1();//如果子类没有实现，默认调用基类的实现
    virtual int fun2() { return 0; } //子类没有实现时默认返回0

    //纯虚函数
    virtual int fun3() = 0;   //基类不必实现，子类必现重写
};

int A::fun1()
{
    return -1;
}

class B :public A
{
private:
    /* data */
public:

    // virtual int fun1();
    // virtual int fun2();
    virtual int fun3();
};

// int B::fun1()
// {
//     return 1;
// }

// int B::fun2()
// {
//     return 2;
// }

int B::fun3()
{
    return 3;
}

/*
*
*
*/

int main(int argc, char const *argv[])
{
    /* code */
    B b;

    cout<<"fun1:"<<b.fun1() <<"  fun2:"<<b.fun2()<<"  fun3:"<<b.fun3()<<endl;
    return 0;
}
