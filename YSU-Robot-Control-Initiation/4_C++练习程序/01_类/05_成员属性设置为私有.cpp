#include <iostream>
#include <string>
using namespace std;

//成员属性设置私有
//1.可以自己控制读写权限
//2.对于写可以检测数据有效性

//人类
class Peron
{
    public:
    void setName(string name) { m_Name = name; } //设置姓名
    string getName() { return m_Name; } //获取姓名
    int getAge() const { return m_Age; } //获取年龄
    void setAge(int age) //设置年龄
    { 
        if (age < 0 || age > 150)
        {
            cout << "年龄输入有误！" << endl;
            return;
        }
        m_Age = age; 
    }

    void setIdol(string idol) { m_Idol = idol; } //设置偶像

    private:

    string m_Name; //姓名       权限：可读可写
    int m_Age = 18; //年龄      权限：只读   年龄设置在0-150之间
    string m_Idol; //偶像       权限：只写 
};

int main()
{
    Peron p;
    //姓名设置
    p.setName("张三");
    cout << "姓名：" << p.getName() << endl;
    p.setAge(200); //错误，年龄输入有误
    //年龄获取
    cout << "年龄：" << p.getAge() << endl;
    //偶像设置
    p.setIdol("蔡徐坤");
    //cout << "偶像：" << p.getIdol() << endl; //错误，m_Idol是私有属性


    //p.m_Name = "张三"; //错误，m_Name是私有属性
    //cout << p.m_Age; //错误，m_Age是私有属性
    //p.m_Idol = "李四"; //错误，m_Idol是私有属性

    return 0;
}