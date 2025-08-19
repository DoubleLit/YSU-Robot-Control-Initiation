#include <iostream>
#include <string>
using namespace std;

//立方体类设计
//1.创建立方体类
//2.属性：长、宽、高
//3.行为：计算面积和体积  
//分别利用全局函数和成员函数实现 判断两个立方体是否相等

class cube 
{
    public:
    //设置长
    void setLen(int len) {m_Len = len;}
    //获取长 
    int getLen() { return m_Len;}
    //设置宽
    void setWid(int wid) {m_Wid = wid;}
    //获取宽    
    int getWid() { return m_Wid;}
    //设置高
    void setHei(int hei) {m_Hei = hei;}
    //获取高
    int getHei() { return m_Hei;}
    //获取立方体面积
    int calculateS() { return m_Hei*m_Len*2+m_Hei*m_Wid*2+m_Wid*m_Len*2;}
    //获取立方体体积
    int calculateV() { return m_Hei*m_Len*m_Len;}

    //利用成员函数实现 判断两个立方体是否相等
    bool isEqualbyclass(cube &c)
    {
        if(m_Len == c.getLen() && m_Wid == c.getWid() && m_Hei == c.getHei())
        {
            return true; //相等
        }
        return false; //不相等
    }

    private:
    int m_Len; //长
    int m_Wid; //宽 
    int m_Hei; //高 


};

//利用全局函数实现 判断两个立方体是否相等
bool isEqual(cube &c1, cube &c2)
{
    if (c1.getLen() == c2.getLen() && c1.getWid() == c2.getWid() && c1.getHei() == c2.getHei())
    {
        return true; //相等
    }
    return false; //不相等
}

int main()
{
    cube c1;
    c1.setLen(3);
    c1.setWid(3);
    c1.setHei(3);
    cout << "立方体面积：" << c1.calculateS() << endl;
    cout << "立方体体积：" << c1.calculateV() << endl;

    cube c2;
    c2.setLen(3);
    c2.setWid(3);
    c2.setHei(3);   
    cout << "立方体面积：" << c2.calculateS() << endl;
    cout << "立方体体积：" << c2.calculateV() << endl;  

    //全局函数判断
    isEqual(c1, c2) ? cout << "全局函数判断：c1和c2相等" << endl : cout << "全局函数判断：c1和c2不相等" << endl;
    //成员函数判断
    c1.isEqualbyclass(c2) ? cout << "成员函数判断：c1和c2相等" << endl : cout << "成员函数判断：c1和c2不相等" << endl;

    return 0;
}