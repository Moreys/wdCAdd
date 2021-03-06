/*************************************************************************
  @FileName:  ./2_stringTest.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 11:54:11 AM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//string 的初始化
void test1()
{
    string str1 = "aaaaa";
    string str2("bbbbb");
    string str3 = str2;//通过拷贝构造函数  来初始化对象str3
    string str4(10, 'a');

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;

}

//string的遍历
void test2()
{
    string str1 = "abcdefghijl";
    
    //1 数组的方式
    for(int idx = 0; idx < str1.length(); ++idx)
    {
        cout << str1[idx] << " ";
    }
    cout << endl;

    //2 迭代器
    for(string::iterator it = str1.begin(); it != str1.end(); ++it)
    {
        cout << *it << " " ;
    }

    // () 和 [] 的区别
    try
    {
        for(int idx = 0; idx < str1.length() + 3; ++idx)
        {
            cout << str1.at(idx) << " ";   // 抛出异常
        }
    }
    catch(...)
    {
        cout << "发生异常" << endl;
    }
    cout << "at 之后" << endl;
    //try
    //{
    //    for(int idx = 0; idx < str1.length() + 3; ++idx)
    //    {
    //        cout << str1[idx] << " ";   // 出现错误不会向外面抛出异常
    //    }
    //}
    //catch(...)
    //{
    //    cout << "发生异常" << endl;
    //}

}

//字符指针和string的转换
void test3()
{
    string str1 = "aaaabbb";
}

//字符串的连接
void test4()
{
    string s1 = "aaa";
    string s2 = "bbb";
    s1 = s1 + s2;
    cout << "s1: " << s1 << endl;

    string s3 = "3333";
    string s4 = "4444";
    s3.append(s4);
    cout << "s3: " << s3 << endl;
}

//查找和替换
void test5()
{
    string str1 = "wbm hello wbm 111 wbm 222 wbm 333";
    //找到wbm出现 的位置’
    
    int index = str1.find("wbm", 0);//位置的下标  从0 开始  //查找一次
    cout << "index = " << index << endl;

    //案例1 求wbm出现的次数 每一次出现的数组下标
    auto offindex = str1.find("wbm", 0);
    while(offindex != string::npos) //字符串的末尾
    {
        cout << "offindex = " << offindex << endl;
        offindex = offindex + 1;
        offindex = str1.find("wbm", offindex);
    }

    //案例2 把wbm改写为 WBM
    
    string str2 = "aa bb cc";
    //replace 只包含字母，不处理空格
    str2.replace(0, 2, "AA");//参数1:替换的起始位置; 参数2：替换的字串长度；参数3：要替换的字串
    str2.replace(3, 3, "AA");
    cout << "str2 = " << str2 << endl;
    offindex = str1.find("wbm", 0);
    while(offindex != string::npos) //字符串的末尾
    {
        cout << "offindex = " << offindex << endl;
        str1.replace(offindex, 3, "WBM");
        offindex = offindex + 1;
        offindex = str1.find("wbm", offindex);
    }
    cout << "str1替换后的效果：" << str1 << endl;
}

//截断（区间删除)和插入
void test6()
{
    string str1 = "hello1 hello whllo1";
    string::iterator it = find(str1.begin(), str1.end(), '2'); //查找1 出现的第一个位置
    if(it != str1.end())//删除找到的对象，如果没有找到那就不进行删除
    {
        str1.erase(it);
    }
    cout << "str1删除1以后的结果：" << str1 << endl;

    str1.erase(str1.begin(), str1.end());
    cout << "str1全部删除" << str1 << endl;
    cout << "str1删除完以后的长度" << str1.length() << endl; 

    string str2 = "BBB";
    str2.insert(0, "AAA");//从 0 的位置开始插入
    str2.insert(str2.length(), "CCC"); //末尾插入

    cout << "str2 = " << str2 << endl;

}

void test7()
{
    string s1 = "AAAbbb";
    //1 函数入口地址  2 函数对象  3 预定义的函数对象
    //transform(s1.begin(), s1.end(), s1.begin(), toupper);
    cout << "s1 = " << s1 << endl;
}
int main()
{
    //test1();
    //test2();
    //test4();
    //test5();
    test6();
    std::cout << "Hello world" << std::endl;
    return 0;
}

