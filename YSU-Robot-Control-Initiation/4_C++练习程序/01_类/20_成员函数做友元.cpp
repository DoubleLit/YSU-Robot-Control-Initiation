#include<iostream>
using namespace std;
#include<string>

class Building;
class GoodGay
{
    public:

    GoodGay();//成员函数
    void Visit();//让Visit可以访问Building中私有成员
    void Visit2();//让Visit2不可以访问Building中私有成员
    Building *building;
};

class Building
{
    //告诉编译器，类GoodGay下的visit成员函数作为本类的友元，可以访问私有成员
    friend void GoodGay::Visit();

    public:

    Building();

    public:

    string m_SittingRoom;

    private:

    string m_BedRoom;
};

//类外实现成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::Visit()
{
    cout << "Visit函数正在访问 ： " << building->m_SittingRoom << endl;
    cout << "Visit函数正在访问 ： " << building->m_BedRoom << endl;
}

void GoodGay::Visit2()
{
    cout << "Visit2函数正在访问 ： " << building->m_SittingRoom << endl;
    //cout << "Visit2函数正在访问 ： " << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay gg;
    gg.Visit();
    gg.Visit2();
}

int main()
{
    test01();
    return 0;
}

//总结：友元friend
//三种实现方式
//全局函数做友元
//类做友元
//成员函数做友元 