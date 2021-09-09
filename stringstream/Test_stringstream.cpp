#include<iostream>
#include<sstream>
using namespace std;

/**
 * stringstream:流的输入/出
 * 用途：1.值转换,配合模板使用   2.组合
 * ps: <sstream>使用string对象来代替字符数组。这样可以避免缓冲区溢出的危险。
 * 而且，传入参数和目标对象的类型被自动推导出来，即使使用了不正确的格式化符也没有危险。
 */

template<class out_type,class in_type>
out_type convertType(const in_type & t)
{
    stringstream stream;
    stream<<t;//向流中传值
    out_type result;//这里存储转换结果
    stream>>result;//向result中写入值
    return result;
}


//如果你打算在多次转换中使用同一个stringstream对象，记住再每次转换前要使用clear()方法；
//在多次转换中重复使用同一个stringstream（而不是每次都创建一个新的对象）对象最大的好处在于效率。
//stringstream对象的构造和析构函数通常是非常耗费CPU时间的。
void test()
{
    stringstream ss;
    string str;
    for(int i =0; i< 10;i ++)
    {
        //int ==>> string
        ss << "index" <<i;
        ss >> str;
        cout<<"i = "<<str<<endl;
        ss.clear();
    }
}



int main(int argc, char const *argv[])
{
    string str;
    int t = 520;
    //int ==>> string
    str = convertType<string, int>(t);

    cout<<"str = "<<str<<endl;

    //string ==>>int
    str = "520";
    t = 0;

    t = convertType<int, string>(str);
    cout<<"t = "<<t<<endl;


    //string == >>int
    str = "i am a boy!!";
    t = 0;
    t = convertType<int, string>(str);
    cout<<"t = "<<t<<endl;

    //clear
    test();


    //组合：int + string +double +bool + int + string + ...
    stringstream ss;
    ss << 520 << "like " << 5.20 << true << 520 << "end!!";
    string str2;
    ss >> str2;//会以空格符分割
    cout<<"str2 = "<<str2<<endl;//str2 = 520like
    cout<<"ss.str() = "<<ss.str()<<endl;//ss.str() = 520like 5.21520end!!
    return 0;
}
