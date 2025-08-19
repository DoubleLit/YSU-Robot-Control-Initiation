#include<iostream>
using namespace std;
#include<string>

class Building
{
    //全局函数goodGay是Building的友元，可以访问Building中的私有成员
    friend void goodGay(Building * building);

    public:

    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

    public:
    string m_SittingRoom;

    private:
    string m_BedRoom;
};

void goodGay(Building * building)//全局函数
{
    cout<<"好基友全局函数 正在访问 ："<< building -> m_SittingRoom << endl;
    cout<<"好基友全局函数 正在访问 ："<< building -> m_BedRoom << endl;//报错，私有属性在类外无法访问
}

void test01()
{
    Building building;
    goodGay(&building);
}

int main()
{
    test01();
    return 0;
}