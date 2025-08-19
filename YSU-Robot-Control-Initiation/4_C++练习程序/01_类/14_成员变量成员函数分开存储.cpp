#include<iostream>
using namespace std;
#include<string>

//成员变量和成员函数分开存储

class Person
{

    int m_Age; //非静态成员变量，属于类的对象上

    static int m_Salary; //静态成员变量，属于类本身,不属于类的对象上

    void func() {} //非静态成员函数，不属于类的对象上

    static void func2() {} //静态成员函数，属于类本身,不属于类的对象上

};

int Person::m_Salary = 10000; //静态成员变量定义并初始化

void test01()
{
    Person p;
    cout << "sizeof(Person) = " << sizeof(p) << endl; //空对象大小为1字节，为了区分空对象占内存的位置
    //每个空对象也都有独一无二的内存地址
}

void test02()
{
    Person p;
    cout << "sizeof(Person) = " << sizeof(p) << endl; //非空对象大小为4字节，为了区分空对象占内存的位置
}

int main()
{

    test02();
    return 0;
}

//总结：
//1。类内成员变量和成员函数分开存储
//2.只有非静态成员变量属于类的对象上