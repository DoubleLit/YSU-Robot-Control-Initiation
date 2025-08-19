#include<iostream>
using namespace std;

//拷贝构造函数调用时机

// 1.使用一个已经创建完毕的对象来初始化一个新对象

//2.值传递的方式给函数参数传值

//3.值方式返回局部对象

class Person
{
    public:

    Person()//默认构造函数
    {
        cout << "Person默认构造函数" << endl;
    }


    Person(int age)//有参构造函数
    {
        m_Age = age; 
        cout << "Person有参构造函数" << endl;
    }

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

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(20);//调用有参构造函数
    Person p2(p1);//调用拷贝构造函数
    cout << "p2的年龄：" << p2.m_Age << endl;
    //输出：
}


//2.值传递的方式给函数参数传值

void doWork1(Person p)//值传递方式
{
    p.m_Age=1000;//修改p的年龄
    cout << "doWork函数中p的年龄：" << p.m_Age << endl;
}

void test02()
{
    Person p;//调用默认构造函数
    doWork1(p);//调用拷贝构造函数
    //输出：   
    cout << "test02函数中p的年龄：" << p.m_Age << endl;
}
    //输出：
    //Person默认构造函数
    //Person拷贝构造函数    
    //Person析构函数
    //Person析构函数 
    //test02函数中p的年龄：0

    //因为在doWork1函数中，p是一个局部变量，修改p的年龄不会影响到test02函数中的p
    //doWork1函数结束后，p的生命周期结束，调用析构函数


//3.值方式返回局部对象
Person doWork2()//引用传递方式
{
    Person p1;//调用默认构造函数
    cout<<(int*)&p1<<endl;//输出p1的地址
    return p1;//返回局部对象
    //返回局部对象时，编译器会自动调用拷贝构造函数，将局部对象p1拷贝到返回值中
    //如果返回值是一个对象，则会调用拷贝构造函数
    //如果返回值是一个指针，则不会调用拷贝构造函数
    //如果返回值是一个引用，则不会调用拷贝构造函数  


}

void test03() 
{
    Person p = doWork2(); 
    cout<<(int*)&p<<endl;//输出p的地址
}

int main()
{
    //test01();
    //输出：
    //Person有参构造函数
    //Person拷贝构造函数
    //p2的年龄：20
    //Person析构函数
    //Person析构函数

    //test02();
    //输出：    
    //Person默认构造函数
    //Person拷贝构造函数    
    //Person析构函数
    //Person析构函数 
    //test02函数中p的年龄：0
    test03();
    //输出：    
    //Person默认构造函数
    //0x61fe14
    //Person拷贝构造函数    
    //0x61fe14
    //Person析构函数
    //Person析构函数


    return 0;
}