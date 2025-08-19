#include<iostream>
using namespace std;

//构造函数调用规则

// 1.创建一个类，C++编译器会给每个类添加至少三个函数
//    默认构造函数(空实现)
//    拷贝构造函数(空实现)
//    析构函数（值拷贝）


//2.如果写了有参构造函数，编译器不提供无参构造函数，但依然提供拷贝构造
//如果写了拷贝构造函数，编译器不提供默认构造函数和有参构造函数

class Person
{
    public:

    // Person()//默认构造函数
    // {
    //     cout << "Person默认构造函数" << endl;
    // }

    //     Person(int age)//有参构造函数
    // {
    //     m_Age = age; 
    //     cout << "Person有参构造函数" << endl;
    // }

    Person(const Person &p)//拷贝构造函数
    {
       m_Age = p.m_Age;
        //拷贝构造函数的参数是一个常量引用，防止在拷贝过程中被修改
        //因为在拷贝构造函数中可能会调用其他成员函数，如果参数是非const引用，则可能会导致死循环调用拷贝构造函数
       cout << "Person拷贝构造函数" << endl;
    }


    ~Person()//析构函数
    {
        cout << "Person析构函数" << endl;
    }


    int m_Age;
};


// void test01()
// {
//     Person p;//调用默认构造函数
//     p.m_Age = 20;//设置年龄

//     Person p2(p);//调用拷贝构造函数
//     cout << "p2的年龄：" << p2.m_Age << endl;

//     //因为在调用拷贝构造函数时，p2是一个局部变量，生命周期结束后会调用析构函数
//     //p2的生命周期结束后，调用析构函数
// }

void test02()
{

    //Person p;//调用有参构造函数p   
    // Person p2(p);//调用拷贝构造函数p2
    // cout << "p2的年龄：" << p2.m_Age << endl; 
}


int main()
{
    
    // test01();

    //若有拷贝构造函数输出：
    //Person默认构造函数
    //Person拷贝构造函数
    //p2的年龄：20
    //Person析构函数
    //Person析构函数

    //(若无拷贝构造函数，则调用默认拷贝构造函数)
    //输出：
    //Person默认构造函数    
    //p2的年龄：20
    //Person析构函数
    //Person析构函数

    test02();



    return 0;
}