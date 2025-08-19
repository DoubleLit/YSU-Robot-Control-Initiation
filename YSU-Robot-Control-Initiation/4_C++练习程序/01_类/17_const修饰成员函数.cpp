#include<iostream>
using namespace std;

//const修饰成员函数
//常函数和常对象
class Person
{
    public:
    //this指针的本质：指针常量，指向不可以修改
    //常函数：保证函数体内不会修改成员属性
    //const Person * const this; //指针常量
    //在成员函数后加const，修饰this指针指向，让this指针指向的值也不可以修改
    void showPerson() const
    {
        this -> m_Score = 100; //可以修改
        //this -> m_Age = 100; //报错，常函数不可以修改成员属性
        //this = NULL; //报错，this指针不可以修改指向
    }

    void func()
    {
        m_Age=29;
    }//非常成员函数

    int m_Age;
    mutable int m_Score; //mutable修饰成员属性，可以被常函数修改
};

void test01()
{
    Person p;
    p.m_Age = 18;
    p.showPerson();
    cout << "age = " << p.m_Age << endl; //age = 18
    cout << "score = " << p.m_Score << endl; //score = 100
}

void test02()
{
    const Person p; //在对象前加const变为常对象
    //p.m_Age = 18; //报错，常对象不可以修改成员属性
    p.m_Score = 100; //可以修改
    
    p.showPerson(); //常对象只能调用常函数
    //p.func(); //报错，常对象不可以调用非常函数
}
int main()
{
    test01();
    return 0;
}






//常函数
//作用：保证函数体内不会修改成员属性
//语法：返回值类型 函数名() const{}
//成员属性声明时加mutable关键字，常函数依然可以修改

//常对象 
//作用：保证常对象只能调用常函数
//语法：const 类名 对象名
