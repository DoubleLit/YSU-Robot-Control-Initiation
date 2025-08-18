#include <iostream>
using namespace std;


//设计一个学生类，属性有学生姓名和学号
//可以给学号和姓名赋值，可以显示学生姓名和学号

//设计学生类
class Student {

    //访问权限
    //公共权限
    //公共权限可以被类的外部访问
    //私有权限只能被类的内部访问
    //保护权限可以被类的子类访问
    public:

    //类中的属性和行为统一称为成员
    //属性     成员属性 成员变量
    //行为     成员函数




    //属性
    //学生姓名      
    //m_Name是学生类的一个属性
    //成员变量是类的属性        
    string m_Name;
    //学号      
    string m_Id;

    //行为
    //设置学生姓名和学号

    //setInfo函数有两个参数，分别是学生姓名和学号    
    //setInfo是一个成员函数
    //成员函数是类的行为        
    //给姓名赋值
    void setName(string name)
    {
        m_Name = name;
    }

    //给学号赋值
    void setId(string id)
    {
        m_Id = id;
    }

    //显示学生姓名和学号
    void showInfo() {

        cout<<"学生姓名：" << m_Name << ", 学号：" << m_Id << endl;
    }

};

int main() {

    //创建一个学生对象，实例化对象
    Student s1;
    //通过对象s1调用setInfo函数，给学生姓名和学号赋值
    //s1是Student类的一个对象
    s1.setName("张三");
    s1.setId("20230001");   
    //通过对象s1调用showInfo函数，显示学生姓名和学号
    //显示学生信息
    s1.showInfo();
     //通过对象s1调用setInfo函数，给学生姓名和学号赋值
    
     Student s2;
    //给学生s2的姓名和学号赋值
    s2.setName("李四");
    s2.setId("20230002");
    //显示学生s2的信息
    s2.showInfo();  


    return 0;
}