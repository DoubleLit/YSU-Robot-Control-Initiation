#include<iostream>
using namespace std;
#include<string>

//静态成员就是在类中声明为static的成员变量或成员函数
//静态成员分为静态成员变量和静态成员函数

//静态成员变量
class Person
{
    public:
    //1.所有对象共享同一份数据
    //2.在编译阶段就分配内存
    //3.在类外进行初始化，在类内声明

    static int m_Age; // 声明静态成员变量

    private:
    static int m_Salary; // 声明静态成员变量（私有）
};

int Person::m_Age = 100; // 在类外进行初始化
int Person::m_Salary = 5000; // 在类外进行初始化（私有静态成员变量）
// 静态成员变量需要在类外进行初始化


void test01()
{

    Person p;//100
    cout<< "Person的年龄: " << p.m_Age << endl; // 访问静态成员变量

    Person p2; // 创建另一个对象
    p2.m_Age = 200; // 修改静态成员变量
    cout << "Person的年龄: " << p2.m_Age << endl; // 访问静态成员变量
    cout<< "Person的年龄: " << p.m_Age << endl; // 访问静态成员变量  //输出为200



}

void test02()
{
    //静态成员变量，不属于某个对象上，所有对象共享同一份数据
    //因此静态成员变量有两种访问方式

    //1.通过类名访问静态成员变量
    cout << "Person的年龄: " << Person::m_Age << endl;
    //cout << "Person的薪资: " << Person::m_Salary << endl;// 不可访问静态成员变量（私有）

    // //2.通过对象访问静态成员变量
    // Person p;
    // cout << "Person的年龄: " << p.m_Age << endl;

}
int main()
{

    test02();
    return 0;
}
