#include<iostream>
#include<sstream>

using namespace std;

/**
 * istringstream:进行流的输入
 * 用途：istringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来。
 */

// 输入：i am a boy!
// 输出：
// i
// am
// a
// boy!

int main(int argc, char const *argv[])
{
    string str, line;
    cout<<"please input some string:";
    while(getline(cin, line))
    {
        istringstream stream(line);
        cout<<"out:"<<endl;
        while(stream>>str)
            cout<<str.c_str()<<endl;
        break;
    }
    return 0;
}
