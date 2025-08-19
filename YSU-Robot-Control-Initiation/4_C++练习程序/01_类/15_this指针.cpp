#include<iostream>
using namespace std;
#include<string>

class Person
{
public:

    Person(int age)
    {
        //this指针：指向被调用的成员函数所属的对象
        this -> age = age;
    }

    Person& PersonAddAge(Person & p)//若返回的不是引用，而返回的是值，则创建了临时新对象
    {
        this -> age += p.age;
        return *this; //this指向p2的指针，而*this指向p2对象本身
    }

    int age;
};

//解决命名冲突
void test01()
{
    Person p1(18);
    cout << "p1 's age = " << p1.age << endl; //age = 乱码
}

//返回对象本身用return *this
void test02()
{
    Person p1(18);
    Person p2(12);
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1); //12 + 18 + 18 + 18  //链式编程
    cout << "p2 's age = " << p2.age << endl; //age = 66
}
int main()
{

    test02();
    return 0;
}



//this指针：指向被调用的成员函数所属的对象

//1.隐含每个非静态成员函数内的指针
//2.无需定义，直接使用即可

//用途：
//1.形参与成员变量同名时，解决名称冲突
//2.在类的非静态成员函数中返回对象本身，可以使用ruturn *this;
