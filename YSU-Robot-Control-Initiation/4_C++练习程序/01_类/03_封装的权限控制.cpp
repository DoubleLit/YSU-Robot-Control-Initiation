#include <iostream>
#include <string>
using namespace std;



class Person {

    //访问权限
    //公共权限
    //公共权限public      可以被类的外部访问
    //私有权限private     不可以被类的外部访问，只能被类的内部访问  子类不可访问父类的私有内容
    //保护权限protected   不可以被类的外部访问，可以被类的子类访问  子类可以访问父类的保护内容

    public:
    //公共权限
    string m_Name; //姓名

    protected:
    //私有权限
    string m_Car;//汽车

    private:
    //保护权限
    string m_Password; //银行卡密码

    public:
    void function() {
        m_Name = "张三"; //可以访问
        m_Car = "宝马"; //可以访问
        m_Password = "123456"; //可以访问  
    }
};

int main() {

    Person p1;

    p1.m_Name = "李四"; //可以访问
    //p1.m_Car = "奥迪"; //错误，不能访问protected成员
    //p1.m_Password = "654321"; //错误，不能访问private成员

    p1.function(); //可以访问，因为function是public成员函数

    return 0;
}

