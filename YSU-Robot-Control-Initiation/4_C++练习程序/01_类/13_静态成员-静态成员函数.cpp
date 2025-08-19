#include<iostream>
using namespace std;
#include<string>

//静态成员函数
//1.所有对象共享同一份函数
//2.静态成员函数只能访问静态成员变量

class Person
{
    public:

    //静态成员函数
    static void func()
    {
        m_Salary = 20000; //静态成员函数可以访问静态成员变量
        //m_Age = 20; //错误，静态成员函数不能访问非静态成员变量，无法区分到底是哪个对象的m_Age属性
        cout << "静态成员函数func" << endl;
    }
    static int m_Salary; //静态成员变量
    int m_Age; //非静态成员变量

    private:

    //静态成员函数也有访问权限
    static void func2()
    {
        cout<< "私有静态成员函数func2" << endl;
    } //私有静态成员函数


};
int Person::m_Salary = 10000; //静态成员变量定义并初始化


void test01()
{
    //静态函数变量有两种访问方式

    //1.通过类名访问静态成员函数
    Person::func(); 
    //Person::func2(); //类外访问不到私有静态成员函数

    //2.通过对象访问静态成员函数
    Person p;
    p.func(); 

}
int main()
{

    test01();
    return 0;
}
