#include<iostream>
using namespace std;
#include<string>

//类对象作为类成员
class Phone
{
    public:
    //手机品牌
    string m_Brand;
    //手机价格
    double m_Price;

    Phone(string brand, double price) : m_Brand(brand), m_Price(price) // 使用初始化列表
    {
            cout<< "Phone类构造函数调用" << endl; // 输出提示信息
    }

    ~Phone() // 析构函数
    {
        cout << "Phone类析构函数调用" << endl; // 输出提示信息
    }
};

class Person//人类
{
    public:

    Person(string name,Phone phone) : m_Name(name), m_Phone(phone) // 使用初始化列表
    {
            cout<< "Person类构造函数调用" << endl; // 输出提示信息
    }

    //姓名
    string m_Name;
    //手机
    Phone m_Phone; // 假设有一个Phone类作为成员变量

    ~Person() // 析构函数
    {
        cout << "Person类析构函数调用" << endl; // 输出提示信息
    }

};
//当其他类对象作为本类成员时，构造时先构造类对象，再构造自身(析构函数与构造函数顺序相反)

void test01()
{
    Phone phone("Apple", 999.99); // 创建Phone对象
    Person p("Alice", phone); // 调用有参构造函数

    cout << "姓名: " << p.m_Name << " 持有" << endl;
    cout << "手机品牌: " << p.m_Phone.m_Brand << endl;
    cout << "手机价格: $" << p.m_Phone.m_Price << endl;
}

int main()
{
    test01();
    return 0;
}
//输出：
// Phone类构造函数调用
// Person类构造函数调用
// 姓名: Alice 持有
// 手机品牌: Apple
// 手机价格: $999.99