#include<iostream>
using namespace std;

//深拷贝与浅拷贝

class Person
{
    public:

    Person()//默认构造函数
    {
        cout << "Person默认构造函数" << endl;
    }

        Person(int age ,int height)//有参构造函数
    {
        m_Age = age; 
        m_Height = new int(height); // 假设有一个指针成员变量
        // 在有参构造函数中分配内存
        // 注意：这里需要分配内存，防止浅拷贝时出现问题
        cout << "Person有参构造函数" << endl;
    }


    //自己实现拷贝构造函数 解决浅拷贝的问题
    Person(const Person &p)//拷贝构造函数
    {
        m_Age = p.m_Age;
        // 深拷贝：为指针成员变量分配新的内存空间
        m_Height = new int(*(p.m_Height)); // 深拷贝，分配新的内存空间并复制值
        cout << "Person拷贝构造函数" << endl;
    }

    //析构函数
    ~Person()//析构函数
    {
        if(m_Height != nullptr) {
            delete m_Height; // 释放堆区开辟的指针成员变量的内存
            m_Height = nullptr; // 防止悬空指针
        }
        // 释放堆区开辟的指针成员变量的内存
        cout << "Person析构函数" << endl;
    }


    int m_Age;
    int *m_Height; // 假设有一个指针成员变量
};

void test01()
{
    Person p1(18,180);//调用有参构造函数
    cout << "p1的年龄：" << p1.m_Age << endl;
    cout << "p1的身高：" << *(p1.m_Height) << endl;

    Person p2(p1);//调用拷贝构造函数
    cout << "p2的年龄：" << p2.m_Age << endl;
    cout << "p2的身高：" << *(p2.m_Height) << endl;

}



int main()
{
    
    test01();

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




    return 0;
}

//总结：
//1.浅拷贝：简单的赋值拷贝操作
//2.深拷贝：在堆区重新申请空间，进行拷贝操作