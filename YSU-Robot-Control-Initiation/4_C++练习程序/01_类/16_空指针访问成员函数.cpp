#include<iostream>
using namespace std;


//空指针访问成员函数

class Person
{
public:
    
    void showClassName()
    {
        cout << "This is Person class!" << endl;
    }

    void showPersonAge()
    {
      if(this == NULL) //空指针保护
        {
            return;
        }

        cout << "age = " << this -> m_Age << endl; //age = 18
    }

    int m_Age;
};

void test01()
{
    Person * p = NULL; //空指针
    p -> showClassName(); //可以调用成员函数
    p -> showPersonAge(); //报错：传入的this指针是NULL
}

int main()
{

    test01();
    return 0;
}


