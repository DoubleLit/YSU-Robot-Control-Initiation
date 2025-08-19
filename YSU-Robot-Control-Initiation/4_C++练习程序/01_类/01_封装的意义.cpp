#include <iostream>
#include <string>
using namespace std;

//圆周率
const double PI=3.14;

//设计一个圆类，求圆的周长

class Circle {

    //访问权限
    //公共权限
public:

    //属性
    //半径
    int m_r;

    //行为
    //获取圆的周长
    double calculateZC() 
    {

        return 2*PI*m_r;

    }
};

int main() {

    //通过圆类创建一个圆的对象
    //实例化
    //对象名为c1
    //Circle是类名  
    //c1是对象名
    //类是一个抽象的概念，只有通过类创建对象，才能使用  
    Circle c1;

    //给圆的半径赋值
    //m_r是Circle类的一个属性   
    //c1是Circle类的一个对象
    //通过对象来访问类的属性        
    c1.m_r = 10;

    //输出圆的周长  calculateZC()是一个成员函数
    //调用成员函数时，必须通过对象来调用        
    //c1.calculateZC()是调用Circle类的calculateZC()函数
    //calculateZC()函数返回一个double类型的值
    //cout是C++的输出流对象，用于输出信息到控制台       
    cout << "圆的周长是：" << c1.calculateZC() << endl;

}