#include<iostream>
#include<sstream>
using namespace std;

/**
 * ostringstream:流的输出
 * 用途：值转换;组合
 */

template<class T>
void to_string(string & result,const T& t)
{
    ostringstream oss;//创建一个流
    oss<<t;//把值传递如流中
    result = oss.str();//获取转换后的字符转并将其写入result
}

template<class T>
string to_String2(const T& t)
{
    ostringstream oss;//创建一个流
    oss<<t;//把值传递如流中
    return oss.str();
}


int main(int argc, char const *argv[])
{
    string s1,s2,s3;
    to_string(s1,10.5);//double到string

    to_string(s2,123);//int到string

    to_string(s3,true);//bool到string
    cout<<"s1 ="<<s1<<" s2 = "<<s2<<" s3 ="<<s3<<endl;

    string t1,t2,t3;
    // t1 = to_String2<double>(10.5);
    // t2 = to_String2<int>(123);
    // t3 = to_String2<bool>(true);
    //也可以不加<T>
    t1 = to_String2(10.5);
    t2 = to_String2(123);
    t3 = to_String2(true);

    cout<<"t1 ="<<t1<<" t2 = "<<t2<<" t3 ="<<t3<<endl;


    return 0;
}
