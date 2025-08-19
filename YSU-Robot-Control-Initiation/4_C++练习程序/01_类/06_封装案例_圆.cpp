#include <iostream>
#include <string>
using namespace std;

//点和圆关系
//点类
class Point
{
    public:
    //设置点的坐标
    void setPoint(int x, int y) {m_X = x; m_Y = y;}
    //获取点的x坐标
    int getX() { return m_X;}
    //获取点的y坐标
    int getY() { return m_Y;}

    private:
    int m_X; //x坐标
    int m_Y; //y坐标
};
//圆类
class Circle
{
    public:
    //设置圆心坐标
    void setCenter(Point center) {m_Center = center;}
    //获取圆心
    Point getCenter() { return m_Center;}
    //设置半径
    void setRadius(int radius) {m_Radius = radius;}
    //获取半径
    int getRadius() { return m_Radius;}

    private: 
    Point m_Center; //圆心
    int m_Radius;   //半径
};

//判断点与圆位置关系
void isPointInCircle(Point &p, Circle &c)
{
    //计算两点之间的距离平方
    int distanceSquared =
                       (c.getCenter().getX()-p.getX())*(c.getCenter().getX()-p.getX())+
                       (c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY());
    //计算半径的平方
    int radiusSquared = c.getRadius() *c.getRadius();
   
    //判断点与圆的关系
    if(distanceSquared == radiusSquared)
    {
        cout << "点在圆上" << endl;
    }
    else if(distanceSquared < radiusSquared)
    {
        cout << "点在圆内" << endl;
    }
    else
    {
        cout << "点在圆外" << endl;
    }

}

int main()
{
    Circle c; //创建圆对象
    c.setRadius(10); //设置半径
    Point center;  //创建圆心点对象
    center.setPoint(10,0); //设置圆心坐标
    c.setCenter(center); //设置圆心

    Point p; //创建点对象
    p.setPoint(10,11); //设置点坐标

    //判断点与圆的关系
    isPointInCircle(p,c);

    return 0;
}