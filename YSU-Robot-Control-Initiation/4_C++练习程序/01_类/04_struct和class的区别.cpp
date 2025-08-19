#include <iostream>
using namespace std;
#include <string>



class C1 
{
    int m_A; //默认权限为私有
};

struct C2 
{
    int m_A; //默认权限为公共
};

int main() 
{

    // C1的默认权限为私有，不能直接访问
    // C2的默认权限为公共，可以直接访问
    // 结构体的默认权限为公共，类的默认权限为私有
    // 这就是结构体和类的区别之一

    C1 c1;
    //c1.m_A = 10; //错误，C1的默认权限为私有，不能访问
    //cout << "C1 m_A: " << c1.m_A << endl;

    C2 c2;
    c2.m_A = 10; //正确，C2的默认权限为公共，可以访问

    cout << "C2 m_A: " << c2.m_A << endl;

    return 0;
}